#include "MapData.h"

MapData::MapData()
{

	mapArray = new int*[MAP_WIDTH];

	for (int i = 0; i < MAP_WIDTH; i++)
	{
		mapArray[i] = new int[MAP_HEIGHT];

		for (int j = 0; j < MAP_HEIGHT; j++)
		{
			mapArray[i][j] = 0;
		}
	}
}

void MapData::logMap()
{
	system("CLS");
	for (int i = 0; i < MAP_WIDTH; i++)
	{
		std::cout << "\n";
		for (int j = 0; j < MAP_HEIGHT; j++)
		{
			std::cout << mapArray[i][j] << "-";
		}
	}std::cout << "\n\n\n\n";
}
