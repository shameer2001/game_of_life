#include "catch.hpp"
#include "golCatchMain.h"
#include "golGameGrid.h"
#include "golGameOfLife.h"
#include <iostream>
#include <vector>


TEST_CASE( "Test Instantiation of GameGrid class", "[GameGrid]" ) {
  GameGrid testGrid(2, 2);

  SECTION("Get function", "[GameGrid]") {
    REQUIRE(testGrid.Get(0, 0) == '-');
    REQUIRE(testGrid.Get(0, 1) == '-');
    REQUIRE(testGrid.Get(1, 0) == '-');
    REQUIRE(testGrid.Get(1, 1) == '-');
  }


  SECTION("Set function", "[GameGrid]") {
    testGrid.Set(1, 0, 'o');
    testGrid.Set(1, 1, 'o');

    REQUIRE(testGrid.Get(0, 0) == '-');
    REQUIRE(testGrid.Get(0, 1) == '-');
    REQUIRE(testGrid.Get(1, 0) == 'o');
    REQUIRE(testGrid.Get(1, 1) == 'o');
  }

}




TEST_CASE("Confirm Random Pattern of 2 Equal Parameter Grids are Different", "[GameGridRandom]" ) {
  int rows = 25;
  int columns = 26;
  
  GameGrid testGrid1(rows, columns, 50);
  GameGrid testGrid2(rows, columns, 50);

  bool cell_is_equal = true;


  // Loop through all of grid:

  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns; j++) {

      if(testGrid1.Get(i, j) != testGrid2.Get(i, j)) {
        cell_is_equal = false;
        break;
      }
    
    }
  }
  REQUIRE(cell_is_equal == false);
}





TEST_CASE("Confirm Same Number of Alive Cells in 2 Equal Parameter Grids", "[GameGridRandom]" ) {
  int rows = 25;
  int columns = 26;
  
  GameGrid testGrid1(rows, columns, 50);
  GameGrid testGrid2(rows, columns, 50);

  int grid1_alive = 0;
  int grid2_alive = 0;


  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns; j++) {

      if(testGrid1.Get(i, j) == 'o') {
        grid1_alive++;
      }
      if(testGrid2.Get(i, j) == 'o') {
        grid2_alive++;
      }

    }
  }
  REQUIRE(grid1_alive == 50);
  REQUIRE(grid2_alive == 50);
}

TEST_CASE("Check Input Parameters for Random Initialisation Constructor", "[GameGridRandom]" ) {
  GameGrid testGrid;

  SECTION("Check if grid size is valid", "[GameGrid]") {
    REQUIRE_THROWS(testGrid.CheckGridSize(-1, -2));
    REQUIRE_THROWS(testGrid.CheckGridSize(-45, 2));
    REQUIRE_NOTHROW(testGrid.CheckGridSize(1, 2));
    REQUIRE_NOTHROW(testGrid.CheckGridSize(10, 26));
  }

  SECTION("Check if alive cells number is valid", "[GameGrid]") {
    REQUIRE_NOTHROW(testGrid.CheckAliveNum(19, 1, 7));
    REQUIRE_NOTHROW(testGrid.CheckAliveNum(88, 346, 56));
    REQUIRE_THROWS(testGrid.CheckAliveNum(5, 5, -4));
    REQUIRE_THROWS(testGrid.CheckAliveNum(10, 10, 1000));
  }
}







