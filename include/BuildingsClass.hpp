#pragma once
#include "Utils.hpp"

template<bool isTransparent, bool isMirror>
class BuildingsClass{
	GLfloat size;
	Vertex2D position;
	string wallTexture;
	static const string floorTexture;
	static const string roofTexture;
	void drawWalls(LightClass & light);
	void drawFloor(LightClass & light);
	void drawRoof(LightClass & light);
	
public:
	void draw(LightClass &);
	BuildingsClass(Vertex2D, GLfloat, string);
	~BuildingsClass();
};

template<bool isTransparent, bool isMirror>
void BuildingsClass<isTransparent, isMirror>::draw(LightClass & light){

	drawFloor(light);
	drawWalls(light);
	drawRoof(light);

}

template<bool isTransparent, bool isMirror>
const string BuildingsClass<isTransparent, isMirror>::floorTexture = "../Texture/BuildingFloor.jpg";
template<bool isTransparent, bool isMirror>
const string BuildingsClass<isTransparent, isMirror>::roofTexture = "../Texture/BuildingRoof.jpg";

template<bool isTransparent, bool isMirror>
void BuildingsClass<isTransparent, isMirror>::drawFloor(LightClass & light){
	glEnable(GL_TEXTURE_2D);
	Mat img = imread(floorTexture);
	flip(img, img, 0);
	SET_TEXTURE_PARAM(img)
	
	if(isTransparent){
		light.transparentMaterial();
	}else if(isMirror){
		light.reflectiveMaterial();
	}

	glPushMatrix();
	glTranslated(position.x-0.5f, position.y-0.5f, 0.005f);
	glBegin(GL_QUADS);
	    glTexCoord2f(0.0, 1.0); glVertex2f(0.0f, 0.0f);
	    glTexCoord2f(0.0, 0.0); glVertex2f(0.0f, 1.0f);
	    glTexCoord2f(1.0, 0.0); glVertex2f(1.0f, 1.0f);
	    glTexCoord2f(1.0, 1.0); glVertex2f(1.0f, 0.0f);
	glEnd();
	glPopMatrix();

	if(isTransparent||isMirror){
		light.basicMaterial();
	}
	glDisable(GL_TEXTURE_2D);   
}

template<bool isTransparent, bool isMirror>
void BuildingsClass<isTransparent, isMirror>::drawRoof(LightClass & light){
	glEnable(GL_TEXTURE_2D);
	Mat img = imread(roofTexture);
	SET_TEXTURE_PARAM(img)

	if(isTransparent){
		light.transparentMaterial();
	}else if(isMirror){
		light.reflectiveMaterial();
	}

	glPushMatrix();
	glTranslated(position.x-0.5f, position.y-0.5f, size);
	glBegin(GL_QUADS);
	    glTexCoord2f(0.0, 1.0); glVertex2f(0.0f, 0.0f);
	    glTexCoord2f(0.0, 0.0); glVertex2f(0.0f, 1.0f);
	    glTexCoord2f(1.0, 0.0); glVertex2f(1.0f, 1.0f);
	    glTexCoord2f(1.0, 1.0); glVertex2f(1.0f, 0.0f);
	glEnd();
	glPopMatrix();

	if(isTransparent||isMirror){
		light.basicMaterial();
	}
	glDisable(GL_TEXTURE_2D);   
}

template<bool isTransparent, bool isMirror>
void BuildingsClass<isTransparent, isMirror>::drawWalls(LightClass & light){
	glEnable(GL_TEXTURE_2D);
	Mat img = imread(wallTexture);
	rotate(img, img, ROTATE_180);
	SET_TEXTURE_PARAM(img)

	if(isTransparent){
		light.transparentMaterial();
	}else if(isMirror){
		light.reflectiveMaterial();
	}

	glPushMatrix();
	{
		glTranslated(position.x - 0.5, position.y - 0.5, 0.0);

		glBegin(GL_QUADS);
		// wall 1 - down
		glTexCoord2d(0.0, size);	glVertex3d(0.0, 0.0, size);
		glTexCoord2d(1.0, size);	glVertex3d(1.0, 0.0, size);
		glTexCoord2d(1.0, 0.0);		glVertex3d(1.0, 0.0, 0.0);
		glTexCoord2d(0.0, 0.0);		glVertex3d(0.0, 0.0, 0.0);
		// wall 2 - left
		glTexCoord2d(0.0, size);	glVertex3d(0.0, 0.0, size);
		glTexCoord2d(1.0, size);	glVertex3d(0.0, 1.0, size);
		glTexCoord2d(1.0, 0.0);		glVertex3d(0.0, 1.0, 0.0);
		glTexCoord2d(0.0, 0.0);		glVertex3d(0.0, 0.0, 0.0);
		// wall 3 - up
		glTexCoord2d(0.0, size);	glVertex3d(0.0, 1.0, size);
		glTexCoord2d(1.0, size);	glVertex3d(1.0, 1.0, size);
		glTexCoord2d(1.0, 0.0);		glVertex3d(1.0, 1.0, 0.0);
		glTexCoord2d(0.0, 0.0);		glVertex3d(0.0, 1.0, 0.0);
		// wall 4 - right
		glTexCoord2d(0.0, size);	glVertex3d(1.0, 0.0, size);
		glTexCoord2d(1.0, size);	glVertex3d(1.0, 1.0, size);
		glTexCoord2d(1.0, 0.0);		glVertex3d(1.0, 1.0, 0.0);
		glTexCoord2d(0.0, 0.0);		glVertex3d(1.0, 0.0, 0.0);

		glEnd();
	}
	glPopMatrix();
	
	if(isTransparent||isMirror){
		light.basicMaterial();
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
