#include "Grid.h"

Grid::Grid(int r, int c, GridLabel l){
    row = r;
    column = c;
    label = l;
}

int Grid::getRow(){
    return row;
}

int Grid::getColumn(){
    return column;
}

GridLabel Grid::getLabel(){
    return label;
}

int Grid::getPopulation(){
    return population;
}

void Grid::setPopulation( int x ){
    population = x;
}

void Grid::growPopulation(){
    population++;
}

int Grid::getPollution(){
    return pollution;
}

void Grid::setPollution( int x){
    pollution = x;
}

bool Grid::isUpdate(){
    return update;
}

void Grid::setUpdate( bool b ){
    update = b;
}
