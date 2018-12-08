#include "HousesClass.hpp"

const string HousesClass::floorTexture = "../Texture/BuildingFloor2.jpg";

void HousesClass::draw(){
    drawRoof();
    drawWalls();
    drawFloor();
}

HousesClass::HousesClass(Vertex2D pos, string roofText, string houseText){
    position = pos;
    roofTexture = roofText;
    houseTexture = houseText;
}


HousesClass::~HousesClass(){
}

void HousesClass::drawFloor(){
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	Mat img = imread(floorTexture);
	flip(img, img, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.cols, img.rows, 0, GL_BGR, GL_UNSIGNED_BYTE, img.ptr());

 	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTranslated(position.x-0.5f, position.y-0.5f, 0.0f);
	glBegin(GL_QUADS);
	    glTexCoord2f(0.0, 1.0); glVertex2f(0.0f, 0.0f);
	    glTexCoord2f(0.0, 0.0); glVertex2f(0.0f, 1.0f);
	    glTexCoord2f(1.0, 0.0); glVertex2f(1.0f, 1.0f);
	    glTexCoord2f(1.0, 1.0); glVertex2f(1.0f, 0.0f);
	glEnd();

	glDisable(GL_TEXTURE_2D);   
	glPopMatrix();
}

void HousesClass::drawRoof(){
    glEnable(GL_TEXTURE_2D);
	Mat img = imread(roofTexture);
	flip(img, img, 0);
	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.cols, img.rows, 0, GL_BGR, GL_UNSIGNED_BYTE, img.ptr());

 	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glPushMatrix();
    glTranslatef(position.x-0.5f,position.y, 1.0 + tan(45*pi/180)*0.5);
	glRotatef(-135.0, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	    glTexCoord2f(0.0, 1.0); glVertex2d(0.0f, 0.5/cos(45*pi/180.0));
	    glTexCoord2f(0.0, 0.0); glVertex2d(1.0f, 0.5/cos(45*pi/180.0));
	    glTexCoord2f(1.0, 0.0); glVertex2d(1.0f, 0.0f);
	    glTexCoord2f(1.0, 1.0); glVertex2d(0.0f, 0.0f);
	glEnd();
	glPopMatrix();

    glPushMatrix();
    glTranslatef(position.x-0.5f,position.y, 1.0 + tan(45*pi/180.0)*0.5);
	glRotatef(-45.0, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	    glTexCoord2f(0.0, 1.0); glVertex2d(0.0f, 0.5/cos(45*pi/180.0));
	    glTexCoord2f(0.0, 0.0); glVertex2d(1.0f, 0.5/cos(45*pi/180.0));
	    glTexCoord2f(1.0, 0.0); glVertex2d(1.0f, 0.0f);
	    glTexCoord2f(1.0, 1.0); glVertex2d(0.0f, 0.0f);
	glEnd();
	glPopMatrix();

    glColor3f(191/255.0f,62/255.0f,46/255.0f);

    glPushMatrix();
	glTranslatef(position.x - 0.5f, position.y - 0.5f, 1.0f);
	glRotatef(90.0, 0.0f, 1.0f, 0.0f);
	glRotatef(90.0, 0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLE_STRIP);
	    glVertex2d(1.0f, 0.0f);
	    glVertex2d(0.0f, 0.0f);
	    glVertex2d(0.5f, tan(45*pi/180.0)*0.5);
	glEnd();
	glPopMatrix();

    glPushMatrix();
	glTranslatef(position.x + 0.5f, position.y - 0.5f, 1.0f);
	glRotatef(90.0, 0.0f, 1.0f, 0.0f);
	glRotatef(90.0, 0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLE_STRIP);
	    glVertex2d(1.0f, 0.0f);
	    glVertex2d(0.0f, 0.0f);
	    glVertex2d(0.5f, tan(45*pi/180.0)*0.5);
	glEnd();
	glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

void HousesClass::drawWalls(){
    glEnable(GL_TEXTURE_2D);
	Mat img = imread(houseTexture);
	// flip(img, img, 0);
	rotate(img, img, ROTATE_180);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.cols, img.rows, 0, GL_BGR, GL_UNSIGNED_BYTE, img.ptr());
 	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// wall 1 - down

	glPushMatrix();
	glTranslatef(position.x - 0.5f, position.y - 0.5f, 0.0f);
	glRotatef(90.0, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	    glTexCoord2f(0.0, 1.0); glVertex2d(0.0f, 1.0f);
	    glTexCoord2f(1.0, 1.0); glVertex2d(1.0f, 1.0f);
	    glTexCoord2f(1.0, 0.0); glVertex2d(1.0f, 0.0f);
	    glTexCoord2f(0.0, 0.0); glVertex2d(0.0f, 0.0f);
	glEnd();
	glPopMatrix();

	// wall 3 - up

	glPushMatrix();
	glTranslatef(position.x - 0.5f,position.y + 0.5f,0.0f);
	glRotatef(90.0, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	    glTexCoord2f(0.0, 1.0); glVertex2d(0.0f, 1.0f);
	    glTexCoord2f(1.0, 1.0); glVertex2d(1.0f, 1.0f);
	    glTexCoord2f(1.0, 0.0); glVertex2d(1.0f, 0.0f);
	    glTexCoord2f(0.0, 0.0); glVertex2d(0.0f, 0.0f);
	glEnd();
	glPopMatrix();

	rotate(img, img, ROTATE_180);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.cols, img.rows, 0, GL_BGR, GL_UNSIGNED_BYTE, img.ptr());
 	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// wall 2 - left
	
	glPushMatrix();
	glTranslatef(position.x - 0.5f, position.y - 0.5f, 0.0f);
	glRotatef(360.0-90.0, 0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	    glTexCoord2f(0.0, 1.0); glVertex2d(0.0f, 1.0f);
	    glTexCoord2f(0.0, 0.0); glVertex2d(1.0f, 1.0f);
	    glTexCoord2f(1.0, 0.0); glVertex2d(1.0f, 0.0f);
	    glTexCoord2f(1.0, 1.0); glVertex2d(0.0f, 0.0f);
	glEnd();
	glPopMatrix();

	// wall 4 - right

	glPushMatrix();
	glTranslatef(position.x + 0.5f,position.y - 0.5f,0.0f);
	glRotatef(360.0-90.0, 0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	    glTexCoord2f(0.0, 1.0); glVertex2d(0.0f, 1.0f);
	    glTexCoord2f(0.0, 0.0); glVertex2d(1.0f, 1.0f);
	    glTexCoord2f(1.0, 0.0); glVertex2d(1.0f, 0.0f);
	    glTexCoord2f(1.0, 1.0); glVertex2d(0.0f, 0.0f);
	glEnd();
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);   
}