#include <iostream>
#include <vector>
#include "pollution.h"

using namespace std;

Pollution::Pollution() {

    rows = 0;
    cols = 0;
    polInitialized = false;
    polUpdated = false;
    

}

Pollution::Pollution(int numRows, int numCols) {
    rows = numRows;
    cols = numCols;
    polInitialized = false;
    polUpdated = false;
    
}

void Pollution::PrintPollutionMap(){
    for (int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << pollMap[i][j] << " ";
        }
        cout << endl;
    }
}

void Pollution::TotalPollution(){
    int sum = 0;
    for (int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            sum += pollMap[i][j];
        }
    }
    cout << "Total Pollution for simulation: " << sum << endl;
}

void Pollution::RegionPollution(int startRow, int startCol, int endRow, int endCol){
    if(startRow >= 0 && startRow < rows && startCol >= 0 && startCol < cols && endRow >= startRow && endCol >= startCol && endRow < rows && endCol < cols){
        int sum = 0;
        for (int i = startRow; i <= endRow; i++){
            for(int j = startCol; j <= endCol; j++){
                cout << pollMap[i][j] << " ";
                sum += pollMap[i][j];
            }
            cout << endl;
        }
        cout << "Total Region Pollution: " << sum << endl;
    }
    else{
        cout << "The region entered is invalid. Please try again." << endl;
    }
}

int Pollution::PollutionSpread(int currPollution, int currRow, int currCol){
    int maxPollution = currPollution;

    for (int x = currRow - 1; x <= currRow + 1; x++){
        for(int y = currCol - 1; y <= currCol + 1; y++){
            if (x != currRow && y != currCol && x >= 0 && y >= 0 && x < pollMap.size() && y < pollMap.at(x).size()){
                if(pollMap[x][y] > maxPollution)
                maxPollution = pollMap[x][y];
            }
        }
    }

    return maxPollution - 1;
}

void Pollution::Update(vector<vector<Grid *>> gridMap){
    polUpdated = true;

    if (!polInitialized){
        polInitialized = true;

        for (int i = 0; i < gridMap.size()-1; i++){
            vector<int> newRow(gridMap.at(i).size());
            pollMap.push_back(newRow);
        }
    }

    for (int x = 0; x < gridMap.size(); x++){
        for (int y = 0; y < gridMap.at(x).size(); y++){
            if (gridMap[x][y]->getLabel() == INDUSTRIAL){

                pollMap[x][y] = gridMap[x][y]->getPopulation();

            }
            else{
                pollMap[x][y] = 0;
            }
        }
    }

    while (polUpdated == true){
        polUpdated = false;

        for (int i = 0; i < pollMap.size(); i++){
            for (int j = 0; j < pollMap[i].size(); j++){
                int initial = pollMap[i][j];
                int num = PollutionSpread(pollMap[i][j], i, j);
                if (num > initial){
                    pollMap[i][j] = num;
                    polUpdated = true;
                }
            }
        }
    }


}