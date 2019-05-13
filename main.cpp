#include "dp_knapsack.h"
#include <iostream>

int main() {
    int const W = 99;

    std::vector<double> const val = {66, 48, 94, 17, 46,  8, 39, 23,
                                     11, 13, 60, 11, 70, 74, 12, 54,
                                     25, 65, 23, 25, 24, 41, 46, 83,
                                     48};

    std::vector<int> const wt = {56, 68, 14, 36, 83, 33, 97, 40,
                                    91, 54, 19, 65, 59, 49, 62,  6,
                                     7, 67, 23, 36, 52, 70, 26, 25,
                                    48};

    auto res = resultknapsack(W, wt, val);
    std::cout << "valor total: " << res.first << std::endl;
    std::cout << "items: ";
    for (auto const & i : res.second) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}