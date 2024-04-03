#include <vector>
#include <queue>
#include <cmath>
#include <cstddef>

// Скользящее окно, использующее приоритетную очередь
void smoothWindowUsePriorityQueeu(std::vector<double>& data, std::vector<double>& max, std::vector<double>& min, size_t  windowLength);

// Скользящее окно, использующее примитивный поиск
void smoothWindowPrimitiveImplementation(std::vector<double>& data, std::vector<double>& max, std::vector<double>& min, size_t  windowLength);