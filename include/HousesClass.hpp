#pragma once

#include "Utils.hpp"

class HousesClass{
	Vertex2D position;
	const static GLuint floorTextureID;
	const static GLuint grassTextureID;
	GLuint roofTextureID1;
	GLuint roofTextureID2;
	GLuint houseTextureID;
	void drawFloor();
	void drawRoof();
	void drawWalls();
	void drawGrass();
public:
	void draw();
	HousesClass(Vertex2D, GLuint, GLuint, GLuint);
	~HousesClass();
};

