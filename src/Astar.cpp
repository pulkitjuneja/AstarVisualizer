#include "Astar.h"

Astar::Astar()
{
	goal = start = NULL;
}
void Astar::setstart(int x, int y)
{
	start = new QueueNode(x, y, 0, 0, NULL);
}
void Astar::setgoal(int x, int y)
{
	goal = new QueueNode(x, y, 0, 0, start);
}
void Astar::getsuccessors(QueueNode* pos, std::vector<QueueNode*>& vec, MapData& mapData)
{
	vec.clear();
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (i == 0 && j == 0)continue;
			if (issafe(mapData, pos->x + i, pos->y + j))
			{
				vec.push_back(new QueueNode(pos->x + i, pos->y + j, heur(pos->x + i, pos->y + j), g(pos, i, j), pos));
			}
		}
	}

}
bool Astar::issafe(MapData& mapData, int x, int y)
{
	if (x >= 0 && x < mapData.MAP_WIDTH && y >= 0 && y < mapData.MAP_HEIGHT && mapData.mapArray[x][y] != 1)
		return true;
	else
		return false;

}
int Astar::g(QueueNode*parent, int x, int y)
{
	if ((x == -1 || x == 1) && (y == 1 || y == -1))
	{
		return parent->g + 2;
	}
	else if (x == 0 && y == 0)
	{
		return parent->g;
	}
	else
		return parent->g + 1;
}
int Astar::heur(int x, int y)
{
	return abs(x - goal->x) + abs(y - goal->y);
}
void Astar::calculate(MapData& mapData)
{
	if (start == NULL || goal == NULL)
	{
		std::cout << "not set ";
		return;
	}
	std::vector<QueueNode*> neighbors;
	openlist.push(start);
	while (!openlist.empty())
	{
		//	system("CLS");
		//	closedlist.display();
		//	std::cout << "cl\n";
		//	std::cout << "loop start\n";
		//	openlist.display();
		//	std::cout << "op\n";
		QueueNode* parent = openlist.pop();
		//	std::cout << "parent" << parent->x << " " << parent->y << "\n";
		getsuccessors(parent, neighbors, mapData);
		//	std::cout << "getting successors\n";
		//	for (int i = 0; i < neighbors.size(); i++)
		//	std::cout << neighbors[i]->x << "  "<< neighbors[i]->y<<"  "<<neighbors[i]->g<<" "<<neighbors[i]->h<<"\n";
		//std::cout << "successors done\n";
		for (int i = 0; i < neighbors.size(); i++)
		{
			QueueNode* current = neighbors[i];
			int index = openlist.indexof(current);
			if (index != -1)
			{
				if (openlist[index]->compareto(current) > 0)
				{
					openlist.removeat(index);
					openlist.push(current);
				}
				continue;
			}
			index = closedlist.indexof(current);
			if (index != -1)
			{
				continue;
			}
			openlist.push(current);
		}
		closedlist.push(parent);
		if (parent->issame(goal))
		{//closedlist.push(parent);
			break;
		}
		//displayarray();
	}
}