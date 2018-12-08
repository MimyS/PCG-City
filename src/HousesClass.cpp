#include "HousesClass.hpp"

const string HousesClass::floorTexture = "../Texture/BuildingFloor2.jpg";
const string HousesClass::grassTexture = "../Texture/grass.jpg";
const string HousesClass::roofTexture = "../Texture/HouseRoof.jpg";

void HousesClass::draw(){
    drawRoof();
    drawWalls();
    drawFloor();
	drawGrass();
}

HousesClass::HousesClass(Vertex2D pos, string houseText){
    position = pos;
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

	glTranslated(position.x-0.5f, position.y-0.5f, 0.05f);
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
	{
		glTranslated(position.x, position.y, 0.0);
		
		glBegin(GL_QUADS);
			// up - trapeze
			glTexCoord2d(-0.5, 1.0);	glVertex3d(-0.5, 0.5, 1.0);
			glTexCoord2d(-0.2, 1.7);	glVertex3d(-0.2, 0.0, 1.7);
			glTexCoord2d(0.2, 1.7);	glVertex3d( 0.2, 0.0, 1.7);
			glTexCoord2d(0.5, 1.0);	glVertex3d( 0.5, 0.5, 1.0);
			// down - trapeze
			glTexCoord2d(-0.5, 1.0);	glVertex3d(-0.5, -0.5, 1.0);
			glTexCoord2d(-0.2, 1.7);	glVertex3d(-0.2,  0.0, 1.7);
			glTexCoord2d(0.2, 1.7);	glVertex3d( 0.2,  0.0, 1.7);
			glTexCoord2d(0.5, 1.0);	glVertex3d( 0.5, -0.5, 1.0);
		glEnd();
	}
	glPopMatrix();
	
	rotate(img, img, ROTATE_90_CLOCKWISE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.cols, img.rows, 0, GL_BGR, GL_UNSIGNED_BYTE, img.ptr());

 	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glPushMatrix();
	{
		glTranslated(position.x, position.y, 0.0f);

		glBegin(GL_TRIANGLE_STRIP);
			glTexCoord2d(-0.5,-0.5);	glVertex3d(-0.5,-0.5, 1.0);
			glTexCoord2d(-0.2, 0.0);	glVertex3d(-0.2, 0.0, 1.7);
			glTexCoord2d(-0.5, 0.5);	glVertex3d(-0.5, 0.5, 1.0);
			
			glTexCoord2d(-0.5,-0.5);	glVertex3d( 0.5,-0.5, 1.0);
			glTexCoord2d(-0.2, 0.0);	glVertex3d( 0.2, 0.0, 1.7);
			glTexCoord2d(-0.5, 0.5);	glVertex3d( 0.5, 0.5, 1.0);
		glEnd();
	}
	glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void HousesClass::drawWalls(){
    glEnable(GL_TEXTURE_2D);
	Mat img = imread(houseTexture);
	rotate(img, img, ROTATE_180);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.cols, img.rows, 0, GL_BGR, GL_UNSIGNED_BYTE, img.ptr());
 	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glPushMatrix();
	{
		glTranslated(position.x - 0.5, position.y - 0.5, 0.0);

		glBegin(GL_QUADS);

			// wall 1 - down
			glTexCoord2d(0.0, 1.0);	glVertex3d(0.0, 0.0, 1.0);
			glTexCoord2d(1.0, 1.0);	glVertex3d(1.0, 0.0, 1.0);
			glTexCoord2d(1.0, 0.0);	glVertex3d(1.0, 0.0, 0.0);
			glTexCoord2d(0.0, 0.0);	glVertex3d(0.0, 0.0, 0.0);
			// wall 2 - left
			glTexCoord2d(0.0, 1.0);	glVertex3d(0.0, 0.0, 1.0);
			glTexCoord2d(1.0, 1.0);	glVertex3d(0.0, 1.0, 1.0);
			glTexCoord2d(1.0, 0.0);	glVertex3d(0.0, 1.0, 0.0);
			glTexCoord2d(0.0, 0.0);	glVertex3d(0.0, 0.0, 0.0);
			// wall 3 - up
			glTexCoord2d(0.0, 1.0);	glVertex3d(0.0, 1.0, 1.0);
			glTexCoord2d(1.0, 1.0);	glVertex3d(1.0, 1.0, 1.0);
			glTexCoord2d(1.0, 0.0);	glVertex3d(1.0, 1.0, 0.0);
			glTexCoord2d(0.0, 0.0);	glVertex3d(0.0, 1.0, 0.0);
			// wall 4 - right
			glTexCoord2d(0.0, 1.0);	glVertex3d(1.0, 0.0, 1.0);
			glTexCoord2d(1.0, 1.0);	glVertex3d(1.0, 1.0, 1.0);
			glTexCoord2d(1.0, 0.0);	glVertex3d(1.0, 1.0, 0.0);
			glTexCoord2d(0.0, 0.0);	glVertex3d(1.0, 0.0, 0.0);

		glEnd();
	}
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);   
}

void HousesClass::drawGrass(){
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	Mat img = imread(grassTexture);
	flip(img, img, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.cols, img.rows, 0, GL_BGR, GL_UNSIGNED_BYTE, img.ptr());

 	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTranslated(position.x-0.75f, position.y-0.75f, 0.025f);
	glBegin(GL_QUADS);
	    glTexCoord2f(0.0, 0.0); glVertex2f(0.0f, 0.0f);
	    glTexCoord2f(0.0, 1.5); glVertex2f(0.0f, 1.5f);
	    glTexCoord2f(1.5, 1.5); glVertex2f(1.5f, 1.5f);
	    glTexCoord2f(1.5, 0.0); glVertex2f(1.5f, 0.0f);
	glEnd();

	glDisable(GL_TEXTURE_2D);   
	glPopMatrix();
}