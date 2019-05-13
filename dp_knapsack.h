#ifndef DP_KNAPSACK
#define DP_KNAPSACK

#include <unordered_map>
#include <vector>

double dpknapsack(int const W,
                std::vector<int> const wt,
                std::vector<double> const val,
                int const n, 
                std::unordered_map<double, int> dic);

std::pair < double, std::vector<int> > resultknapsack(int const W,
                std::vector<int> const wt,
                std::vector<double> const val);

#endif