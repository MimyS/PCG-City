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

void LightClass::lighting() {
	//GL_LIGHT0, GL_LIGHT1, ... , GL_LIGHT7
	GLfloat white[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat black[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat away[] = { 56/255.0f, 52/255.0f, 18/255.0f, 1.0f };

	/* Cria uma fonte de luz puntual */
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	glLightfv(GL_LIGHT0, GL_AMBIENT, black);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white);

	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.001);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.001);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.001);

	//glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

}