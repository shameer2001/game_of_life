#/*============================================================================
#
#  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.
#
#  Copyright (c) University College London (UCL). All rights reserved.
#
#  This software is distributed WITHOUT ANY WARRANTY; without even
#  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
#  PURPOSE.
#
#  See LICENSE.txt in the top level directory for details.
#
#============================================================================*/

set(DATA_DIR ${CMAKE_SOURCE_DIR}/test/data)
set(TMP_DIR ${CMAKE_BINARY_DIR}/test/temp)

set(TEST_CASES
  golBasicTest
  golCommandLineArgsTest
  # Add name of new test file here (without .cpp extension) to build a new test executable
  golGridTest
)

foreach(_test_case ${TEST_CASES})
  add_executable(${_test_case} ${_test_case}.cpp golCatchMain.cpp)
  target_link_libraries(${_test_case} ${PHAS0100ASSIGNMENT1_LIBRARIES} ${ALL_THIRD_PARTY_LIBRARIES})
endforeach()

# Adding tests is done outside the above loop,
# as each test will need different arguments.

##################################################################################################
# Dont forget its:  add_test(<test name (globally unique) > <exe name> <argument1> <argument2>
##################################################################################################

add_test(NoArgs ${EXECUTABLE_OUTPUT_PATH}/golBasicTest)
add_test(1File ${EXECUTABLE_OUTPUT_PATH}/golCommandLineArgsTest ${DATA_DIR}/input.txt)
# Add add_test line here to expose a new test executable to CTest
add_test(GameGrid ${EXECUTABLE_OUTPUT_PATH}/golGridTest)