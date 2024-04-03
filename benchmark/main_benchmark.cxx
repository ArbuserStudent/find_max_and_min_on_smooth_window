#include <benchmark/benchmark.h>

#include "../src/utilities.hxx"
#include "../src/smooth_windows.hxx"

//----------------------------------------------------------------------------------------------------------------
static void BM_constantWindowLengthSmoothWindowUsePriorityQueeu(benchmark::State& state)
{
    size_t dataLength = state.range(0);
    size_t windowLength = 6;

    std::vector<double> data(dataLength);
    std::vector<double> historyMax(data.size() - windowLength + 1);
    std::vector<double> historyMin(data.size() - windowLength + 1);

    createRandmoData(data);

    for (auto it : state)
        smoothWindowUsePriorityQueeu(data, historyMax, historyMin, windowLength);
}

//----------------------------------------------------------------------------------------------------------------
static void BM_variableWindowLengthSmoothWindowUsePriorityQueeu(benchmark::State& state)
{
    size_t dataLength = 4096;
    size_t windowLength = state.range(0);

    std::vector<double> data(dataLength);
    std::vector<double> historyMax(data.size() - windowLength + 1);
    std::vector<double> historyMin(data.size() - windowLength + 1);

    createRandmoData(data);

    for (auto it : state)
        smoothWindowUsePriorityQueeu(data, historyMax, historyMin, windowLength);
}

//----------------------------------------------------------------------------------------------------------------
static void BM_constantWindowLengthSmoothWindowPrimitiveImplementation(benchmark::State& state)
{
    size_t dataLength = state.range(0);
    size_t windowLength = 6;

    std::vector<double> data(dataLength);
    std::vector<double> historyMax(data.size() - windowLength + 1);
    std::vector<double> historyMin(data.size() - windowLength + 1);

    createRandmoData(data);

    for (auto it : state)
        smoothWindowPrimitiveImplementation(data, historyMax, historyMin, windowLength);
}

//----------------------------------------------------------------------------------------------------------------
static void BM_variableWindowLengthSmoothWindowPrimitiveImplementation(benchmark::State& state)
{
    size_t dataLength = 4096;
    size_t windowLength = state.range(0);

    std::vector<double> data(dataLength);
    std::vector<double> historyMax(data.size() - windowLength + 1);
    std::vector<double> historyMin(data.size() - windowLength + 1);

    createRandmoData(data);

    for (auto it : state)
        smoothWindowPrimitiveImplementation(data, historyMax, historyMin, windowLength);
}

//-------------------------------------------------------------------------------------
BENCHMARK(BM_constantWindowLengthSmoothWindowUsePriorityQueeu)->Unit(benchmark::kMicrosecond)->RangeMultiplier(2)->Range(8, 8 << 12);

//-------------------------------------------------------------------------------------
BENCHMARK(BM_constantWindowLengthSmoothWindowPrimitiveImplementation)->Unit(benchmark::kMicrosecond)->RangeMultiplier(2)->Range(8, 8 << 12);

//-------------------------------------------------------------------------------------
BENCHMARK(BM_variableWindowLengthSmoothWindowUsePriorityQueeu)->Unit(benchmark::kMicrosecond)->RangeMultiplier(2)->Range(8, 8 << 4);

//-------------------------------------------------------------------------------------
BENCHMARK(BM_variableWindowLengthSmoothWindowPrimitiveImplementation)->Unit(benchmark::kMicrosecond)->RangeMultiplier(2)->Range(8, 8 << 4);

//-------------------------------------------------------------------------------------
BENCHMARK_MAIN();