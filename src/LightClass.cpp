#include "LightClass.hpp"


void LightClass::ambient_light(){
	GLfloat global_ambient[] = {0.9f, 0.9f, 0.9f, 1.0f};

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

	glEnable(GL_LIGHTING);
}

LightClass::LightClass(GLfloat x, GLfloat y, GLfloat z){
	position[0] = x;
	position[1] = y;
	position[2] = z;
}

LightClass::~LightClass(){
}

void LightClass::basicMaterial(){
	glDisable(GL_COLOR_MATERIAL);
	GLfloat specular[] = { 0.0f, 0.0f, 0.0f, 0 };
	GLfloat ambient[] = { 0.2, 0.2, 0.2, 0 };
	GLfloat diffuse[] = { 0.4f, 0.4f, 0.4f, 0 };

	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 1);
	glColor4d(1.0f, 1.0f, 1.0f, 0.0f);
}

void LightClass::transparentMaterial(){
	glEnable(GL_COLOR_MATERIAL);
	glColor4d(1.0f, 1.0f, 1.0f, 0.5f);
}

void LightClass::reflectiveMaterial(){
	glDisable(GL_COLOR_MATERIAL);
	GLfloat specular[] = { 1, 1, 1, 0 };
	GLfloat ambient[] = { 1, 1, 1, 0 };
	GLfloat diffuse[] = { 1, 1, 1, 0 };

	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 1.0f);
}

void LightClass::lighting() {
	//GL_LIGHT0, GL_LIGHT1, ... , GL_LIGHT7
	GLfloat white[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat black[] = { 0.0f, 0.0f, 0.0f, 1.0f };

	/* Cria uma fonte de luz puntual */
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	glLightfv(GL_LIGHT0, GL_AMBIENT, black);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white);

	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 1);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 1);

	glEnable(GL_LIGHT0);
}