#include "golGameGrid.h"



GameGrid::GameGrid(int row_num, int column_num): rows(row_num), columns(column_num)   {

    grid = std::vector<std::vector<char>>(rows, std::vector<char>(columns, '-'));
}


void GameGrid::printGrid() {

    for (auto &i: grid) {
        for (auto &j: i) {
            std::cout << j;
        }
        std::cout << '\n';
    }
    std::cout << " " << std::endl;
}



char GameGrid::get(int row, int column) {
    return grid[row][column];
}
void GameGrid::set(int row, int column, char value) {
    grid[row][column] = value;
}



