#pragma once
#include<iostream>
#include "mh.h"

struct node
{
	int x;
	int y;
	int h;
	int g;
	node* parent;
public:
	node(int x, int y, int h, int g,node*parent)
	{
		this->x = x;
		this->y = y;
		this->h = h;
		this->g = g;
		this->parent = parent;
	}
	int compareto(node* nod);
	bool issame(node* nod);
};

int node::compareto(node* nod)
{
	if ((nod->g + nod->h) > (g + h))
		return -1;
	else if ((nod->g + nod->h) == (g + h))
		return 0;
	else
		return 1;

}
bool node::issame(node* nod)
{
	if (this->x == nod->x&&this->y == nod->y)
		return true;
	else
		return false;
}

class priorityqueue
{
	node** ar;
public:
	int size;
	priorityqueue();
	void push(node* val);
	void remove(node* nod);
	void removeat(int index);
	int indexof(node* nod);
	node* operator[](int index);
	void display();
	void clear();
	bool empty();
	node* pop();
	node* peek();
};

priorityqueue::priorityqueue()
{
	ar = new node*[500];
	size = 0;
}
void priorityqueue::push(node* val)
{
	if (size == 499)return;
	if (size == 0)
	{
		ar[size] = val;
		size++;
		return;
	}
	else
	{
		int i = 0;
		for (; i < size; i++)
		{
			if ((val->g + val->h) > (ar[i]->g + ar[i]->h))
				break;
		}
		for (int j = size; j>i; j--)
			ar[j] = ar[j - 1];
		ar[i] = val;
		size++;
	}
}

node* priorityqueue::operator[](int index)
{
	if (index < 0 || index >= size)return NULL;
	return ar[index];
}
void priorityqueue::display()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << ar[i]->x << "   " << ar[i]->y << "   " << ar[i]->g<<" "<<ar[i]->h << "\n";
	}
}
void priorityqueue::remove(node* nod)
{
	int i = 0;
	for (; i < size; i++)
	{
		if (ar[i]->x == nod->x&&ar[i]->y == nod->y)
			break;
	}
	if (i == size)return;
	delete ar[i];
	for (int j = i; j < size - 1; j++)
		ar[j] = ar[j + 1];
	size--;
}
void priorityqueue::removeat(int index)
{
	if (index>size || index < 0)return;
	delete ar[index];
	for (int j = index; j < size - 1; j++)
		ar[j] = ar[j + 1];
	size--;
}
int priorityqueue::indexof(node* nod)
{
	for (int i = 0; i < size; i++)
	{
		if (ar[i]->issame(nod))
			return i;
	}
	return -1;
}
void priorityqueue::clear()
{
	delete[] ar;
	ar = new node*[500];
	size = 0;
}

bool priorityqueue::empty()
{
	return size > 0 ? false : true;
}

node* priorityqueue::pop()
{
	return ar[size-- - 1];
}

node* priorityqueue::peek()
{
	return ar[size - 1];
}

class queue
{
	node** ar;
	int front, rear;
public:
	queue();
	void push(node* nod);
	node* pop();
	node* pop_back();
	int indexof(node* nod);
	void clear();
	bool empty();
	void display()
	{
		if (front == -1)return;
		for (int i = front; i <= rear; i++)
		{
			std::cout << ar[i]->x << "   " << ar[i]->y << "   " << ar[i]->g + ar[i]->h << "\n";
		}
	}
};
queue::queue()
{
	ar = new node*[500];
	front = rear = -1;
}

bool queue::empty()
{
	if (front == -1)return true;
	return false;
}
void queue::push(node* nod)
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
node* queue::pop()
{
	if (front == -1)
	{
		return NULL;
	}
	else if (front == rear)
	{
		node* v = ar[front];
		front = rear = -1;
		return v;
	}
	else
	{
		return ar[front++];
	}
}

int queue::indexof(node* nod)
{
	if (front == -1)return -1;
	for (int i = front; i <= rear; i++)
	{
		if (ar[i]->issame(nod))
			return i;
	}
	return -1;
}
void queue::clear()
{
	delete[] ar;
	ar = new node*[500];
	front = rear = -1;
}

node* queue::pop_back()
{
	if (rear == -1)
		return NULL;
	return ar[rear];
}