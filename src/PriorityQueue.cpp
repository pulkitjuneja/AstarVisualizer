#include "priorityqueue.h"

PriorityQueue::PriorityQueue()
{
	ar = new QueueNode*[500];
	size = 0;
}
void PriorityQueue::push(QueueNode* val)
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
		for (int j = size; j > i; j--)
			ar[j] = ar[j - 1];
		ar[i] = val;
		size++;
	}
}

QueueNode* PriorityQueue::operator[](int index)
{
	if (index < 0 || index >= size)return NULL;
	return ar[index];
}
void PriorityQueue::display()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << ar[i]->x << "   " << ar[i]->y << "   " << ar[i]->g << " " << ar[i]->h << "\n";
	}
}
void PriorityQueue::remove(QueueNode* nod)
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
void PriorityQueue::removeat(int index)
{
	if (index > size || index < 0)return;
	delete ar[index];
	for (int j = index; j < size - 1; j++)
		ar[j] = ar[j + 1];
	size--;
}
int PriorityQueue::indexof(QueueNode* nod)
{
	for (int i = 0; i < size; i++)
	{
		if (ar[i]->issame(nod))
			return i;
	}
	return -1;
}
void PriorityQueue::clear()
{
	delete[] ar;
	ar = new QueueNode*[500];
	size = 0;
}

bool PriorityQueue::empty()
{
	return size > 0 ? false : true;
}

QueueNode* PriorityQueue::pop()
{
	return ar[size-- - 1];
}

QueueNode* PriorityQueue::peek()
{
	return ar[size - 1];
}