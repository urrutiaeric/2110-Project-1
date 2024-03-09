#include "file_reader.h"
#include "commercial.h"
#include "Goods.h"
#include "Grid.h"
#include "GridLabel.h"
#include "industrial.h"
#include "matrixBasics.h"
#include "pollution.h"
#include "residential.h"
#include <iostream>
using namespace std;

int main() {
    File_Reader reader;
    std::string configFilename, regionFilename;
    int maxTimeSteps, refreshRate;
    
    //Find the config1.txt file in the directory
    configFilename = "config1.txt";
    //Find the Region name to run on the simulatoin
    regionFilename = "SimMapEx1.txt";
    // Read the configuration file to get the region filename, max time steps, and refresh rate
    reader.readConfigFile(configFilename, regionFilename, maxTimeSteps, refreshRate);
    //Read the region file using the region filename obtained from the configuration file
    reader.readRegionFile(regionFilename);
    // Output the initial grid of the region
    for (const auto& row : reader.grid) {
        for (char cell : row) {
            std::cout << cell << " ";
        } 
        std::cout << std::endl;
    }

    




    return 0;    
}
