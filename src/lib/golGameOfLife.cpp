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
            if(grid_current.Get(i, j) == '-') {
                
                if(live_neighb == 3) {
                    grid_next.Set(i, j, 'o');
                }
            }


            // Rule 2: A live cell with two or three live neighbours should stay alive.
            // Rule 3: A live cell with less than two or more than three live neighbours should die.
            else if(grid_current.Get(i, j) == 'o') {

                if(live_neighb < 2    ||    live_neighb > 3) {
                    grid_next.Set(i, j, '-');
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




// int main() {

//     //GameGrid my_grid(5,5); // create and instance of the GameGrid constructor

//     GameGrid my_grid("test/data/glider.txt"); 

//     //my_grid.PrintGrid();
//     //std::cout << my_grid.LiveNeighbours(2,1);

//     GameOfLife GameOfLife(my_grid);
//     //GameOfLife.printGrid();

//     //my_grid.Set(4, 5, '-');



//     //std::cout << "hello";
//     GameOfLife.printGrid();


//     GameOfLife.takeStep();

//     //my_grid.PrintGrid();
//     GameOfLife.printGrid();


//     GameOfLife.getGridCurr().PrintGrid();






//     return 0;
// };