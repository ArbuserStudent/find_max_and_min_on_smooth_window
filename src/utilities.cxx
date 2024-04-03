#include "utilities.hxx"

//----------------------------------------------------------------------------------------------------------------
void createRandmoData(std::vector<double>& data)
{
    std::random_device device;
    std::mt19937_64 gen(device());
    std::uniform_real_distribution<> distribution(1.0, 10.0);

    for (auto& it : data)
        it = distribution(gen);
}