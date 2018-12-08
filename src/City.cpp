#include "City.hpp"

/**GLOBAL**/
ViewClass viewC;
ControlClass control;
LightClass light(-10.0f, -10.0f, 25.0f);

using namespace std;

void drawScene(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(173/255.0, 213/255.0, 247/255.0, 1.0f);

	Vertex2D position = {2.0f, 2.0f};

	HousesClass c1(position, "../Texture/HouseWall.jpg");
	c1.draw();

	position = {-2.0f, -2.0f};

	BuildingsClass<false, false> p1(position, 5.0f, "../Texture/BuildingWall5.jpg");
	p1.draw();

	position = {0.0f, 0.0f};

	BuildingsClass<true, false> p2(position, 12.0f, "../Texture/BuildingWall.jpg");
	p2.draw();

	position = {2.0f, -2.0f};

	BuildingsClass<false, true> p3(position, 7.0f, "../Texture/BuildingWall10.jpg");
	p3.draw();

	drawCityFloor();
	drawLandscape();

	light.ambient_light();

	light.lighting();

	glutSwapBuffers();
}

void drawCityFloor(){
	glPushMatrix();

	string floorTexture = "../Texture/CityFloor.jpg";
	Mat img = imread(floorTexture);
	flip(img, img, 0);
	SET_TEXTURE_PARAM(img)

	// glColor3f(1.0f,0.0f,0.0f);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	    glTexCoord2f(0.0, 10.0); glVertex2d(-10.0, 10.0);
	    glTexCoord2f(0.0, 0.0); glVertex2d(-10.0, -10.0);
	    glTexCoord2f(10.0, 0.0); glVertex2d(10.0, -10.0);
	    glTexCoord2f(10.0, 10.0); glVertex2d(10.0, 10.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void drawLandscape(){
	string landscapeTexture = "../Texture/skybox3";
	Mat img = imread(landscapeTexture+"-down.jpg");
	flip(img, img, 0);
	SET_TEXTURE_PARAM(img)

	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);
			glTexCoord2d(0.0, 1.0); glVertex3d(-25,  25, -0.01);
			glTexCoord2d(0.0, 0.0); glVertex3d(-25, -25, -0.01);
			glTexCoord2d(1.0, 0.0); glVertex3d( 25, -25, -0.01);
			glTexCoord2d(1.0, 1.0); glVertex3d( 25,  25, -0.01);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();

	img = imread(landscapeTexture+"-up.jpg");
	flip(img, img, 0);
	SET_TEXTURE_PARAM(img)

	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);
			glTexCoord2d(0.0, 1.0); glVertex3d(-25,  25, 50);
			glTexCoord2d(0.0, 0.0); glVertex3d(-25, -25, 50);
			glTexCoord2d(1.0, 0.0); glVertex3d( 25, -25, 50);
			glTexCoord2d(1.0, 1.0); glVertex3d( 25,  25, 50);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();

	img = imread(landscapeTexture+"-side4.jpg");
	flip(img, img, 0);
	flip(img, img, 1);
	SET_TEXTURE_PARAM(img)

	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);
			glTexCoord2d(0.0, 1.0); glVertex3d(-25, 25,  50);
			glTexCoord2d(0.0, 0.0); glVertex3d(-25, 25, -0.01);
			glTexCoord2d(1.0, 0.0); glVertex3d( 25, 25, -0.01);
			glTexCoord2d(1.0, 1.0); glVertex3d( 25, 25,  50);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();

	img = imread(landscapeTexture+"-side3.jpg");
	flip(img, img, 0);
	SET_TEXTURE_PARAM(img)

	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);
			glTexCoord2d(0.0, 1.0); glVertex3d( 25, -25,  50);
			glTexCoord2d(0.0, 0.0); glVertex3d( 25, -25, -0.01);
			glTexCoord2d(1.0, 0.0); glVertex3d( 25,  25, -0.01);
			glTexCoord2d(1.0, 1.0); glVertex3d( 25,  25,  50);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();

	img = imread(landscapeTexture+"-side2.jpg");
	flip(img, img, 0);
	SET_TEXTURE_PARAM(img)

	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);
			glTexCoord2d(0.0, 1.0); glVertex3d(-25, -25,  50);
			glTexCoord2d(0.0, 0.0); glVertex3d(-25, -25, -0.01);
			glTexCoord2d(1.0, 0.0); glVertex3d( 25, -25, -0.01);
			glTexCoord2d(1.0, 1.0); glVertex3d( 25, -25,  50);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();

	img = imread(landscapeTexture+"-side1.jpg");
	flip(img, img, 0);
	flip(img, img, 1);
	SET_TEXTURE_PARAM(img)

	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);
			glTexCoord2d(0.0, 1.0); glVertex3d(-25, -25,  50);
			glTexCoord2d(0.0, 0.0); glVertex3d(-25, -25, -0.01);
			glTexCoord2d(1.0, 0.0); glVertex3d(-25,  25, -0.01);
			glTexCoord2d(1.0, 1.0); glVertex3d(-25,  25,  50);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();

}

void windowReshapeFunc(GLsizei w, GLsizei h){
	viewC.windowReshape(w, h);
}

void animate(){


	viewC.VisParamSpecify();
	glutPostRedisplay();
}


void keyboard(unsigned char key, int x, int y){
	control.keyboard(key, x, y, viewC);
}

void keyboard_special(int key, int x, int y){
	control.keyboard_special(key, x, y, viewC);
}