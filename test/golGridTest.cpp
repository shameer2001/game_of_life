#include "catch.hpp"
#include "golCatchMain.h"
#include "golGameGrid.h"
#include <iostream>
#include <vector>

TEST_CASE( "Assess Instantiation of GameGrid class", "[GameGrid]" ) {
  GameGrid gameGrid(2, 2);

  SECTION("Get function", "[GameGrid]") {
    REQUIRE( gameGrid.Get(0, 0) == '-');
    REQUIRE( gameGrid.Get(0, 1) == '-');
    REQUIRE( gameGrid.Get(1, 0) == '-');
    REQUIRE( gameGrid.Get(1, 1) == '-');
  }


  SECTION("Set function", "[GameGrid]") {
    gameGrid.Set(1, 0, 'o');
    gameGrid.Set(1, 1, 'o');

    REQUIRE( gameGrid.Get(0, 0) == '-');
    REQUIRE( gameGrid.Get(0, 1) == '-');
    REQUIRE( gameGrid.Get(1, 0) == 'o');
    REQUIRE( gameGrid.Get(1, 1) == 'o');
  }


}

TEST_CASE( "My second test", "[some group identifier]" ) {
  std::vector<int> a;
  REQUIRE( a.size() == 0 );
}

