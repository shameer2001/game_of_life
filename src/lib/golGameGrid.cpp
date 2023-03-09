#include "golGameGrid.h"



GameGrid::GameGrid(int row_num, int column_num): rows(row_num), columns(column_num)   {

    grid = std::vector<std::vector<char>>(rows, std::vector<char>(columns, '-'));
}

// Constructor for random grid initialisation
GameGrid::GameGrid(int row_num, int column_num, int alive_num): rows(row_num), columns(column_num), alive(alive_num)   {

    grid = std::vector<std::vector<char>>(rows, std::vector<char>(columns, '-'));
    SetRand();
}



void GameGrid::PrintGrid() {
    
    // Loop through entire grid:
    for (auto &i: grid) {
        for (auto &j: i) {
            std::cout << j;
        }
        std::cout << '\n';
    }
    std::cout << " " << std::endl;
}



char GameGrid::Get(int row, int column) {
    return grid[row][column];
}
void GameGrid::Set(int row, int column, char value) {
    grid[row][column] = value;
}



// Set alive cells randomly for random initializer constructor
void GameGrid::SetRand() {

    int alive_count = 0;
    srand(time(nullptr)); // Set random seed


    while (alive != alive_count)
    {
        int rand_row = rand()%(rows -1 + 1); // Generate random number between 0 and total row number
        int rand_column = rand()%(columns -1 + 1); 


        if( Get(rand_row, rand_column) == '-') {
            alive_count++;
            Set(rand_row, rand_column, 'o');
        }
    }

        
}



// int main(){

// };