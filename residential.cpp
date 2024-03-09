#include "residential.h" //Import the header file

//This function displays the state number, workers, and grid to the console.
void printGrid(char matrix[rows][cols], int state, int workers)
{
    cout << "State: " << state << endl;
    cout << "Available Workers: " << workers << endl;

    for(int r = 0; r < rows; r++)
    {
        for(int c = 0; c < cols; c++)
        {
            cout << matrix[r][c] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

//This function does the following requirement: "If a cell has a population of 0 and is adjacent to a powerline in the
//current time step, that cell’s population will increase by 1 in the next time step."
MatrixStruct adjacentToPowerline(char matrix[rows][cols], int state, int workers)
{
    MatrixStruct var;
    bool running1 = true;
    int initialWorkers = workers;

    while(running1 == true) {
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (matrix[r][c] == residential) {
                    if (((matrix[r - 1][c] == powerline) and (r > 0)) or
                        ((matrix[r - 1][c + 1] == powerline) and (r > 0 and c < cols - 1)) or
                        ((matrix[r][c + 1] == powerline) and (c < cols - 1)) or
                        ((matrix[r + 1][c + 1] == powerline) and (r < rows - 1 and c < cols - 1)) or
                        ((matrix[r + 1][c] == powerline) and (r < rows - 1)) or
                        ((matrix[r + 1][c - 1] == powerline) and (r < rows - 1 and c > 0)) or
                        ((matrix[r][c - 1] == powerline) and (c > 0)) or
                        ((matrix[r - 1][c - 1] == powerline) and (r > 0 and c > 0)))
                    {
                        matrix[r][c] = one;
                        workers++;
                    }
                }
            }
        }
        running1 = false;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                var.matrix[i][j] = matrix[i][j];
            }
        }
        var.state = state;
        var.workers = workers;
    }
	return var;
}

//This function does the following requirement: "If a cell has a population of 0 and is adjacent to at least one cell
//with a population of at least 1, that cell’s population will increase by 1 in the next time step."
MatrixStruct zeroAdjacentToOne(char matrix[rows][cols], int state, int workers)
{
    MatrixStruct var;
    bool running2 = true;
    int initialWorkers = workers;

    while(running2 == true) {
        vector<int> onesR;
        vector<int> onesC;

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
                            if (matrix[r][c] == residential) {
                                if((r-1 == onesR.at(r2) and c == onesC.at(c2)) or
                                   (r-1 == onesR.at(r2) and c+1 == onesC.at(c2)) or
                                   (r-1 == onesR.at(r2) and c-1 == onesC.at(c2)) or
                                   (r == onesR.at(r2) and c+1 == onesC.at(c2)) or
                                   (r == onesR.at(r2) and c-1 == onesC.at(c2)) or
                                   (r+1 == onesR.at(r2) and c+1 == onesC.at(c2)) or
                                   (r+1 == onesR.at(r2) and c == onesC.at(c2)) or
                                   (r+1 == onesR.at(r2) and c-1 == onesC.at(c2)))
                                {
                                    matrix[r][c] = one;
                                    workers++;
                                }
                            }
                        }
                    }
                }
            }
        }
        running2 = false;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                var.matrix[i][j] = matrix[i][j];
            }
        }
        var.state = state;
        var.workers = workers;
    }
	return var;
}

//This function does the following requirement: "If a cell has a population of 1 and is adjacent to at least two cells
//with a population of at least 1, that cell’s population will increase by 1 in the next time step."
MatrixStruct oneAdjacentToOne(char matrix[rows][cols], int state, int workers)
{
    MatrixStruct var;
    bool running3 = true;
    int initialWorkers = workers;

    while(running3 == true) {
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
                            if (matrix[r][c] == one) {
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

                                if(onesCounter > 2)
                                {
                                    matrix[r][c] = two;
                                    workers++;
                                }
                            }
                        }
                        onesCounter = 0;
                    }
                }
            }
        }
        running3 = false;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                var.matrix[i][j] = matrix[i][j];
            }
        }
        var.state = state;
        var.workers = workers;
    }
	return var;
}

