#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "file_reader.h"


void File_Reader::readConfigFile(const string& filename, string& regionFilename, int& maxTimeSteps, int& refreshRate) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Cannot open file: " << filename << endl;
            return;
        }

        string line;
        if (getline(file, line)) {
            size_t pos = line.find(":");
            if (pos != string::npos) {
                regionFilename = line.substr(pos + 1);
            }
        }
        // Read the time limit
        if (getline(file, line)) {
            size_t pos = line.find(":");
            if (pos != string::npos) {
                maxTimeSteps = stoi(line.substr(pos + 1));
            }
        }
        // Read the refresh rate
        if (getline(file, line)) {
            size_t pos = line.find(":");
            if (pos != string::npos) {
                refreshRate = stoi(line.substr(pos + 1));
            }
        }
        file.close();
    }

void File_Reader::readRegionFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Cannot open file: " << filename << endl;
            return;
        }
        string line;
        while (getline(file, line)) {
            vector<char> row;
            stringstream ss(line);
            string value;
            while (getline(ss, value, ',')) {
                if (!value.empty()) {
                    row.push_back(value[0]);
                }
            }
            grid.push_back(row);
        }
        file.close();
    } 
