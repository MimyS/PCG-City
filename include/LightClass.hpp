#pragma once

#include "Utils.hpp"

class LightClass{
	GLfloat position[3];
public:
	void ambient_light();
	void lighting();
	LightClass(GLfloat x, GLfloat y, GLfloat z);
	~LightClass();
};

