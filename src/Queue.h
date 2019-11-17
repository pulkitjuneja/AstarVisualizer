#pragma once

#ifndef QUEUE_H

struct QueueNode
{
	int x;
	int y;
	int h;
	int g;
	QueueNode* parent;
public:
	QueueNode(int x, int y, int h, int g, QueueNode*parent);
	int compareto(QueueNode* nod);
	bool issame(QueueNode* nod);
};

class Queue
{
	QueueNode** ar;
	int front, rear;
public:
	Queue();
	void push(QueueNode* nod);
	QueueNode* pop();
	QueueNode* pop_back();
	int indexof(QueueNode* nod);
	void clear();
	bool empty();
	void display();
};

#endif // !QUEUE_H
