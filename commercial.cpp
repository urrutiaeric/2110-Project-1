#include "commercial.h"
MatrixStruct adjacentToPowerline(char matrix[rows][cols], int state, int workers, int goods)
{
    MatrixStruct var;
    bool running = true;

    while(running == true) {
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (matrix[r][c] == commercial) {
                    if (((matrix[r - 1][c] == powerline) and (r > 0)) or
                        ((matrix[r - 1][c + 1] == powerline) and (r > 0 and c < cols - 1)) or
                        ((matrix[r][c + 1] == powerline) and (c < cols - 1)) or
                        ((matrix[r + 1][c + 1] == powerline) and (r < rows - 1 and c < cols - 1)) or
                        ((matrix[r + 1][c] == powerline) and (r < rows - 1)) or
                        ((matrix[r + 1][c - 1] == powerline) and (r < rows - 1 and c > 0)) or
                        ((matrix[r][c - 1] == powerline) and (c > 0)) or
                        ((matrix[r - 1][c - 1] == powerline) and (r > 0 and c > 0)))
                    {
                        if(workers >= 1 && goods >= 1)
                        {
                            matrix[r][c] = one;
                            workers -= workers;
                            goods -= goods;
                        }
                    }
                }
            }
        }
        running = false;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                var.matrix[i][j] = matrix[i][j];
            }
        }
        var.state = state;
        var.workers = workers;
        var.goods = goods;
    }
	return var;
}

MatrixStruct zeroAdjacentToOne(char matrix[rows][cols], int state, int workers, int goods)
{
    MatrixStruct var;
    bool running = true;

    while(running == true) {
        vector<int> onesR;
        vector<int> onesC;
        int onesCounter = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (atLeastBlank(matrix[r][c], one) == true) {
                    onesR.push_back(r);
                    onesC.push_back(c);
                }
            }
        }

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (onesR.empty() == false and onesC.empty() == false) {
                    for (int r2 = 0; r2 < onesR.size(); r2++) {
                        for (int c2 = 0; c2 < onesC.size(); c2++) {
                            if (matrix[r][c] == commercial) {
                                if((r-1 == onesR.at(r2) and c == onesC.at(c2)))
                                {
                                    onesCounter++;
                                }
                                if((r-1 == onesR.at(r2) and c+1 == onesC.at(c2)))
                                {
                                    onesCounter++;
                                }
                                if((r-1 == onesR.at(r2) and c-1 == onesC.at(c2)))
                                {
                                    onesCounter++;
                                }
                                if((r == onesR.at(r2) and c+1 == onesC.at(c2)))
                                {
                                    onesCounter++;
                                }
                                if((r == onesR.at(r2) and c-1 == onesC.at(c2)))
                                {
                                    onesCounter++;
                                }
                                if((r+1 == onesR.at(r2) and c+1 == onesC.at(c2)))
                                {
                                    onesCounter++;
                                }
                                if((r+1 == onesR.at(r2) and c == onesC.at(c2)))
                                {
                                    onesCounter++;
                                }
                                if((r+1 == onesR.at(r2) and c-1 == onesC.at(c2)))
                                {
                                    onesCounter++;
                                }

                                if(onesCounter >= 1 && workers >= 1 && goods >= 1)
                                {
                                    matrix[r][c] = one;
                                    workers -= workers;
                                    goods -= goods;
                                }
                            }
                        }
                        onesCounter = 0;
                    }
                }
            }
        }
        running = false;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                var.matrix[i][j] = matrix[i][j];
            }
        }
        var.state = state;
        var.workers = workers;
        var.goods = goods;
    }
	return var;
}
