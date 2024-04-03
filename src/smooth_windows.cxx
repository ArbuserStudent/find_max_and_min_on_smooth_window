#include "smooth_windows.hxx"

//----------------------------------------------------------------------------------------------------------------
void smoothWindowUsePriorityQueeu(std::vector<double>& data, std::vector<double>& max, std::vector<double>& min, size_t  windowLength)
{
    auto first = data.begin();
    auto last = std::next(first, windowLength);
    auto maxPointer = max.begin();
    auto minpointer = min.begin();

    for (; last <= data.end(); ++first, ++last, ++maxPointer, ++minpointer)
    {
        std::priority_queue<double, std::vector<double>, std::greater<double> > min(first, last);
        *minpointer = min.top(); 
        
        std::priority_queue<double> max(first, last);
        *maxPointer = max.top();  
    }     
}


//----------------------------------------------------------------------------------------------------------------
void smoothWindowPrimitiveImplementation(std::vector<double>& data, std::vector<double>& max, std::vector<double>& min, size_t  windowLength)
{
    size_t median = std::lround(static_cast<double>(windowLength) / 2);
    double medianValue = 0.0;

    auto pointerMax = max.begin();
    auto pointerMin = min.begin();

    size_t shiftPoint = 0;
    for (; pointerMax != max.end(); ++pointerMax, ++pointerMin, ++shiftPoint, ++median)
    {
        medianValue = data[median - 1];

        auto firstMax = std::next(data.begin(), shiftPoint);
        auto lastMax = std::next(data.begin(), windowLength - 1 + shiftPoint);

        auto firstMin = std::next(data.begin(), shiftPoint);
        auto lastMin = std::next(data.begin(), windowLength - 1 + shiftPoint);

        // find max and min on window
        for (size_t n = 0; n < median - shiftPoint; ++n)
        {
            if (*firstMax > *lastMax)
                --lastMax;
            else
                ++firstMax;

            if (*firstMin < *lastMin)
                --lastMin;
            else
                ++firstMin;
        }

        double localMax = (*firstMax > *lastMax) ? *firstMax : *lastMax;
        double localMin = (*firstMin < *lastMin) ? *firstMin : *lastMin;

        *pointerMax = (localMax > medianValue) ? localMax : medianValue;
        *pointerMin = (localMin < medianValue) ? localMin : medianValue;
    }
}