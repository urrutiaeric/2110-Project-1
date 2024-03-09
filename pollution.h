#include <iostream>
#include <vector>
#include "Grid.h"

using namespace std;

class Pollution {
    private:

    vector<vector<int>> pollMap;
    int rows, cols;
    bool polInitialized, polUpdated;

    public:

    Pollution();

    Pollution(int numRows, int numCols);

    int GetRows(){
        return rows;
    }

    int GetCols(){
        return cols;
    }

    vector<vector<int>> GetPolMap() {
        return pollMap;
    }

    void SetRows(int newRows){
        rows = newRows;
    }

    void SetCols(int newCols){
        cols = newCols;
    }

    void SetPollMap(vector<vector<int>> newPollMap){
        pollMap = newPollMap;
    }

    void PrintPollutionMap();

    void TotalPollution();

    void RegionPollution(int startRow, int startCol, int endRow, int endCol);

    int PollutionSpread(int currPollution, int currRow, int currCol);

    void Update(vector<vector<Grid*>> gridMap);
};