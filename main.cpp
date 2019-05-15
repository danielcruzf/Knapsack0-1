#include "dp_knapsack.hpp"
#include "getdata.hpp"
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv) {
  if (argc >= 2) {
    auto data = getdata(argv[1]);
    auto const n = data["nW"][0];
    auto const W = data["nW"][1];
    auto const wt = data["wt"];
    auto const val = data["val"];
    string comp;
    if (argc == 2) {
      auto const result = resultknapsack(W, wt, val);
      string bits(n, '0');
      cout << result.first << " " << 1 << endl;
      for (auto &&i : result.second) {
        bits[i] = '1';
      }
      for (auto &&bit : bits) {
        cout << bit << " ";
      }
      cout << endl;
    } else if (comp = "print"; comp.compare((string)argv[2]) == 0) {
      cout << "W = " << W << endl << "n = " << n << endl << "wt =";
      for (auto &&w : wt) {
        cout << " " << w;
      }
      cout << endl << "val = ";
      for (auto &&v : val) {
        cout << " " << v;
      }
      cout << endl;
    } else if (comp = "time"; comp.compare((string)argv[2]) == 0) {
      clock_t begin = clock();
      auto const result = resultknapsack(W, wt, val);
      clock_t end = clock();
      double sec = double(end - begin) / CLOCKS_PER_SEC;
      cout << "result: " << result.first << endl
           << "Execution time: " << sec << " seconds" << endl;
    } else {
      cout << "output [path] [time|print]" << endl;
    }
  } else {
    cout << "output [path] [time|print]" << endl;
  }
  return 0;
}