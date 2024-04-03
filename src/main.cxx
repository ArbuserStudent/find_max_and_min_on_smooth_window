#include <iostream>
#include <queue>
#include <vector>
#include <iterator>

#include "smooth_windows.hxx"
#include "utilities.hxx"

int main()
{
    size_t dataLength  = 10;
    std::vector<double> data(dataLength);
    createRandmoData(data);

    size_t windiwLength = 5;

    {
        std::vector<double> historyMax(data.size() - windiwLength + 1);
        std::vector<double> historyMin(data.size()- windiwLength + 1);

        smoothWindowUsePriorityQueeu(data, historyMax, historyMin, windiwLength);
        std::cout << "history max: ";
        std::copy(historyMax.begin(), historyMax.end(), std::ostream_iterator<double>(std::cout, "  "));
        std::cout << std::endl;

        std::cout << "history min: ";
        std::copy(historyMin.begin(), historyMin.end(), std::ostream_iterator<double>(std::cout, "  "));
        std::cout << std::endl;
    }

    {
        std::vector<double> historyMax(data.size() - windiwLength + 1);
        std::vector<double> historyMin(data.size()- windiwLength + 1);
    
        smoothWindowPrimitiveImplementation(data, historyMax, historyMin, windiwLength);
        std::cout << "history max: ";
        std::copy(historyMax.begin(), historyMax.end(), std::ostream_iterator<double>(std::cout, "  "));
        std::cout << std::endl;
    
        std::cout << "history min: ";
        std::copy(historyMin.begin(), historyMin.end(), std::ostream_iterator<double>(std::cout, "  "));
        std::cout << std::endl;
    }
    
    return 0;
}