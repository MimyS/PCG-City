#pragma once
#include "Utils.hpp"

template<bool isTransparent, bool isMirror>
class BuildingsClass{
	GLfloat size;
	Vertex2D position;
	string wallTexture;
	static const string floorTexture;
	static const string roofTexture;
	void drawWalls();
	void drawFloor();
	void drawRoof();
	
public:
	void draw();
	BuildingsClass(Vertex2D, GLfloat, string);
	~BuildingsClass();
};

template<bool isTransparent, bool isMirror>
void BuildingsClass<isTransparent, isMirror>::draw(){

	drawFloor();
	drawWalls();
	drawRoof();

}

template<bool isTransparent, bool isMirror>
const string BuildingsClass<isTransparent, isMirror>::floorTexture = "../Texture/BuildingFloor.jpg";
template<bool isTransparent, bool isMirror>
const string BuildingsClass<isTransparent, isMirror>::roofTexture = "../Texture/BuildingRoof.jpg";

template<bool isTransparent, bool isMirror>
void BuildingsClass<isTransparent, isMirror>::drawFloor(){
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	Mat img = imread(floorTexture);
	flip(img, img, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.cols, img.rows, 0, GL_BGR, GL_UNSIGNED_BYTE, img.ptr());

 	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	if(isTransparent){
		glEnable(GL_BLEND);
		glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA);
		GLfloat kd1[] = { 0.8f,0.8f,0.8f,0.5f };
		GLfloat ks1[] = { 0.8f,0.8f,0.8,0.5f };
		GLfloat ns1 = 60.0f;

		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, kd1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, ks1);
		glMaterialf(GL_FRONT, GL_SHININESS, ns1);
		glMatrixMode(GL_MODELVIEW);
		glColor4f(1.0f,1.0f,1.0f,0.5f);
	}
	glTranslated(position.x-0.5f, position.y-0.5f, 0.005f);
	glBegin(GL_QUADS);
	    glTexCoord2f(0.0, 1.0); glVertex2f(0.0f, 0.0f);
	    glTexCoord2f(0.0, 0.0); glVertex2f(0.0f, 1.0f);
	    glTexCoord2f(1.0, 0.0); glVertex2f(1.0f, 1.0f);
	    glTexCoord2f(1.0, 1.0); glVertex2f(1.0f, 0.0f);
	glEnd();
	if(isTransparent){
		glDisable(GL_BLEND);
	}
	glDisable(GL_TEXTURE_2D);   
	glPopMatrix();
}

template<bool isTransparent, bool isMirror>
void BuildingsClass<isTransparent, isMirror>::drawRoof(){
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	Mat img = imread(roofTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.cols, img.rows, 0, GL_BGR, GL_UNSIGNED_BYTE, img.ptr());

 	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	if(isTransparent){
		glEnable(GL_BLEND);
		glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA);
		GLfloat kd1[] = { 0.8f,0.8f,0.8f,0.5f };
		GLfloat ks1[] = { 0.8f,0.8f,0.8,0.5f };
		GLfloat ns1 = 60.0f;

		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, kd1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, ks1);
		glMaterialf(GL_FRONT, GL_SHININESS, ns1);
		glMatrixMode(GL_MODELVIEW);
		glColor4f(1.0f,1.0f,1.0f,0.5f);
	}
	glTranslated(position.x-0.5f, position.y-0.5f, size);
	glBegin(GL_QUADS);
	    glTexCoord2f(0.0, 1.0); glVertex2f(0.0f, 0.0f);
	    glTexCoord2f(0.0, 0.0); glVertex2f(0.0f, 1.0f);
	    glTexCoord2f(1.0, 0.0); glVertex2f(1.0f, 1.0f);
	    glTexCoord2f(1.0, 1.0); glVertex2f(1.0f, 0.0f);
	glEnd();
	if(isTransparent){
		glDisable(GL_BLEND);
	}
	glDisable(GL_TEXTURE_2D);   
	glPopMatrix();
}

