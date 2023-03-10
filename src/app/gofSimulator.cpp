#include "golGameOfLife.h"
#include <thread>
#include <chrono>

static void help()
{
    std::cout << "Usage: gof_simulator [OPTION]... [FILE]...\n"
              << "Options:\n"
              << "  -g, --generations  specify the number of generations to simulate\n"
              << "  -r, --random       start with random cell contents\n"
              << "  -f, --file         specify the text-file name or path\n"
              << "  -s, --size         specify the size of the grid in terms of numbers of rows and columns (only needed for random)\n"
              << "  -a, --alive        specify the total number of initial alive cells to place (only needed for random)\n"
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



        if (arg == "-f" || arg == "--file" && (i+1)<argc)
        {
            text_file = true;
            filename = argv[i + 1]; // Argument after --t is the filename
            i++;
        }




        else if (arg == "-r" || arg == "--random")
        {
            random = true;
        }
        else if ((arg == "-s" || arg == "--size") && (i+2)<argc)
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

    

    if (random==true) {
        GameGrid grid(rows, columns, alive);
        GameOfLife gol(grid);


        for(int i = 0; i < generations; i++) {
            gol.printGrid();
            gol.takeStep();

            std::this_thread::sleep_for (std::chrono::seconds(1)); // Allow some time between each generation
        }
    }


    else if (text_file==true)
    {
        GameGrid grid(filename);
        GameOfLife gol(grid);


        for(int i = 0; i < generations; i++) {
            gol.printGrid();
            gol.takeStep();
        
            std::this_thread::sleep_for (std::chrono::seconds(1)); 
        }
    }
    
}