#ifndef __List__LinkedList__
#define __List__LinkedList__

#include <stdio.h>
#include "List.h"
#include "ListNode.h"


#pragma once
class LinkedList: public List{
private:
	 ListNode* start;
	 long ticks;
	 int theLength;

public:
	LinkedList();
	LinkedList(const LinkedList& arrToCopy);
    ~LinkedList();
    int length();
    const Data getStart();
    Data removeStart();
    const Data getEnd();
    Data removeEnd();
    void printList();
	void addToEnd(Data toAdd);
	//
	void addToFront(Data toAdd);
	//
	bool findData(Data search);
  
    int calcMemInUse();
    long getElapsedTime();

	friend ostream& operator<< (ostream &out, LinkedList &arraylist);
};



#endif /* defined(__List__LinkedList__) */