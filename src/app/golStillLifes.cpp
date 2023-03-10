#include "golGameOfLife.h"
#include <thread>
#include <chrono>

static void help()
{
    std::cout << "Usage: Still Life Simulator [OPTION]... [FILE]...\n"
              << "Options:\n"
              << "  -g, --generations  specify the number of generations to simulate\n"
              << "  -s, --size         specify the size of the grid in terms of numbers of rows and columns E.G. 5 rows and 6 columns: `--size 5 6`\n"
              << "  -a, --alive        specify the total number of initial alive cells to place randomly\n"
              << "  -h, --help         print this help message\n"
              << std::endl;
}




int main(int argc, char *argv[])
{
    // Parse command line arguments:
    int generations = 0;
    bool random = false;
    bool text_file = false;
    int rows = 0;
    int columns = 0;
    int alive = 0;
    std::string filename;


    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];


        
        if ((arg == "-s" || arg == "--size") && (i+2)<argc)
        {
            rows = std::stoi(argv[i + 1]); // Convert str to int (arg after "--size" is rows)
            columns = std::stoi(argv[i + 2]); 
            
            i++;
        }

        else if ((arg == "-a" || arg == "--alive") && (i+1)<argc)
        {
            alive = std::stoi(argv[i + 1]);
            i++;
        }

        else if ((arg == "-g" || arg == "--generations") && (i+1)<argc)
        {
            generations = std::stoi(argv[i + 1]);
            i++;
        }
        else if (arg == "-h" || arg == "--help")
        {
            help();
            return 0;
        }

    }

    




    for( int iteration = 0; iteration < 15; iteration++) {

        GameGrid grid(rows, columns, alive);
        GameOfLife gol(grid);

        for(int i = 0; i < generations; i++) {

            GameGrid grid_prev = gol.getGridCurr();
            gol.takeStep();
            gol.getGridCurr().IfSameGrid( gol.getGridCurr());


            if(  (grid_prev.IfSameGrid( gol.getGridCurr() ) == true)
                && (gol.getGridCurr().IfEmpty() == false)) {

                gol.getGridCurr().PrintGrid();
                break;
            }
            else {
                
            }
            std::this_thread::sleep_for (std::chrono::seconds(1)); //allow some time between each generation
        }
    }
    



    
}