#include "golGameGrid.h"


GameGrid::GameGrid() {};

GameGrid::GameGrid(int row_num, int column_num): rows(row_num), columns(column_num)   {
    CheckGridSize(rows, columns);
    grid = std::vector<std::vector<char>>(rows, std::vector<char>(columns, '-'));
}

// Constructor for random grid initialisation
GameGrid::GameGrid(int row_num, int column_num, int alive_num): rows(row_num), columns(column_num), alive(alive_num)   {
    CheckGridSize(rows, columns);
    CheckAliveNum(rows, columns, alive);


    grid = std::vector<std::vector<char>>(rows, std::vector<char>(columns, '-'));
    SetRand();
}








std::vector<std::vector<char>> GameGrid::GetGrid() {
    return grid;
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
    //srand(time(nullptr)); // Set random seed
    
    unsigned seed = std::chrono::high_resolution_clock::now().time_since_epoch().count(); // Set random seed
    srand(seed);


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






void GameGrid::CheckGridSize(int row_num, int col_num) {
    try{
        if (row_num <= 0 || col_num <= 0) {
            throw std::out_of_range("The grid rows and columns must be positive integers");
        }
    }
    catch(std::out_of_range &err_msg) {
        std::cerr << "Exception: " << err_msg.what() << std::endl;
        throw; // Throw the SAME exception
    }
}


void GameGrid::CheckAliveNum(int row_num, int col_num, int alive_num) {
    try{
        if (alive_num < 0    ||    alive_num > row_num*col_num) {
            throw std::out_of_range("The number of alive cells must be non-negative and less than the grid size!");
        }
    }
    catch(std::out_of_range &err_msg) {
        std::cerr << "Exception: " << err_msg.what() << std::endl;
        throw;
    }
}

// int main(){


// };