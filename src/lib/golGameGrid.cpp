#include "golGameGrid.h"

// Empty default constructor for testing purposes
GameGrid::GameGrid() {};

GameGrid::GameGrid(int row_num, int column_num): rows(row_num), columns(column_num)   {
    CheckGridSize(rows, columns);
    grid = std::vector<std::vector<bool>>(rows, std::vector<bool>(columns, status_dead));
}

// Constructor for random grid initialisation
GameGrid::GameGrid(int row_num, int column_num, int alive_num): rows(row_num), columns(column_num), alive(alive_num)   {
    CheckGridSize(rows, columns);
    CheckAliveNum(rows, columns, alive);


    grid = std::vector<std::vector<bool>>(rows, std::vector<bool>(columns, status_dead));
    SetRand();
}

// Constructor for grid initialization from a file
GameGrid::GameGrid(std::string file_path) {
    CheckFileExists(file_path);
    std::ifstream file(file_path);


    std::string line;
    while (std::getline(file, line)) {

        std::vector<bool> single_line;

        for (auto i : line) {

            if (i == '-') {
                single_line.push_back(status_dead);
            } 
            else if (i == 'o') {
                single_line.push_back(status_alive);
            }

        }
        grid.push_back(single_line);
    }

    rows = grid.size();
    columns = grid[0].size();

    file.close();
}






std::pair<int, int> GameGrid::GetGridSize() {
    return {grid.size(), grid[0].size()};  // rows, columns
}


void GameGrid::PrintGrid() {
    
    // Loop through entire grid:
    for (auto i: grid) {
        for (auto j: i) {

            if (j == status_dead) {
                std::cout << "- ";
            }
            else if (j == status_alive) {
                std::cout << "o ";
            }

        }
        std::cout << '\n';
    }
    std::cout << " " << std::endl;
}



bool GameGrid::Get(int row, int column) {
    return grid[row][column];
}
void GameGrid::Set(int row, int column, bool value) {
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


        if( Get(rand_row, rand_column) == status_dead) {
            alive_count++;
            Set(rand_row, rand_column, status_alive);
        }
    }

}



int GameGrid::LiveNeighbours(int row, int column) {
    CheckCellLocation(row, column);

    int live_num = 0;

    // Loop through cells around user-input cell (ie row above & column above, row above & column to the left etc.)
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = column - 1; j <= column + 1; j++) {

            if (i >= 0 && j >= 0 && i < rows && j < columns 
            && !(i == row && j == column) && Get(i, j) == status_alive) {
                live_num++;
            }

        }
    }

    return live_num;

}



// For Still Life applications:
bool GameGrid::IfSameGrid(GameGrid grid2) {
    
    // Compare grid sizes
    if (grid2.GetGridSize().first != GetGridSize().first) {
        return false;
    }
    else if (grid2.GetGridSize().second != GetGridSize().second) {
        return false;
    }


    // Compare grid cells
    else {
        for (int i = 0; i < grid2.GetGridSize().first; i++) {
            for (int j = 0; j < grid2.GetGridSize().second; j++) {

                if (Get(i, j) != grid2.Get(i, j)) {
                    return false;
                }
            }
        }
        return true;
    }
}



bool GameGrid::IfEmpty() {

    int grid_area = GetGridSize().first*GetGridSize().second;
    int dead_num = 0;

    for (int i = 0; i < GetGridSize().first; i++) {
        for (int j = 0; j < GetGridSize().second; j++) {

            if (Get(i, j) == status_dead) {
                dead_num++;
            }

        }
    }

    if (grid_area == dead_num) {
        return true;
    }
    else {
        return false;
    }


}








void GameGrid::CheckGridSize(int row_num, int col_num) {
    try{
        if (row_num <= 0 || col_num <= 0) {
            throw std::out_of_range("The grid rows and columns must be positive integers");
        }
    }
    catch(std::out_of_range &err_msg) {
        std::cerr << "Error: " << err_msg.what() << std::endl;
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
        std::cerr << "Error: " << err_msg.what() << std::endl;
        throw;
    }
}


void GameGrid::CheckFileExists(std::string file_path) {
    std::ifstream file(file_path);
    try{
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file. Make sure the path is correct and the file exists.");
        }
    }
    catch(std::runtime_error &err_msg) {
        std::cerr << "Error: " << err_msg.what() << std::endl;
        throw;
    }
}


void GameGrid::CheckCellLocation(int row, int col) {
    try{
        if (row >= rows || col >= columns  || row < 0 || col < 0) {
            throw std::out_of_range("The row and column number must be non-negative and within the grid");
        }
    }
    catch(std::out_of_range &err_msg) {
        std::cerr << "Error: " << err_msg.what() << std::endl;
        throw;
    }
}

// int main(){
//     GameGrid testGrid1("test/data/glider.txt");
//     testGrid1.PrintGrid();

//     GameGrid testGrid2( 5, 5);

//     // std::cout << testGrid1.Get(2,0) << std::endl;
//     // std::cout << testGrid1.Get(3,1) << std::endl;
//     // std::cout << testGrid1.Get(3,2) << std::endl;
//     // std::cout << testGrid1.Get(2,2) << std::endl;
//     // std::cout << testGrid1.Get(1,2) << std::endl;

//     // if (testGrid1.IfSameGrid( testGrid1 ) == true) {
//     //     std::cout << testGrid1.IfSameGrid( testGrid1 ) << std::endl;
//     // }
//     //std::cout << testGrid1.LiveNeighbours(2, 0) << std::endl;


//     std::cout << testGrid1.IfEmpty() << std::endl;

// };