#pragma once

#ifndef ASTAR_H

#include "mh.h"
#include "MapData.h"
#include "Queue.h"

class Astar
{
	QueueNode* goal;
	QueueNode *start;

	bool issafe(MapData& mapData, int x, int y);
	int g(QueueNode* parent, int x, int j);
	int heur(int x, int y);
	void getsuccessors(QueueNode* pos, std::vector<QueueNode*>& vec, MapData& mapData);

public:

	PriorityQueue openlist;
	Queue closedlist;

	Astar();
	void calculate(MapData& mapData);
	void setstart(int x, int y);
	void setgoal(int x, int y);
	QueueNode* getgoal() { return goal; }

};

#endif // !ASTAR_H




