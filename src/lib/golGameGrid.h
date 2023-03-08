#ifndef golGameGrid_h
#define golGameGrid_h


#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>


class GameGrid 
{
    public:

    GameGrid(int row_num, int column_num);

    void printGrid();
    char get(int row, int column);
    void set(int row, int column, char value);




    private:

    bool status;
    int columns;
    int rows;


    std::vector<std::vector<char>> grid;
    







};

#endif