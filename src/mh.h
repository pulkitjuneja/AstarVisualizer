#pragma once 



#include<SFML/Graphics.hpp>
#include<iostream>
#include<conio.h>
#include<queue>
#include "vector.h"
#include "priorityqueue.h"

const int mapwidth = 19;
const int mapheight = 25;
int mapar[mapwidth][mapheight];

#define width 800
#define height 600 

class GameObject
{
public:
	virtual void update(sf::RenderWindow* window) = 0;
	virtual void render(sf::RenderWindow* window) = 0;
};