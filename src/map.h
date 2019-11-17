#pragma once

#ifndef MAP_H

#include "mh.h"
#include "Astar.h"
#include "MapData.h"

class Map :public Entity
{
	int state;
	int isGoalSet = 0, isSourceSet = 0;
	QueueNode* final;
	Astar pathfinder;
	MapData mapData;
	sf::RectangleShape ** map;

public:

	Map();
	void update(sf::RenderWindow* window);
	void render(sf::RenderWindow* window);
};

Map::Map()
{
	map = new sf::RectangleShape*[mapData.MAP_WIDTH];
	state = 1;

	for (int i = 0; i < mapData.MAP_WIDTH; i++)
	{
		map[i] = new sf::RectangleShape[mapData.MAP_HEIGHT];
		for (int j = 0; j < mapData.MAP_HEIGHT; j++)
		{
			map[i][j].setOutlineColor(sf::Color::Blue);
			map[i][j].setOutlineThickness(2);
			map[i][j].setSize(sf::Vector2<float>(32, 32));
			map[i][j].setPosition(sf::Vector2f(j * 32, i * 32));
		}
	}
}
void Map::update(sf::RenderWindow* window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (isSourceSet != 0)return;
		state = 2;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
	{
		if (isGoalSet != 0)return;
		state = 3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
	{
		pathfinder.calculate(mapData);
		if (pathfinder.closedlist.empty()) {
			return;
		};
		final = pathfinder.closedlist.pop_back();
		state = -7;
	}
	if (state == -7)
	{
		if (!pathfinder.closedlist.empty())
		{
			QueueNode * v = pathfinder.closedlist.pop();
			mapData.mapArray[v->x][v->y] = 4;
			map[v->x][v->y].setFillColor(sf::Color::Color(v->h * 5, v->g * 5, 0, 255));
			sf::sleep(sf::milliseconds(100));
		}
		else if (!final->issame(pathfinder.getgoal()))
		{
			std::cout << "maze unsolvable";
			state = 0;
			return;
		}
		else
		{
			state = -2;
		}
	}
	if (state == -2 && final != NULL)
	{
		mapData.mapArray[final->x][final->y] = 3;
		map[final->x][final->y].setFillColor(sf::Color::Red);
		final = final->parent;
		sf::sleep(sf::milliseconds(100));
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (state == 0)return;
		for (int i = 0; i < mapData.MAP_WIDTH; i++)
		{
			for (int j = 0; j < mapData.MAP_HEIGHT; j++)
			{
				if (map[i][j].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window))))
				{
					if (mapData.mapArray[i][j] != 0)return;
					mapData.mapArray[i][j] = state;
					switch (state)
					{
					case 1:map[i][j].setFillColor(sf::Color::Blue); break;
					case 2:map[i][j].setFillColor(sf::Color::Green); pathfinder.setstart(i, j); isSourceSet = 1; state = 1; break;
					case 3:map[i][j].setFillColor(sf::Color::Red); pathfinder.setgoal(i, j); isGoalSet = 1; state = 1; break;
					}
					mapData.logMap();
				}
			}
		}
	}
}
void Map::render(sf::RenderWindow* window)
{
	for (int i = 0; i < mapData.MAP_WIDTH; i++)
	{
		for (int j = 0; j < mapData.MAP_HEIGHT; j++)
		{
			window->draw(map[i][j]);
		}
	}

}

#endif // !MAP_H
