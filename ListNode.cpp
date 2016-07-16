#include "StdAfx.h"
#include "ListNode.h"
#include <iostream>
#include "List.h"
#include <time.h>
#include <ctime> 

using namespace std;


ListNode::ListNode(Data* dataIn, ListNode* nextIn){
	data=new Data(*dataIn);
	next=nextIn;
}


ListNode::~ListNode(){
	delete data;
	data=nullptr;
	next=nullptr;
}

Data ListNode::getData(){
	return Data(*data);
}

ListNode* ListNode:: getNext(){
	return next;
}

void ListNode::setNext(ListNode* next){
	this->next=next;
}
