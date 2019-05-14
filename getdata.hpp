#ifndef GETDATA
#define GETDATA

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <unordered_map>

using namespace std;
unordered_map<string, vector<unsigned long> > getdata(string path);

#endif