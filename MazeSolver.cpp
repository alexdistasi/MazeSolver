//
//  MazeSolver.cpp
//  MazeProject
//
//  Created by Alex DiStasi on 11/20/14.
//  Copyright (c) 2014 Alex DiStasi. All rights reserved.
//


#include "stdafx.h"
#include "MazeSolver.h"
using namespace std;


bool isInList(list<Position> pos, Position p){
    std::list <Position>::iterator iter=std::find(pos.begin(), pos.end(), p); 
    if(iter == pos.end()){
        return false;
    }
    return true;
}

void printWalkedMaze(Maze* myMaze, list<Position> previous, list<Position> solution){
    for (int y=0; y<myMaze->getHeight(); y++){
        for (int x=0; x<myMaze->getWidth(); x++){
            Position p = Position(x, y);
            if (p == myMaze->getStart()){
                printf("S");
            }
            else if (p == myMaze->getEnd()){
                printf("E");
            }else if(!myMaze->isValidLocation(p)){
                cout << "#";
            }
            else if (myMaze->isValidLocation(p)){
                
                if (isInList(previous, p) && !isInList(solution, p)){
                      cout << "x";
                }
                else if (isInList(solution, p)){
                    cout << ".";
                }
                else{
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
    cout << endl << endl;
}

MazeSolver::MazeSolver(Maze* mazeIn){
    test(mazeIn);
    printWalkedMaze(mazeIn, prevPositions, solution);

}

MazeSolver::~MazeSolver(){
    
}

void MazeSolver::test(Maze* theMaze){
    Position end = theMaze->getEnd();
    Position current = theMaze->getStart();
    Position nextMoves;
    while (current!=end){
        Position* nextMovesArr=current.getNextMoves();
        int possiblePos=0;
        int invalidNum=0;
        bool positionChosen=false;
        for(int x = 0; x<4; x++){
            std::list <Position>::iterator iter=std::find(prevPositions.begin(), prevPositions.end(),  (*(nextMovesArr+x)));
            //checks if spots around are valid and weren't previously used
            if (theMaze->isValidLocation(*(nextMovesArr+x)) && iter==prevPositions.end()){
                possiblePos++;
                if (!positionChosen) {
                    nextMoves = (*(nextMovesArr+x));
                    positionChosen = true;
                }
            } else {
                invalidNum++;
            }
        }
        if (possiblePos>1){
            decPoints.push(current);
        }
        if (positionChosen) {
            prevPositions.push_front(current);
            solution.push_front(current);
            current = nextMoves;
        } else {
            //this means it hit a dead end
            badSteps.push_front(current);
            

            while (decPoints.top() != solution.front()) {   
                solution.pop_front();
            }
            
            //Check if top of DecPoints is a decision point
            Position topOfDecisionPoints = decPoints.top();
            nextMovesArr = topOfDecisionPoints.getNextMoves();
            possiblePos = 0;
            for(int x = 0; x<4; x++){
                std::list <Position>::iterator iter=std::find(prevPositions.begin(), prevPositions.end(), (*(nextMovesArr+x)));
                if (theMaze->isValidLocation(*(nextMovesArr+x)) && iter==prevPositions.end()){
                    possiblePos++;
                }
            }
           
            
            //if possible positions is > 1, it is a decision point
            if (possiblePos == 1) {
                decPoints.pop();
            }
            current = solution.front();
        }
    }
}