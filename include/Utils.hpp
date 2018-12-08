#pragma once

#include <GL/glut.h>
#include <math.h>
#include<opencv2/opencv.hpp>
#include <string>
#include <vector>
#include<iostream>
#include<utility>
const double pi = 3.1415926535897; 
using namespace std;
using namespace cv;

#define SIZE_GAUSSIAN 40

typedef struct{
	GLfloat x;
	GLfloat y;
	GLfloat z;
} Vertex3D;

typedef struct{
	GLfloat x;
	GLfloat y;
} Vertex2D;

typedef struct{
	Vertex3D point;
	Vertex3D normal;
} Cell;

extern Cell gaussian[SIZE_GAUSSIAN + 2][SIZE_GAUSSIAN + 2];

Vertex3D crossproduct(Vertex3D a, Vertex3D b);

Vertex3D normalize(Vertex3D p);

void calcNormal();

void criaGaussiana();
