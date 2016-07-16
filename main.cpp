//
//  main.cpp
//  MazeProject
//
//  Created by Toby Dragon on 10/30/14.
//  Modified by Alex DiStasi on 11/20/14
//  Copyright (c) 2014 Toby Dragon. All rights reserved.

#include "stdafx.h"
#include <iostream>
#include <time.h>
using namespace std;

#include <list>
#include <stack>
#include "Maze.h"
#include "MazeSolver.h"

void printWalkedMaze(Maze* myMaze){
    for (int y=0; y<myMaze->getHeight(); y++){
        for (int x=0; x<myMaze->getWidth(); x++){
            Position p = Position(x, y);
            if (p == myMaze->getStart()){
                printf("S");
            }
            else if (p == myMaze->getEnd()){
                printf("E");
            }
			
            else if (myMaze->isValidLocation(p)){
				
               //if (path->isInList(p)){
                    //cout << ".";
			    // }
              // else if (badSteps->isInList(p)){
                  //  cout << "x";
              //  }
              // else{
                    cout << " ";
               // } 
            }
            else {
                cout << "#";
            }
        }
        cout << endl;
    }
    cout << endl << endl;
}

int main() {
    srand(int(time(0)));
    Maze* myMaze = new Maze();
	//printWalkedMaze(myMaze);
	MazeSolver mazeSolved= MazeSolver(myMaze);
	mazeSolved.test(myMaze);

}

