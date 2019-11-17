#pragma once

#ifndef PRIORITY_QUEUE_H

#include<iostream>
#include "mh.h"
#include "Queue.h"

class PriorityQueue
{
	QueueNode** ar;

public:

	int size;
	PriorityQueue();
	void push(QueueNode* val);
	void remove(QueueNode* nod);
	void removeat(int index);
	int indexof(QueueNode* nod);
	QueueNode* operator[](int index);
	void display();
	void clear();
	bool empty();
	QueueNode* pop();
	QueueNode* peek();

};

#endif // !PRIORITY_QUEUE_H