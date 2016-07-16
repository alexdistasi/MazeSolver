#include "StdAfx.h"
#include "LinkedList.h"
#include <iostream>
#include "List.h"
#include <time.h>
#include <ctime> 
#include "MazeSolver.h"
#include "Maze.h"

using namespace std;

LinkedList::LinkedList(){
	start=nullptr;
	ticks=0;
	theLength=0;
}

//O(n)
LinkedList::~LinkedList(){
	ListNode* current=start;
	while(current->getNext() != nullptr){
		ListNode* temp=current->getNext();
		delete current;
		current=temp;
		ticks++;
	}
	delete current;
	current=nullptr;
	start=nullptr;
	ticks+=3;
}

//O(n)
int LinkedList::length(){
	ListNode* current=start;
	int theLength=0;
	while (current->getNext()!=nullptr){
		theLength++;
		ticks++; 
	}
	return theLength;
}

//O(1)
const Data LinkedList:: getStart(){
	ListNode* current=start;
	ticks+=1;
	return current->getData();
}

//O(1)
Data LinkedList::removeStart(){
	Data returnVal;
	if (start==nullptr){
		cout<<"error. empty list"<<endl;
	}
	else{
		ListNode* current=start;
		ListNode* nodeAfterDelete=current->getNext();
		Data temp=current->getData();
		delete current;
		current=nullptr;
		start=nodeAfterDelete;
		//cout<<"START IS NOW: "<<start->getData()<<endl;
		ticks+=5;
		//cout<<"TEMP FOR REMOVE START IS: " << temp;
		returnVal=temp;
	}
	return returnVal;
}

//O(n)
const Data LinkedList:: getEnd(){
	ListNode* current=start;
	while (current->getNext()!=nullptr){
		current=current->getNext();
		ticks++;
	}
	ticks+=2;
	return current->getData();
}

//O(n)
Data LinkedList::removeEnd(){
	ListNode* current=start;
	ListNode* nodeBeforeDelete=nullptr;
	if (start==nullptr){
		cout<<"empty list"<<endl;
	}
	else{
		while (current->getNext()!=nullptr){
			ticks++;
			current=current->getNext();
			if (current->getNext()!=nullptr){
				if (current->getNext()->getNext()==nullptr){
					nodeBeforeDelete=current;
					//cout<<nodeBeforeDelete<<endl;
				}
			}
		}
	}

	Data temp=current->getData();
	//cout<<"CURRENT IN 'REMOVE END' RIGHT BEFORE DELETION IS: "<<current->getData();
	delete current;  
	current=nullptr;
	//cout<<"node before delete before setnext is set to nullptr is: "<<nodeBeforeDelete->getData()<<endl;
	nodeBeforeDelete->setNext(nullptr); //()node after
	//cout<<"NODE BEFORE DELETE AFTER GETNEXT IS SET TO NULLPTR IS: "<<nodeBeforeDelete->getData()<<endl;
	ticks+=6;
	//cout<<"TEMP IS: "<<temp<<endl;
	return temp;

}



//O(n)
void LinkedList::addToEnd(Data toAdd){
	if (start == nullptr){
        start = new ListNode(&toAdd, nullptr);
    }
    else {
        ListNode* current = start;
        while (current->getNext() != nullptr){
            current = current->getNext();
			ticks++;
        }
		ticks+=5;
        current->setNext(new ListNode(&toAdd, nullptr));
    }

}
void LinkedList::addToFront(Data toAdd){
	if (start == nullptr){
        start = new ListNode(&toAdd, nullptr);
	}
	else{
		ListNode* current=start;
		current->setNext(current);
		ListNode* nodeAfterInsert=current->getNext();
		start= new ListNode (&toAdd, nullptr);
	}
   

}


/*
void LinkedList::addToFront(Data toAdd){
	if (start == nullptr){
        start = new ListNode(&toAdd, nullptr);
    }
    else {
        ListNode* current = start;
		start=toAdd;
        while (current->getNext() != nullptr){
            current = current->getNext();
			ticks++;
        }
		ticks+=5;
        current->setNext(new ListNode(&toAdd, nullptr));
    }

}
*/
/*
bool LinkedList::findData(Data search){

}

*/



//O(n)
void LinkedList::printList(){
	ListNode* current=start;
	cout<<"{";
	while (current != nullptr){ 
		cout<<current->getData() << ",";
		current=current->getNext();
		ticks++;
	}
	ticks+=3;
	cout<<"}";
}
//O(n)
int LinkedList::calcMemInUse(){
    ListNode* current = start;
    int memory = 0;
    memory+= sizeof(length());//check if length variable
    memory+= sizeof(start);
    if(current != nullptr){
        while(current != nullptr){
            memory+=sizeof(*current);//big box
            memory+=sizeof(current->getData());//small box
            current = current->getNext();
        }
        memory+=sizeof(current->getNext());//for last in list
        memory+=sizeof(nullptr);
    }

 
    ticks+=6;
    return memory;
}
//O(1)
long LinkedList::getElapsedTime(){
	return ticks;
}

ostream& operator<< (ostream &out, LinkedList &arrayList){
    // Since operator<< is a friend, we can access the data members of CarLot directly.
    ListNode* current = arrayList.start;
    int i=0;
    while (current->getNext() != nullptr){
        out << "["  << i++ << "] \t" << current->getData() << "\n";
        current = current->getNext();
    }
    return out;
}