template<bool isTransparent, bool isMirror>
void BuildingsClass<isTransparent, isMirror>::drawWalls(){
	glEnable(GL_TEXTURE_2D);
	Mat img = imread(wallTexture);
	rotate(img, img, ROTATE_180);
	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.cols, img.rows, 0, GL_BGR, GL_UNSIGNED_BYTE, img.ptr());

 	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	if(isTransparent){
		glEnable(GL_BLEND);
		glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA);
		GLfloat kd1[] = { 0.8f,0.8f,0.8f,0.5f };
		GLfloat ks1[] = { 0.8f,0.8f,0.8,0.5f };
		GLfloat ns1 = 60.0f;

		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, kd1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, ks1);
		glMaterialf(GL_FRONT, GL_SHININESS, ns1);
		glMatrixMode(GL_MODELVIEW);
		glColor4f(1.0f,1.0f,1.0f,0.5f);
	}

	// wall 1

	glPushMatrix();
	glTranslatef(position.x - 0.5f, position.y - 0.5f, 0.0f);
	glRotatef(90.0, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	    glTexCoord2f(0.0, size); glVertex2d(0.0f, size);
	    glTexCoord2f(1.0, size); glVertex2d(1.0f, size);
	    glTexCoord2f(1.0, 0.0); glVertex2d(1.0f, 0.0f);
	    glTexCoord2f(0.0, 0.0); glVertex2d(0.0f, 0.0f);
	glEnd();
	glPopMatrix();

	// wall 3

	glPushMatrix();
	glTranslatef(position.x - 0.5f,position.y + 0.5f,0.0f);
	glRotatef(90.0, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	    glTexCoord2f(0.0, size); glVertex2d(0.0f, size);
	    glTexCoord2f(1.0, size); glVertex2d(1.0f, size);
	    glTexCoord2f(1.0, 0.0); glVertex2d(1.0f, 0.0f);
	    glTexCoord2f(0.0, 0.0); glVertex2d(0.0f, 0.0f);
	glEnd();
	glPopMatrix();

	// wall 2

	glPushMatrix();

	glTranslatef(position.x - 0.5f,position.y - 0.5f,0.0f);
	glRotatef(90.0, 1.0f, 0.0f, 0.0f);
	glRotatef(90.0, 0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	    glTexCoord2f(0.0, size); glVertex2d(0.0f, size);
	    glTexCoord2f(1.0, size); glVertex2d(1.0f, size);
	    glTexCoord2f(1.0, 0.0); glVertex2d(1.0f, 0.0f);
	    glTexCoord2f(0.0, 0.0); glVertex2d(0.0f, 0.0f);
	glEnd();

	glPopMatrix();

	// wall 4

	glPushMatrix();
	glTranslatef(position.x + 0.5f,position.y - 0.5f,0.0f);
	glRotatef(90.0, 1.0f, 0.0f, 0.0f);
	glRotatef(90.0, 0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	    glTexCoord2f(0.0, size); glVertex2d(0.0f, size);
	    glTexCoord2f(1.0, size); glVertex2d(1.0f, size);
	    glTexCoord2f(1.0, 0.0); glVertex2d(1.0f, 0.0f);
	    glTexCoord2f(0.0, 0.0); glVertex2d(0.0f, 0.0f);
	glEnd();
	glPopMatrix();
	
	if(isTransparent){
		glDisable(GL_BLEND);
	}
	glDisable(GL_TEXTURE_2D);   
}

template<bool isTransparent, bool isMirror>
BuildingsClass<isTransparent, isMirror>::BuildingsClass(Vertex2D pos, GLfloat height, string wall){
	position = pos;
	size = height;
	wallTexture = wall;
}

template<bool isTransparent, bool isMirror>
BuildingsClass<isTransparent, isMirror>::~BuildingsClass(){
}
