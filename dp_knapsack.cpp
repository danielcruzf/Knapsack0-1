#include "dp_knapsack.hpp"

std::unordered_map<unsigned long, unsigned long> dic;

unsigned long dpknapsack(unsigned long const W,
                         std::vector<unsigned long> const wt,
                         std::vector<unsigned long> const val,
                         unsigned long const n) {
  // recursive implementation of 0-1 Knapsack Problem
  // Returns the maximum value that can be put in a
  // knapsack of capacity W
  // and save data in a unordered map
  if (n == 0 or W == 0) {
    return 0;
  } else if (wt[n - 1] > W) {
    return dpknapsack(W, wt, val, n - 1);
  } else {
    unsigned long const a =
        val[n - 1] + dpknapsack(W - wt[n - 1], wt, val, n - 1);
    unsigned long const b = dpknapsack(W, wt, val, n - 1);

    if (a > b) {
      dic[a] = n - 1;
      return a;
    } else {
      return b;
    }
  }
}

std::pair<unsigned long, std::vector<unsigned long>>
resultknapsack(unsigned long const W, std::vector<unsigned long> const wt,
               std::vector<unsigned long> const val) {
  auto n = wt.size();
  auto best = dpknapsack(W, wt, val, n);
  // vector of items
  std::vector<unsigned long> result;
  auto v = best;
  while (v > 0) {
    auto i = dic[v];
    result.push_back(i);
    v -= val[i];
  }
  return std::make_pair(best, result);
}