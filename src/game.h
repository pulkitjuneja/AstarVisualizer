#pragma once
#include "mh.h"
#include "map.h"
#include "vector.h"


class Game
{
	sf::RenderWindow* window;
	GameObject* gameobjects;
	bool playing=true;
public:
	Game();
	void update();
	void render();
	void run();
};

Game::Game()
{
	window = new sf::RenderWindow(sf::VideoMode(width, height), "A*");
	gameobjects = new Map();
}
void Game::update()
{
	if (playing)
	{

		gameobjects->update(window);
	}
}
void Game::render()
{
	gameobjects->render(window);
}
void Game::run()
{
	sf::Event event;
	while (window->isOpen())
	{
		while(window->pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::P)
				{
					playing = !playing;
				}
			}
		}
		window->clear();
		update();
		render();
		window->display();
	}
}