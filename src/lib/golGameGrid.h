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
    GameGrid(int row_num, int column_num, int alive_rand); 

    void PrintGrid();
    char Get(int row, int column);
    void Set(int row, int column, char value);

    void SetRand();




    private:

    bool status;
    int columns;
    int rows;
    int alive;


    std::vector<std::vector<char>> grid;
    

};

#endif