#include "dp_knapsack.h"

std::unordered_map<double, int> dic;

double dpknapsack(int const W,
                std::vector<int> const wt,
                std::vector<double> const val,
                int const n) {
    // recursive implementation of 0-1 Knapsack Problem
    // Returns the maximum value that can be put in a
    // knapsack of capacity W 
    // and save data in a unordered map
    if (n == 0 or W==0) {
        return 0;
    } else if (wt[n-1] > W) {
        return dpknapsack(W, wt, val, n-1);
    } else {
        double const a  = val[n-1] + dpknapsack(W-wt[n-1], wt, val, n-1);
        double const b = dpknapsack(W, wt, val, n-1);

        if (a > b) {
            dic[a] = n-1;
            return a;
        } else {
            return b;
        }
    }
}

std::pair < double, std::vector<int> > resultknapsack(
                                            int const W,
                                            std::vector<int> const wt,
                                            std::vector<double> const val) {
    auto n = wt.size();
    auto best = dpknapsack(W, wt, val, n);
    //vector of items
    std::vector<int> result;
    auto v = best;
    while (v > 0) {
        auto i = dic[v];
        result.push_back(i);
        v -= val[i];
    }
    return std::make_pair(best, result);
}