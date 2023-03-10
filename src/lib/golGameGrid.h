#ifndef golGameGrid_h
#define golGameGrid_h


#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
#include <stdexcept>


class GameGrid 
{
    public:

    GameGrid(); 
    GameGrid(int row_num, int column_num);
    GameGrid(int row_num, int column_num, int alive_rand); 
    GameGrid(std::string file_path);
    
    std::pair<int, int> GetGridSize();

    void PrintGrid();
    bool Get(int row, int column);
    void Set(int row, int column, bool alive);
    int LiveNeighbours(int row, int column);

    void SetRand();


    void CheckGridSize(int row_num, int col_num);
    void CheckAliveNum(int row_num, int col_num, int alive_num); 
    void CheckFileExists(std::string file_path);
    void CheckCellLocation(int row, int col);




    private:


    int columns;
    int rows;
    int alive; // Number of alive cells for random initializer constructor


    bool status_dead = false;
    bool status_alive = true;

    std::vector<std::vector<bool>> grid;
    

};

#endif