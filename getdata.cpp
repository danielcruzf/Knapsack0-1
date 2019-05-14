#include "getdata.hpp"

unordered_map<string, vector<unsigned long> > getdata(string path) {
    string line; 
    ifstream myfile;
    vector <string> v; //splits
    vector <unsigned long> wt;
    vector <unsigned long> val;
    vector <unsigned long> nw;
    unordered_map <string, vector<unsigned long> > data;
    myfile.open (path);

    if (myfile.is_open()) {
        getline(myfile, line);
        boost::split(v, line, [](char c){return c == ' ';});
        nw.push_back(stoi(v[0]));
        nw.push_back(stoi(v[1]));
        data["nW"] = nw;

        while ( getline(myfile,line) ) {
            boost::split(v, line, [](char c){return c == ' ';});
            val.push_back(stoi(v[0]));
            wt.push_back(stoi(v[1]));
        }
        myfile.close();
    } else {
      cout << "Unable to open file: " << path << endl; 
    }
    data["wt"] = wt;
    data["val"] = val;

  return data; 
} 