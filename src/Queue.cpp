#include "Queue.h"

QueueNode::QueueNode(int x, int y, int h, int g, QueueNode*parent)

{
	this->x = x;
	this->y = y;
	this->h = h;
	this->g = g;
	this->parent = parent;
}

int QueueNode::compareto(QueueNode* nod)
{
	if ((nod->g + nod->h) > (g + h))
		return -1;
	else if ((nod->g + nod->h) == (g + h))
		return 0;
	else
		return 1;

}
bool QueueNode::issame(QueueNode* nod)
{
	if (this->x == nod->x&&this->y == nod->y)
		return true;
	else
		return false;
}

// ----------------------------------------------------------------------------------------------------------------

Queue::Queue()
{
	ar = new QueueNode*[500];
	front = rear = -1;
}

bool Queue::empty()
{
	if (front == -1)return true;
	return false;
}
void Queue::push(QueueNode* nod)
{
	if (front == -1)
	{
		front = rear = 0;
	}
	else
	{
		rear++;
	}
	ar[rear] = nod;
}
QueueNode* Queue::pop()
{
	if (front == -1)
	{
		return nullptr;
	}
	else if (front == rear)
	{
		QueueNode* v = ar[front];
		front = rear = -1;
		return v;
	}
	else
	{
		return ar[front++];
	}
}

int Queue::indexof(QueueNode* nod)
{
	if (front == -1)return -1;
	for (int i = front; i <= rear; i++)
	{
		if (ar[i]->issame(nod))
			return i;
	}
	return -1;
}
void Queue::clear()
{
	delete[] ar;
	ar = new QueueNode*[500];
	front = rear = -1;
}

QueueNode* Queue::pop_back()
{
	if (rear == -1)
		return nullptr;
	return ar[rear];
}

void Queue::display() {
	if (front == -1) {
		return;
	}
	for (int i = front; i <= rear; i++)
	{
		std::cout << ar[i]->x << "   " << ar[i]->y << "   " << ar[i]->g + ar[i]->h << "\n";
	}
}