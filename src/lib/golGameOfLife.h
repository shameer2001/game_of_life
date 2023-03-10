#ifndef golGameOfLife_h
#define golGameOfLife_h


#include <iostream>
#include "golGameGrid.h"





class GameOfLife {


    public:

    GameOfLife(GameGrid grid2d);

    GameGrid getGridCurr();
    GameGrid getGridNext();

    void takeStep();
    void printGrid();



    private:

    GameGrid grid_current;
    GameGrid grid_next;

    int rows;
    int cols;



};






#endif