TEST_CASE("Check File Constructor Grid Cell", "[GameGridFile]" ) {
  GameGrid testGrid1("../../test/data/glider.txt");
  GameGrid testGrid2("../../test/data/oscillators.txt");
  GameGrid testGrid3("../../test/data/still_lifes.txt");


  SECTION("Check if grid is read correctly", "[GameGridFile]") {
    // Check grid sizes:
    REQUIRE(testGrid1.GetGridSize().first == 10);
    REQUIRE(testGrid1.GetGridSize().second == 10);

    REQUIRE(testGrid2.GetGridSize().first == 12);
    REQUIRE(testGrid2.GetGridSize().second == 12);

    REQUIRE(testGrid3.GetGridSize().first == 10);
    REQUIRE(testGrid3.GetGridSize().second == 10);


    // Check alive and dead cells and location:
    REQUIRE(testGrid1.Get(2, 0) == 'o');
    REQUIRE(testGrid1.Get(3, 1) == 'o');
    REQUIRE(testGrid1.Get(3, 2) == 'o');
    REQUIRE(testGrid1.Get(2, 2) == 'o');
    REQUIRE(testGrid1.Get(1, 2) == 'o');

    int grid1Rows = testGrid1.GetGridSize().first;
    int grid1Cols = testGrid1.GetGridSize().second;

    int dead_num = 0;

    for(int i = 0; i < grid1Rows; i++) {
      for(int j = 0; j < grid1Cols; j++) {

        if ( (i != 2 && j != 0) 
        || (i != 3 && j != 1) 
        || (i != 3 && j != 2) 
        || (i != 2 && j != 2) 
        || (i != 1 && j != 2)) // Except cells already tested are alive
        {

          if(testGrid1.Get(i, j) == '-') {
            dead_num++;

          }
        }
      }
    }

    REQUIRE(dead_num == 95);
    REQUIRE(grid1Rows*grid1Cols - dead_num == 5); // Alive number
  
  }



  testGrid1.Set(2, 0, '-');
  testGrid2.Set(5, 8, 'o');
  testGrid3.Set(9, 9, 'o');

  SECTION("Check if Set method works with grid from file", "[GameGridFile]") {
    REQUIRE(testGrid1.Get(2, 0) == '-');
    REQUIRE(testGrid2.Get(5, 8) == 'o');
    REQUIRE(testGrid3.Get(9, 9) == 'o');
  }
}



TEST_CASE("File Does Not Exist Error Message", "[GameGridFile]" ) {
  GameGrid testGrid;


  REQUIRE_THROWS(testGrid.CheckFileExists("../../test/data/gliderrr.txt"));
  REQUIRE_THROWS(testGrid.CheckFileExists("../../test/dataaa/oscillators.txt"));
  REQUIRE_THROWS(testGrid.CheckFileExists("../../tesst/data/still_lifess.txt"));

  REQUIRE_NOTHROW(testGrid.CheckFileExists("../../test/data/glider.txt"));
  REQUIRE_NOTHROW(testGrid.CheckFileExists("../../test/data/oscillators.txt"));
  REQUIRE_NOTHROW(testGrid.CheckFileExists("../../test/data/still_lifes.txt"));
}








TEST_CASE("Live Neighbours Method Test", "[LiveNeighboursFunction]" ) {
  GameGrid testGrid1("../../test/data/glider.txt");
  GameGrid testGrid2("../../test/data/oscillators.txt");
  GameGrid testGrid3("../../test/data/still_lifes.txt");
  GameGrid testGrid4(5, 5, 25);

  REQUIRE(testGrid1.LiveNeighbours(5, 8) == 0);
  REQUIRE(testGrid1.LiveNeighbours(2, 0) == 1);
  REQUIRE(testGrid1.LiveNeighbours(2, 1) == 5);

  REQUIRE(testGrid2.LiveNeighbours(9, 3) == 4);
  REQUIRE(testGrid2.LiveNeighbours(11, 11) == 0);


  REQUIRE(testGrid3.LiveNeighbours(2, 2) == 5);
  REQUIRE(testGrid3.LiveNeighbours(8, 7) == 3);


  REQUIRE(testGrid4.LiveNeighbours(4, 4) == 3);
  REQUIRE(testGrid4.LiveNeighbours(2, 2) == 8);

  testGrid4.Set(2, 3, '-');
  REQUIRE(testGrid4.LiveNeighbours(2, 2) == 7);
  testGrid4.Set(2, 1, '-');
  REQUIRE(testGrid4.LiveNeighbours(2, 2) == 6);

}


