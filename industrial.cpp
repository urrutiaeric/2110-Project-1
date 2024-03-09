#include "industrial.h"

/* Note: Add if statements to the functions to make sure that the current grid cell is an industrial one
   and then change the r and c ranges so that they are based on the size of the grid, not just
   the industrial zone so that it can work for other region files. */

void Industrial::oneAdjacentP() {
    for (int r = 1; r < 4; r++) {
        for (int c = 0; c < 3; c++) {
            if (c == 0 && availWorkers >= 2)  {
                if (map[r-1][c] == 'T' || map[r-1][c+1] == 'T' || map[r][c+1] == 'T' || map[r+1][c+1] == 'T' || map[r+1][c] == 'T') {
                    int temp = static_cast<int>(map[r][c]);
                    map[r][c] = static_cast<char>(temp+1);
                    availWorkers = 0;
                }
            }
            else if (c != 0 && availWorkers >= 2) {
                if (map[r-1][c-1] == 'T' || map[r-1][c] == 'T' || map[r-1][c+1] == 'T' || map[r][c-1] == 'T' || map[r][c+1] == 'T' || map[r+1][c-1] == 'T' || map[r+1][c] == 'T' || map[r+1][c+1] == 'T') {
                    int temp = static_cast<int>(map[r][c]);
                    map[r][c] = static_cast<char>(temp+1);
                    availWorkers = 0;
                }
            }
        }
    }
}

void Industrial::zeroAdjacentOne() {
    for (int r = 1; r < 4; r++) {
        for (int c = 0; c < 3; c++) {
            if (c == 0 && availWorkers >= 2) {
                if (static_cast<int>(map[r-1][c]) >= 1 || static_cast<int>(map[r-1][c+1]) >= 1 || static_cast<int>(map[r][c+1]) >= 1 || static_cast<int>(map[r+1][c+1]) >= 1 || static_cast<int>(map[r+1][c]) >= 1) {
                    int temp = static_cast<int>(map[r][c]);
                    map[r][c] = static_cast<char>(temp+1);
                    availWorkers = 0;
                }
            }
            else if (c != 0 && availWorkers >= 2) {
                if (static_cast<int>(map[r-1][c]) >= 1 || static_cast<int>(map[r-1][c+1]) >= 1 || static_cast<int>(map[r][c+1]) >= 1 || static_cast<int>(map[r+1][c+1]) >= 1 || static_cast<int>(map[r+1][c]) >= 1 || static_cast<int>(map[r-1][c-1]) >= 1 || static_cast<int>(map[r][c-1]) >= 1 || static_cast<int>(map[r+1][c-1]) >= 1) {
                    int temp = static_cast<int>(map[r][c]);
                    map[r][c] = static_cast<char>(temp+1);
                    availWorkers = 0;
                }
            }
        }
    }
}

void Industrial::twoAdjacent() {
    for (int r = 1; r < 4; r++) {
        for (int c = 0; c < 3; c++) {
            if (static_cast<int>(map[r][c]) == 1 && Industrial::checkNeighbors(1, r, c) >= 2 && availWorkers >= 2) {
                int temp = static_cast<int>(map[r][c]);
                map[r][c] = static_cast<char>(temp+1);
                availWorkers = 0;
            }
        }
    }
}

void Industrial::fourAdjacent() {
    for (int r = 1; r < 4; r++) {
        for (int c = 0; c < 3; c++) {
            if (static_cast<int>(map[r][c]) == 2 && Industrial::checkNeighbors(2, r, c) >= 4 && availWorkers >= 2) {
                int temp = static_cast<int>(map[r][c]);
                map[r][c] = static_cast<char>(temp+1);
                availWorkers = 0;
            }
        }
    }
}

int Industrial::checkNeighbors(int target, int r, int c) {
    int totalNeighbors = 0;
    
    if (map[r-1][c] >= target)
        totalNeighbors++;
    if (map[r-1][c+1] >= target)
        totalNeighbors++;
    if (map[r][c+1] >= target)
        totalNeighbors++;
    if (map[r+1][c] >= target) 
        totalNeighbors++;
    if (map[r+1][c+1] >= target)
        totalNeighbors++;
    if (c != 0) {
        if (map[r-1][c-1] >= target)
            totalNeighbors++;
        if (map[r][c-1] >= target)
            totalNeighbors++;
        if (map[r+1][c-1] >= target)
            totalNeighbors++;
    }
        
    return totalNeighbors;
}
