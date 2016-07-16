//
//  List.h
//  List
//
//  Created by Toby Dragon on 10/9/14.
//  Copyright (c) 2014 Toby Dragon. All rights reserved.
//

#ifndef List_List_h
#define List_List_h

#include "stdafx.h"
#include <string>
#include <iostream>
#include "Position.h";

using namespace std;

#define Data Position
//#define Data int
//#define Data Car

class List {
public:
    //default destructor, declared virtual to ensure that child destructors are called
    virtual ~List(){};
    
    //returns the number of items in the list
    virtual int length() = 0;
    
    //returns the item at the start of the list
    //(earliest item added)
    //const so that the item can't be changed
    virtual const Data getStart() = 0;
    
    //removes the item at the start of the list
    //returns the item removed
    virtual Data removeStart() = 0;
    
    //returns the item at the end of the list
    //(most recent item added)
    //const so that the item can't be changed
    virtual const Data getEnd() = 0;
    
    //removes the item at the end of the list
    //returns the item removed
    virtual Data removeEnd() = 0;
    
    //adds an item to the end of the list
    //param toAdd: the item to add
    virtual void addToEnd(Data toAdd) = 0;
    
	
    //returns a string representing the list                                    
    virtual void printList() = 0;

	//returns if something is in list
//	virtual void isInList() =0;
    
    //returns the number of bytes currently used by this entire list object
    virtual int calcMemInUse() = 0;
    
    //returns the number of ticks this object has taken,
    //the total for all operations since the object was created
    virtual long getElapsedTime() = 0;
};
#endif
