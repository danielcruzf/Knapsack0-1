#ifndef DP_KNAPSACK
#define DP_KNAPSACK

#include <unordered_map>
#include <vector>

unsigned long dpknapsack(unsigned long const W,
                std::vector<unsigned long> const wt,
                std::vector<unsigned long> const val,
                unsigned long const n, 
                std::unordered_map<unsigned long, unsigned long> dic);

std::pair < unsigned long, std::vector<unsigned long> > resultknapsack(unsigned long const W,
                std::vector<unsigned long> const wt,
                std::vector<unsigned long> const val);

#endif