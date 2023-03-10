#include "golGameOfLife.h"



GameOfLife::GameOfLife(GameGrid grid2d): grid_current(grid2d), grid_next(grid2d) {};




GameGrid GameOfLife::getGridCurr() {
    return grid_current;
}
GameGrid GameOfLife::getGridNext() {
    return grid_next;
}



// Implement the Game Of Life rules for a single step in the game
void GameOfLife::takeStep() {
    rows = grid_current.GetGridSize().first;
    cols = grid_current.GetGridSize().second;


    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {

            int live_neighb = grid_current.LiveNeighbours(i, j);


            // Rule 1: A dead cell with exactly three live neighbours should become a live cell.
            if(grid_current.Get(i, j) == false) {
                
                if(live_neighb == 3) {
                    grid_next.Set(i, j, true);
                }
            }


            // Rule 2: A live cell with two or three live neighbours should stay alive.
            // Rule 3: A live cell with less than two or more than three live neighbours should die.
            else if(grid_current.Get(i, j) == true) {

                if(live_neighb < 2    ||    live_neighb > 3) {
                    grid_next.Set(i, j, false);
                }
            }

     
        }
    }

    grid_current = grid_next;

}



void GameOfLife::printGrid() {
    std::cout << "==================New-Iteration=================" << std::endl;
    grid_current.PrintGrid();

}


