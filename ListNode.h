#ifndef __List__ListNode__
#define __List__ListNode__

#include <stdio.h>
#include "List.h"

#pragma once
class ListNode{
private:
	Data* data;
	ListNode* next;

public:
	ListNode(Data* dataIn, ListNode* nextIn);
	~ListNode();
	Data getData();
	ListNode* getNext();

	void setNext(ListNode* next);
};

#endif /* defined(__List__ListNode__) */