//This function does the following requirement: "If a cell has a population of 2 and is adjacent to at least four cells
//with a population of at least 2, that cell’s population will increase by 1 in the next time step."
MatrixStruct twoAdjacentToTwo(char matrix[rows][cols], int state, int workers)
{
    MatrixStruct var;
    bool running4 = true;
    int initialWorkers = workers;

    while(running4 == true) {
        vector<int> twosR;
        vector<int> twosC;
        int twosCounter = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (atLeastBlank(matrix[r][c], two) == true) {
                    twosR.push_back(r);
                    twosC.push_back(c);
                }
            }
        }

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (twosR.empty() == false and twosC.empty() == false) {
                    for (int r2 = 0; r2 < twosR.size(); r2++) {
                        for (int c2 = 0; c2 < twosC.size(); c2++) {
                            if (matrix[r][c] == two) {
                                if((r-1 == twosR.at(r2) and c == twosC.at(c2)))
                                {
                                    twosCounter++;
                                }
                                if((r-1 == twosR.at(r2) and c+1 == twosC.at(c2)))
                                {
                                    twosCounter++;
                                }
                                if((r-1 == twosR.at(r2) and c-1 == twosC.at(c2)))
                                {
                                    twosCounter++;
                                }
                                if((r == twosR.at(r2) and c+1 == twosC.at(c2)))
                                {
                                    twosCounter++;
                                }
                                if((r == twosR.at(r2) and c-1 == twosC.at(c2)))
                                {
                                    twosCounter++;
                                }
                                if((r+1 == twosR.at(r2) and c+1 == twosC.at(c2)))
                                {
                                    twosCounter++;
                                }
                                if((r+1 == twosR.at(r2) and c == twosC.at(c2)))
                                {
                                    twosCounter++;
                                }
                                if((r+1 == twosR.at(r2) and c-1 == twosC.at(c2)))
                                {
                                    twosCounter++;
                                }

                                if(twosCounter >= 4)
                                {
                                    matrix[r][c] = three;
                                    workers++;
                                }
                            }
                        }
                        twosCounter = 0;
                    }
                }
            }
        }
        running4 = false;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                var.matrix[i][j] = matrix[i][j];
            }
        }
        var.state = state;
        var.workers = workers;
    }
	return var;
}

//This function does the following requirement: "If a cell has a population of 3 and is adjacent to at least six cells
//with a population of at least 3, that cell’s population will increase by 1 in the next time step."
MatrixStruct threeAdjacentToThree(char matrix[rows][cols], int state, int workers)
{
    MatrixStruct var;
    bool running5 = true;

    while(running5 == true) {
        vector<int> threesR;
        vector<int> threesC;
        int threesCounter = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (atLeastBlank(matrix[r][c], three) == true) {
                    threesR.push_back(r);
                    threesC.push_back(c);
                }
            }
        }

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (threesR.empty() == false and threesC.empty() == false) {
                    for (int r2 = 0; r2 < threesR.size(); r2++) {
                        for (int c2 = 0; c2 < threesC.size(); c2++) {
                            if (matrix[r][c] == three) {
                                if((r-1 == threesR.at(r2) and c == threesC.at(c2)))
                                {
                                    threesCounter++;
                                }
                                if((r-1 == threesR.at(r2) and c+1 == threesC.at(c2)))
                                {
                                    threesCounter++;
                                }
                                if((r-1 == threesR.at(r2) and c-1 == threesC.at(c2)))
                                {
                                    threesCounter++;
                                }
                                if((r == threesR.at(r2) and c+1 == threesC.at(c2)))
                                {
                                    threesCounter++;
                                }
                                if((r == threesR.at(r2) and c-1 == threesC.at(c2)))
                                {
                                    threesCounter++;
                                }
                                if((r+1 == threesR.at(r2) and c+1 == threesC.at(c2)))
                                {
                                    threesCounter++;
                                }
                                if((r+1 == threesR.at(r2) and c == threesC.at(c2)))
                                {
                                    threesCounter++;
                                }
                                if((r+1 == threesR.at(r2) and c-1 == threesC.at(c2)))
                                {
                                    threesCounter++;
                                }

                                if(threesCounter >= 6)
                                {
                                    matrix[r][c] = four;
                                    workers++;
                                }
                            }
                        }
                        threesCounter = 0;
                    }
                }
            }
        }
        //state++;
        running5 = false;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                var.matrix[i][j] = matrix[i][j];
            }
        }
        var.state = state;
        var.workers = workers;
    }
	return var;
}

