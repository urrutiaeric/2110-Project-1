#include<iostream>
#include "Grid.h"
#include "residential.h"

class Commerical_Zone{
private:
    int availableWorkerNext = 0;
    int availableWorker = 0;
    int availableGoodNext = 0;
    int availableGood = 0;
    int goodListCounter = 0;

public:
    MatrixStruct adjacentToPowerline(char matrix[rows][cols], int state, int workers, int goods);
    MatrixStruct zeroAdjacentToOne(char matrix[rows][cols], int state, int workers, int goods);
};
