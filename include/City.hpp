#pragma once

#include<GL/glut.h>
#include<iostream>
#include "ControlClass.hpp"
#include "LightClass.hpp"
#include "BuildingsClass.hpp"
#include "HousesClass.hpp"

/**GLOBAL**/
extern ViewClass viewC;
extern ControlClass control;

void Init();
void drawScene();
void drawCityFloor();
void drawLandscape();
void windowReshapeFunc(GLsizei, GLsizei);
void animate();
void keyboard(unsigned char key, int x, int y);
void keyboard_special(int key, int x, int y);