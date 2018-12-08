#pragma once

#include "Utils.hpp"

class HousesClass{
	Vertex2D position;
	const static string floorTexture;
	const static string grassTexture;
	const static string roofTexture;
	string houseTexture;
	void drawFloor();
	void drawRoof();
	void drawWalls();
	void drawGrass();
public:
	void draw();
	HousesClass(Vertex2D, string);
	~HousesClass();
};