TEST_CASE("Live Neighbours Method Error Message Test", "[LiveNeighboursFunction]" ) {
  GameGrid testGrid1("../../test/data/glider.txt");
  GameGrid testGrid2("../../test/data/oscillators.txt");
  GameGrid testGrid3("../../test/data/still_lifes.txt");
  GameGrid testGrid4(5, 5, 25);

  REQUIRE_NOTHROW(testGrid1.LiveNeighbours(5, 8));
  REQUIRE_NOTHROW(testGrid2.LiveNeighbours(11, 11));
  REQUIRE_NOTHROW(testGrid3.LiveNeighbours(2, 0));
  REQUIRE_NOTHROW(testGrid4.LiveNeighbours(4, 4));

  REQUIRE_THROWS(testGrid1.LiveNeighbours(10, 10));
  REQUIRE_THROWS(testGrid2.LiveNeighbours(12, 12));
  REQUIRE_THROWS(testGrid3.LiveNeighbours(10, 10));
  REQUIRE_THROWS(testGrid4.LiveNeighbours(5, 5));


  REQUIRE_THROWS(testGrid1.LiveNeighbours(544, 988));
  REQUIRE_THROWS(testGrid2.LiveNeighbours(5, 12));
  REQUIRE_THROWS(testGrid3.LiveNeighbours(100, 10));

  REQUIRE_THROWS(testGrid1.LiveNeighbours(-10, 9));
  REQUIRE_THROWS(testGrid2.LiveNeighbours(5, -12));
  REQUIRE_THROWS(testGrid3.LiveNeighbours(-2, -4));

}











// Test GameOfLife Class:

TEST_CASE("takeStep Method Test", "[GOLtakeStep]") {

  GameGrid testGrid("../../test/data/glider.txt");
  GameOfLife testGol(testGrid);


  int gridRows = testGol.getGridCurr().GetGridSize().first;
  int gridCols = testGol.getGridCurr().GetGridSize().second;



  // Check alive and dead cells and location BEFORE TAKE STEP:
  REQUIRE(testGol.getGridCurr().Get(2, 0) == 'o');
  REQUIRE(testGol.getGridCurr().Get(3, 1) == 'o');
  REQUIRE(testGol.getGridCurr().Get(3, 2) == 'o');
  REQUIRE(testGol.getGridCurr().Get(2, 2) == 'o');
  REQUIRE(testGol.getGridCurr().Get(1, 2) == 'o');


  int dead_num = 0;

  for(int i = 0; i < gridRows; i++) {
    for(int j = 0; j < gridCols; j++) {

      if ( (i != 2 && j != 0) 
      || (i != 3 && j != 1) 
      || (i != 3 && j != 2) 
      || (i != 2 && j != 2) 
      || (i != 1 && j != 2)) // Except cells already tested are alive
      {
        if(testGol.getGridCurr().Get(i, j) == '-') {
          dead_num++;
        }
      }
    }
  }

  REQUIRE(dead_num == 95);
  REQUIRE(gridRows*gridCols - dead_num == 5); // Alive number




  testGol.takeStep();




  // Check alive and dead cells and location AFTER TAKE STEP:
  REQUIRE(testGol.getGridNext().Get(1, 1) == 'o');
  REQUIRE(testGol.getGridNext().Get(2, 3) == 'o');
  REQUIRE(testGol.getGridNext().Get(2, 2) == 'o');
  REQUIRE(testGol.getGridNext().Get(3, 2) == 'o');
  REQUIRE(testGol.getGridNext().Get(3, 1) == 'o');


  int dead_num_next = 0;

  for(int i = 0; i < gridRows; i++) {
    for(int j = 0; j < gridCols; j++) {

      if ( (i != 1 && j != 1) 
      || (i != 2 && j != 3)
      || (i != 2 && j != 2)
      || (i != 3 && j != 2)
      || (i != 3 && j != 1) ) 
      {
        if(testGol.getGridNext().Get(i, j) == '-') {
          dead_num_next++;
        }
      }
    }
  }

  REQUIRE(dead_num_next == 95);
  REQUIRE(gridRows*gridCols - dead_num_next == 5); 
}