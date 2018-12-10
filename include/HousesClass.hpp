#pragma once

#include "Utils.hpp"

class HousesClass{
	Vertex2D position;
	GLuint floorTexture;
	GLuint grassTexture;
	GLuint roofTexture1;
	GLuint roofTexture2;
	GLuint houseTexture;
	void drawFloor();
	void drawRoof();
	void drawWalls();
	void drawGrass();
public:
	void draw();
	HousesClass(Vertex2D, GLuint, GLuint, GLuint, GLuint, GLuint);
	~HousesClass();
};

