#ifndef GETDATA
#define GETDATA

#include <boost/algorithm/string.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
unordered_map<string, vector<unsigned long>> getdata(string path);

#endif