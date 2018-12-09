#include "City.hpp"

/**GLOBAL**/
Vertex3D pMin = {-25,-25,-0.01};
Vertex3D pMax = { 25, 25, 50};
ViewClass viewC(pMin, pMax);
ControlClass control;
LightClass light(pMax.x - 0.1, pMax.y - 0.1, pMax.z - 1.0);

using namespace std;

void drawScene(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_COLOR_MATERIAL);

	glClearColor(1.0, 1.0, 0.98, 1.0f);

	Vertex2D position = {2.0f, 2.0f};
	
	light.basicMaterial();

	HousesClass c1(position, "../Texture/HouseWall.jpg");
	c1.draw();

	position = {-2.0f, -2.0f};

	BuildingsClass<false, false> p1(position, 5.0f, "../Texture/BuildingWall5.jpg");
	p1.draw(light);

	position = {0.0f, 0.0f};

	BuildingsClass<true, false> p2(position, 12.0f, "../Texture/BuildingWall.jpg");
	p2.draw(light);

	position = {2.0f, -2.0f};

	BuildingsClass<false, true> p3(position, 7.0f, "../Texture/BuildingWall10.jpg");
	p3.draw(light);

	drawCityFloor();
	glDisable(GL_LIGHTING);
	drawLandscape();
	glEnable(GL_LIGHTING);

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
			glTexCoord2d(0.0, 1.0); glVertex3d(pMin.x, pMax.y, pMin.z);
			glTexCoord2d(0.0, 0.0); glVertex3d(pMin.x, pMin.y, pMin.z);
			glTexCoord2d(1.0, 0.0); glVertex3d(pMax.x, pMin.y, pMin.z);
			glTexCoord2d(1.0, 1.0); glVertex3d(pMax.x, pMax.y, pMin.z);
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
			glTexCoord2d(0.0, 1.0); glVertex3d(pMin.x, pMax.y, pMax.z);
			glTexCoord2d(0.0, 0.0); glVertex3d(pMin.x, pMin.y, pMax.z);
			glTexCoord2d(1.0, 0.0); glVertex3d(pMax.x, pMin.y, pMax.z);
			glTexCoord2d(1.0, 1.0); glVertex3d(pMax.x, pMax.y, pMax.z);
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
			glTexCoord2d(0.0, 1.0); glVertex3d(pMin.x, pMax.y, pMax.z);
			glTexCoord2d(0.0, 0.0); glVertex3d(pMin.x, pMax.y, pMin.z);
			glTexCoord2d(1.0, 0.0); glVertex3d(pMax.x, pMax.y, pMin.z);
			glTexCoord2d(1.0, 1.0); glVertex3d(pMax.x, pMax.y, pMax.z);
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
			glTexCoord2d(0.0, 1.0); glVertex3d(pMax.x, pMin.y, pMax.z);
			glTexCoord2d(0.0, 0.0); glVertex3d(pMax.x, pMin.y, pMin.z);
			glTexCoord2d(1.0, 0.0); glVertex3d(pMax.x, pMax.y, pMin.z);
			glTexCoord2d(1.0, 1.0); glVertex3d(pMax.x, pMax.y, pMax.z);
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
			glTexCoord2d(0.0, 1.0); glVertex3d(pMin.x, pMin.y, pMax.z);
			glTexCoord2d(0.0, 0.0); glVertex3d(pMin.x, pMin.y, pMin.z);
			glTexCoord2d(1.0, 0.0); glVertex3d(pMax.x, pMin.y, pMin.z);
			glTexCoord2d(1.0, 1.0); glVertex3d(pMax.x, pMin.y, pMax.z);
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
			glTexCoord2d(0.0, 1.0); glVertex3d(pMin.x, pMin.y, pMax.z);
			glTexCoord2d(0.0, 0.0); glVertex3d(pMin.x, pMin.y, pMin.z);
			glTexCoord2d(1.0, 0.0); glVertex3d(pMin.x, pMax.y, pMin.z);
			glTexCoord2d(1.0, 1.0); glVertex3d(pMin.x, pMax.y, pMax.z);
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