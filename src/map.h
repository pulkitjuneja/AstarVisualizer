#pragma once
#include "mh.h"
#include "Astar.h"

class Map :public GameObject
{
	int state;
	int gset = 0, sset = 0;
	node* final;
	Astar pathfinder;
	sf::RectangleShape ** map;
public:
	Map();
	void update(sf::RenderWindow* window);
	void render(sf::RenderWindow* window);
	void displayarray()
	{
		system("CLS");
		for (int i = 0; i < mapwidth; i++)
		{
			std::cout << "\n";
			for (int j = 0; j < mapheight; j++)
			{
				std::cout << mapar[i][j] << "-";
			}
		}std::cout << "\n\n\n\n";
	}
};
Map::Map()
{
	map = new sf::RectangleShape*[mapwidth];
	state = 1;
	for (int i = 0; i < mapwidth; i++)
	{
		for (int j = 0; j < mapheight; j++)
		{
			mapar[i][j] = 0;
		}
	}
	for (int i = 0; i < mapwidth; i++)
	{
		map[i] = new sf::RectangleShape[mapheight];
		for (int j = 0; j < mapheight; j++)
		{
			map[i][j].setOutlineColor(sf::Color::Blue);
			map[i][j].setOutlineThickness(2);
			map[i][j].setSize(sf::Vector2<float>(32,32));
			map[i][j].setPosition(sf::Vector2f(j * 32, i * 32));
		}
	}
}
void Map::update(sf::RenderWindow* window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (sset != 0)return;
		state = 2; 
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
	{
		if(gset != 0)return;
		state = 3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
	{
		pathfinder.calculate();
		if (pathfinder.closedlist.empty())return;
		final = pathfinder.closedlist.pop_back();
		state = -7;
	}
	if (state == -7)
	{
		if (!pathfinder.closedlist.empty())
		{
			node * v = pathfinder.closedlist.pop();
			mapar[v->x][v->y] = 4;
			map[v->x][v->y].setFillColor(sf::Color::Color(v->h*5, v->g*5,0, 255));
			sf::sleep(sf::milliseconds(100));
		}
		else if(!final->issame(pathfinder.getgoal()))
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
		mapar[final->x][final->y] = 3;
		map[final->x][final->y].setFillColor(sf::Color::Red);
		final = final->parent;
		sf::sleep(sf::milliseconds(100));
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (state == 0)return;
		for (int i = 0; i < mapwidth; i++)
		{
			for (int j = 0; j < mapheight; j++)
			{
				if (map[i][j].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window))))
				{
					if (mapar[i][j] != 0)return;
					mapar[i][j] = state;
					switch (state)
					{
					case 1:map[i][j].setFillColor(sf::Color::Blue); break;
					case 2:map[i][j].setFillColor(sf::Color::Green); pathfinder.setstart(i, j); sset = 1; state = 1; break;
					case 3:map[i][j].setFillColor(sf::Color::Red); pathfinder.setgoal(i, j); gset = 1; state = 1; break;
					}
					displayarray();
				}
			}
		}
	}
}
void Map::render(sf::RenderWindow* window)
{
	for (int i = 0; i < mapwidth; i++)
	{
		for (int j = 0; j < mapheight; j++)
		{
			window->draw(map[i][j]);
		}
	}

}
