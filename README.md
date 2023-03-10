[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-f4981d0f882b2a3f0472912d15f9806d57e124e0fc890972558857b51b24a6f9.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=10023733)
PHAS0100ASSIGNMENT1
------------------

Purpose
-------

This project serves as a starting point for the PHAS0100 2022/23 Assignment 1 Game of Life Simulation coursework. It has a reasonable folder structure for [CMake](https://cmake.org/) based projects that use [CTest](https://cmake.org/) to run unit tests via [Catch](https://github.com/catchorg/Catch2). 

Further information on the specific project is left as an exercise for the student.

Credits
-------

This project is maintained by [Dr. Jamie Quinn](http://jamiejquinn.com/). It is based on [CMakeCatch2](https://github.com/UCL/CMakeCatch2.git) that was originally developed as a teaching aid for UCL's ["Research Computing with C++"](https://github-pages.ucl.ac.uk/research-computing-with-cpp/) course developed by [Dr. James Hetherington](http://www.ucl.ac.uk/research-it-services/people/james) and [Dr. Matt Clarkson](https://iris.ucl.ac.uk/iris/browse/profile?upi=MJCLA42).

Build Instructions
------------------

To run cmake:

```
cmake -B build
```

To compile:

```
cmake --build build
```

To test:

```
cd build
ctest
```

## **How to use the gofSimulator app:**

Once, the cmake has compiled and you have done the testing, use the command line help prompt in the application gofSimulator:

```
./bin/gofSimulator -h
```

This will show you the different commands you can run. There are 2 types of commands you can run: random grid initialisation and grid initialisation from a file. For example:

```
./bin/gofSimulator --random --size 7 7 --alive 15 -g 10
```

This will run simulate the game for a 7x7 grid with 15, randomly placed, alive cells for 10 generations/iterations.


```
./bin/gofSimulator --file "test/data/glider.txt" -g 4
```

This will run the grid present in `glider.txt` for 4 generations.






## **How to use the golStillLifes app:**

This is similar to the above app, however it is now by default random. This will look for and only print those cells that do not change with the Game Of Life rules/instructions. For example, running a 4x4 grid of 10 randomly placed alive cells for 10 generations looks like:

```
./bin/golStillLifes --size 4 4 --alive 10 -g 10
```

With the result being:

![still_lifes_4x4](/images/still_lifes_4x4.png)