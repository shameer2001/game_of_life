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

    void PrintGrid();
    char Get(int row, int column);
    void Set(int row, int column, char value);




    private:

    bool status;
    int columns;
    int rows;


    std::vector<std::vector<char>> grid;
    







};

#endif