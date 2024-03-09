#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#pragma once

using namespace std;

class File_Reader {
public:
    vector<vector<char>> grid;
    //Roger i split your file into two so that this next part is as painless as possible. the file reader files need to basically become the overseer files of the whole project. 
    //not only should they open and read the inital files but they will also need to initialize and run the simulation while interacting with the the other sub functions. dont worry about
    //Elli's stuff i will take care of it. 
    // Function to read the region file
    void readConfigFile(const string& filename, string& regionFilename, int& maxTimeSteps, int& refreshRate);

    //Read the region csv file
    void readRegionFile(const std::string& filename);
};
