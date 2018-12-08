#pragma once

#include "Utils.hpp"

struct HouseDimension{
	// telhado side
	// telhado triangulo
	// paredes
	// ch�o
};

class HousesClass{
	Vertex2D position;
	static struct HouseDimension size;
	const static string floorTexture;
	string roofTexture;
	string houseTexture; // concate 1 at the end of the string for entrance texture and 2 to wall texture
	void drawFloor();
	void drawRoof();
	void drawWalls();
public:
	void draw();
	HousesClass(Vertex2D, string, string);
	~HousesClass();
};

