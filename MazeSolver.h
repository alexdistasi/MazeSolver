//
//  MazeSolver.h
//  MazeProject
//
//  Created by Alex DiStasi on 11/20/14.
//  Copyright (c) 2014 Alex DiStasi. All rights reserved.
//


#ifndef __Lab07__MazeSolver__
#define __Lab07__MazeSolver__

#include "Maze.h"
#include "Position.h"
#include <stack>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

#pragma once

class MazeSolver{

private:
 Position** decisionPoints;
 Position end;

public:

 MazeSolver(Maze* theMaze);
 void test(Maze* theMaze);
 void getEnd();
 stack <Position> decPoints;
 list <Position> prevPositions;
 list <Position> solution;
 list <Position> badSteps;
 ~MazeSolver();

};

#endif /* defined(__Lab08__MazeSolver__) */