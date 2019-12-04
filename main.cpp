#include <iostream>
#include <fstream>
#include <sstream>
#include "string.h"
#include "Maze.h"
#include "Position.h"

using namespace std;

int main()
{
    Maze mz;
    mz.readMaze();
    Position pos(mz);
    pos.solveMaze(mz);
    mz.printMaze();
    return 0;
}
