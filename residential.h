#include "matrixBasics.h"

void printGrid(char matrix[rows][cols], int state, int workers);
MatrixStruct adjacentToPowerline(char matrix[rows][cols], int state, int workers);
MatrixStruct zeroAdjacentToOne(char matrix[rows][cols], int state, int workers);
MatrixStruct oneAdjacentToOne(char matrix[rows][cols], int state, int workers);
MatrixStruct twoAdjacentToTwo(char matrix[rows][cols], int state, int workers);
MatrixStruct threeAdjacentToThree(char matrix[rows][cols], int state, int workers);
MatrixStruct fourAdjacentToFour(char matrix[rows][cols], int state, int workers);
