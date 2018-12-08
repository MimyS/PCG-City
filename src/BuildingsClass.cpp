#include "BuildingsClass.hpp"

// template<bool isTransparent, bool isMirror>
// void BuildingsClass::draw(){

// 	drawFloor();
// 	drawWalls();
// 	drawRoof();

// }

// const string BuildingsClass::floorTexture = "../Texture/BuildingFloor.jpg";

// void BuildingsClass::drawFloor(){
// 	glPushMatrix();
// 	glEnable(GL_TEXTURE_2D);
// 	Mat img = imread(floorTexture);
// 	flip(img, img, 0);
// 	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.cols, img.rows, 0, GL_BGR, GL_UNSIGNED_BYTE, img.ptr());

//  	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//     glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
// 	if(isTransparent){
// 		GLfloat kd1[] = { 0.7f,0.3f,0.5f,0.5f };
// 		GLfloat ks1[] = { 0.7f,0.3f,0.5,0.5f };
// 		GLfloat ns1 = 60.0f;

// 		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, kd1);
// 		glMaterialfv(GL_FRONT, GL_SPECULAR, ks1);
// 		glMaterialf(GL_FRONT, GL_SHININESS, ns1);
// 		glMatrixMode(GL_MODELVIEW);
// 		glColor4f(1.0f,1.0f,1.0f,0.5f);
// 	}
// 	glTranslated(position.x-0.5f, position.y-0.5f, 0.0f);
// 	glBegin(GL_QUADS);
// 	    glTexCoord2f(0.0, 1.0); glVertex2f(0.0f, 0.0f);
// 	    glTexCoord2f(0.0, 0.0); glVertex2f(0.0f, 1.0f);
// 	    glTexCoord2f(1.0, 0.0); glVertex2f(1.0f, 1.0f);
// 	    glTexCoord2f(1.0, 1.0); glVertex2f(1.0f, 0.0f);
// 	glEnd();
// 	glDisable(GL_TEXTURE_2D);   
// 	glPopMatrix();
// }

// void BuildingsClass::drawRoof(){
// 	glPushMatrix();
// 	glTranslated(position.x-0.5f, position.y-0.5f, size);
// 	glColor3f(0.6f, 0.6f, 0.6f);
// 	glBegin(GL_QUADS);
// 		glVertex2f(0.0f, 0.0f);
// 		glVertex2f(0.0f, 1.0f);
// 		glVertex2f(1.0f, 1.0f);
// 		glVertex2f(1.0f, 0.0f);
// 	glEnd();
// 	glPopMatrix();
// }

// void BuildingsClass::drawWalls(){
// 	glEnable(GL_TEXTURE_2D);
// 	Mat img = imread(wallTexture);
// 	flip(img, img, 0);
// 	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.cols, img.rows, 0, GL_BGR, GL_UNSIGNED_BYTE, img.ptr());

//  	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//     glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

// 	// wall 1
	
// 	glPushMatrix();
// 	glTranslatef(position.x - 0.5f, position.y - 0.5f, 0.0f);
// 	glRotatef(90.0, 1.0f, 0.0f, 0.0f);
// 	glBegin(GL_QUADS);
// 	    glTexCoord2f(0.0, 1.0); glVertex2d(0.0f, size);
// 	    glTexCoord2f(0.0, 0.0); glVertex2d(1.0f, size);
// 	    glTexCoord2f(1.0, 0.0); glVertex2d(1.0f, 0.0f);
// 	    glTexCoord2f(1.0, 1.0); glVertex2d(0.0f, 0.0f);
// 	glEnd();
// 	glPopMatrix();

// 	// wall 2

// 	glPushMatrix();
// 	glTranslatef(position.x - 0.5f, position.y - 0.5f, 0.0f);
// 	glRotatef(360.0-90.0, 0.0f, 1.0f, 0.0f);
// 	glBegin(GL_QUADS);
// 	    glTexCoord2f(0.0, 1.0); glVertex2d(0.0f, 1.0f);
// 	    glTexCoord2f(0.0, 0.0); glVertex2d(size, 1.0f);
// 	    glTexCoord2f(1.0, 0.0); glVertex2d(size, 0.0f);
// 	    glTexCoord2f(1.0, 1.0); glVertex2d(0.0f, 0.0f);
// 	glEnd();
// 	glPopMatrix();

// 	// wall 3

// 	glPushMatrix();
// 	glTranslatef(position.x - 0.5f,position.y + 0.5f,0.0f);
// 	glRotatef(90.0, 1.0f, 0.0f, 0.0f);
// 	glBegin(GL_QUADS);
// 	    glTexCoord2f(0.0, 1.0); glVertex2d(0.0f, size);
// 	    glTexCoord2f(0.0, 0.0); glVertex2d(1.0f, size);
// 	    glTexCoord2f(1.0, 0.0); glVertex2d(1.0f, 0.0f);
// 	    glTexCoord2f(1.0, 1.0); glVertex2d(0.0f, 0.0f);
// 	glEnd();
// 	glPopMatrix();

// 	// wall 4

// 	glPushMatrix();
// 	glTranslatef(position.x + 0.5f,position.y - 0.5f,0.0f);
// 	glRotatef(360.0-90.0, 0.0f, 1.0f, 0.0f);
// 	glBegin(GL_QUADS);
// 	    glTexCoord2f(0.0, 1.0); glVertex2d(0.0f, 1.0f);
// 	    glTexCoord2f(0.0, 0.0); glVertex2d(size, 1.0f);
// 	    glTexCoord2f(1.0, 0.0); glVertex2d(size, 0.0f);
// 	    glTexCoord2f(1.0, 1.0); glVertex2d(0.0f, 0.0f);
// 	glEnd();
// 	glPopMatrix();
// 	glDisable(GL_TEXTURE_2D);   
// }


// BuildingsClass::BuildingsClass(Vertex2D pos, GLfloat height, string wall){
// 	position = pos;
// 	size = height;
// 	wallTexture = wall;
// 	// isMirror = mirror;
// 	// isTransparent = transp;
// }


// BuildingsClass::~BuildingsClass(){
// }