//This function does the following requirement: "If a cell has a population of 4 and is adjacent to at least eight cells
//with a population of at least 4, that cell’s population will increase by 1 in the next time step."
MatrixStruct fourAdjacentToFour(char matrix[rows][cols], int state, int workers)
{
    MatrixStruct var;
    bool running6 = true;

    while(running6 == true) {
        vector<int> foursR;
        vector<int> foursC;
        int foursCounter = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (atLeastBlank(matrix[r][c], four) == true) {
                    foursR.push_back(r);
                    foursC.push_back(c);
                }
            }
        }

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (foursR.empty() == false and foursC.empty() == false) {
                    for (int r2 = 0; r2 < foursR.size(); r2++) {
                        for (int c2 = 0; c2 < foursC.size(); c2++) {
                            if (matrix[r][c] == four) {
                                if((r-1 == foursR.at(r2) and c == foursC.at(c2)))
                                {
                                    foursCounter++;
                                }
                                if((r-1 == foursR.at(r2) and c+1 == foursC.at(c2)))
                                {
                                    foursCounter++;
                                }
                                if((r-1 == foursR.at(r2) and c-1 == foursC.at(c2)))
                                {
                                    foursCounter++;
                                }
                                if((r == foursR.at(r2) and c+1 == foursC.at(c2)))
                                {
                                    foursCounter++;
                                }
                                if((r == foursR.at(r2) and c-1 == foursC.at(c2)))
                                {
                                    foursCounter++;
                                }
                                if((r+1 == foursR.at(r2) and c+1 == foursC.at(c2)))
                                {
                                    foursCounter++;
                                }
                                if((r+1 == foursR.at(r2) and c == foursC.at(c2)))
                                {
                                    foursCounter++;
                                }
                                if((r+1 == foursR.at(r2) and c-1 == foursC.at(c2)))
                                {
                                    foursCounter++;
                                }

                                if(foursCounter >= 8)
                                {
                                    matrix[r][c] = five;
                                    workers++;
                                }
                            }
                        }
                        foursCounter = 0;
                    }
                }
            }
        }
        //state++;
        running6 = false;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                var.matrix[i][j] = matrix[i][j];
            }
        }
        var.state = state;
        var.workers = workers;
    }
	return var;
}

int main()
{
    MatrixStruct var;
    
    char sampleMatrix[rows][cols] = {{' ', ' ', 'T', '#', 'T', 'T', 'T', ' '},
                                     {'I', 'I', 'I', '-', 'C', 'C', 'T', ' '},
                                     {'I', 'I', 'I', '-', 'C', 'C', 'T', 'P'},
                                     {'I', 'I', 'I', '-', 'C', 'C', 'T', ' '},
                                     {'-', '-', '-', '-', '-', '-', '#', '-'},
                                     {' ', ' ', '-', 'R', 'R', 'R', 'T', ' '},
                                     {' ', ' ', '-', 'R', 'R', 'R', ' ', ' '},
                                     {' ', ' ', '-', 'R', 'R', 'R', ' ', ' '}
    };

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            var.matrix[i][j] = sampleMatrix[i][j];
        }
    }
    var.state = state;
    var.workers = workers;

    printGrid(var.matrix, var.state, var.workers); //Initial state

    while(simRunning == true) {
        var = fourAdjacentToFour(var.matrix, var.state, var.workers);
        var = threeAdjacentToThree(var.matrix, var.state, var.workers);
        var = twoAdjacentToTwo(var.matrix, var.state, var.workers);
        var = oneAdjacentToOne(var.matrix, var.state, var.workers);
        var = zeroAdjacentToOne(var.matrix, var.state, var.workers);
        var = adjacentToPowerline(var.matrix, var.state, var.workers);
        var.state++;
        printGrid(var.matrix, var.state, var.workers);

        if(var.state >= 5)
        {
            simRunning = false;
        }
    }
    return 0;
}
