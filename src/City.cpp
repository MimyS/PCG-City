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
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.cols, img.rows, 0, GL_BGR, GL_UNSIGNED_BYTE, img.ptr());

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

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
	string landscapeTexture = "../Texture/Landscape.jpg";
	glPushMatrix();
	//Mat img = imread(landscapeTexture);
	//flip(img, img, 0);
	//glTexImage3D(GL_TEXTURE_3D, 0, GL_RGBA, img.cols, img.rows, 1, 0, GL_BGR, GL_UNSIGNED_BYTE, img.ptr());

	// glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 32, 32, 0, GL_RGBA, GL_UNSIGNED_BYTE, matrixTex);
	//glTexParameterf(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameterf(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_REPEAT);

	// glColor3f(1.0f,0.0f,0.0f);
	// glEnable(GL_TEXTURE_2D);
	// glBegin(GL_QUADS);
	//     glTexCoord2f(0.0, 1.0); glVertex2d(-0.5, 0.5);
	//     glTexCoord2f(0.0, 0.0); glVertex2d(-0.5, -0.5);
	//     glTexCoord2f(1.0, 0.0); glVertex2d(0.5, -0.5);
	//     glTexCoord2f(1.0, 1.0); glVertex2d(0.5, 0.5);
	// glEnd();
	// glDisable(GL_TEXTURE_2D);

	//glPushMatrix();
	//glEnable(GL_TEXTURE_3D);

	//GLUquadric * quadObj = gluNewQuadric();
	//gluQuadricDrawStyle(quadObj, GLU_FILL);
	//gluQuadricNormals(quadObj, GLU_SMOOTH);
	//gluQuadricTexture(quadObj, GL_TRUE);
	//gluSphere(quadObj, 1.5f, 100, 100);
	//gluDeleteQuadric(quadObj);

	//glDisable(GL_TEXTURE_3D);
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