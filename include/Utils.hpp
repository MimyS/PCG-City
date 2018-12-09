#pragma once

#include <GL/glut.h>
#include <math.h>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>  

const double pi = 3.1415926535897; 
using namespace std;
using namespace cv;

#define SIZE_GAUSSIAN 40

#define SET_TEXTURE_PARAM(img) 	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.cols, img.rows, 0, GL_BGR, GL_UNSIGNED_BYTE, img.ptr());\
 	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);\
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);\
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);\
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

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
