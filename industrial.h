#include <iostream>
#include <vector>

using namespace std;

class Industrial {
    public:
        void oneAdjacentP();
        void zeroAdjacentOne();
        void twoAdjacent();
        void fourAdjacent();
    private:
        const int rows = 8;
        const int cols = 8;
        int availWorkers;
        vector<vector<char>> map;
        int checkNeighbors(int target, int r, int c);

};
