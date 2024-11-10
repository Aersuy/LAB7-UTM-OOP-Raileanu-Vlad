#pragma once
#include <vector>
template <typename T>
int countAcour(const std::vector<T>& vec, const T& param) {
    int count = 0;
    for (const auto& element : vec) {
        if (element == param) {
            count++;
        }
    }
    return count;
}