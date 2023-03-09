#include "catch.hpp"
#include "golCatchMain.h"
#include "golGameGrid.h"
#include <iostream>
#include <vector>


TEST_CASE( "Test Instantiation of GameGrid class", "[GameGrid]" ) {
  GameGrid testGrid(2, 2);

  SECTION("Get function", "[GameGrid]") {
    REQUIRE( testGrid.Get(0, 0) == '-');
    REQUIRE( testGrid.Get(0, 1) == '-');
    REQUIRE( testGrid.Get(1, 0) == '-');
    REQUIRE( testGrid.Get(1, 1) == '-');
  }


  SECTION("Set function", "[GameGrid]") {
    testGrid.Set(1, 0, 'o');
    testGrid.Set(1, 1, 'o');

    REQUIRE( testGrid.Get(0, 0) == '-');
    REQUIRE( testGrid.Get(0, 1) == '-');
    REQUIRE( testGrid.Get(1, 0) == 'o');
    REQUIRE( testGrid.Get(1, 1) == 'o');
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


  // Loop through all of grid:

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