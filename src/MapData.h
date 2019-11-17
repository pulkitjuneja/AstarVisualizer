#pragma once

#ifndef MAPDATA_H

#include "mh.h"

struct MapData {

	int** mapArray;
	const int MAP_WIDTH = 19;
	const int MAP_HEIGHT = 25;

	MapData();
	void logMap();

};

#endif // !MAPDATA_H