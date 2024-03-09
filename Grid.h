#ifndef GRID_H
#define GRID_H

#include "GridLabel.h"
#include <vector>

class Grid {
    private:
        int row;
        int column;
        GridLabel label;
        int population = 0;
        int pollution = 0;
        bool update = false;
        bool updatePollution = false;

    public:
        Grid(int r, int c, GridLabel l);
        int getRow();
        int getColumn();
        GridLabel getLabel();
        int getPopulation();
        void setPopulation( int x );
        void growPopulation();
        int getPollution();
        void setPollution( int x );
        bool isUpdate();
        void setUpdate( bool b );
        bool isUpdatePollution();
        void setUpdatePollution( bool b );

};

#endif /* GRID_H */
