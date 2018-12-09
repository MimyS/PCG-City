#include "City.hpp"

/**GLOBAL**/
Vertex3D pMin = {-25,-25,-0.01};
Vertex3D pMax = { 25, 25, 50};
ViewClass viewC(pMin, pMax);
ControlClass control;
LightClass light(pMax.x - 0.1, pMax.y - 0.1, pMax.z - 1.0);
vector<HousesClass> houses;
vector<BuildingsClass<false,false>> normalBuildings;
vector<BuildingsClass<false,true>> mirrorBuildings;
BuildingsClass<true, false> p({0.0,0.0}, 12.0f, 42);

using namespace std;

GLfloat bdSize(){
	return 3 + rand()%6;
}

GLuint bdText(){
	return 27 + (rand()%16);
}

GLuint hsText(){
	return 18 + (rand()%9);
}

GLuint rfText(){
	return 12 + 2*(rand()%3);
}

void Binds(){
	string base = "../Texture/skybox3";
	Mat img = imread(base+"-down.jpg");
	flip(img, img, 0);
	BIND_TEX(1, img)

	img = imread(base+"-up.jpg");
	flip(img, img, 0);
	BIND_TEX(2, img)

	img = imread(base+"-side4.jpg");
	flip(img, img, 0);
	flip(img, img, 1);
	BIND_TEX(3, img)

	img = imread(base+"-side3.jpg");
	flip(img, img, 0);
	BIND_TEX(4, img)

	img = imread(base+"-side2.jpg");
	flip(img, img, 0);
	BIND_TEX(5, img)

	img = imread(base+"-side1.jpg");
	flip(img, img, 0);
	flip(img, img, 1);
	BIND_TEX(6, img)

	img = imread("../Texture/CityFloor.jpg");
	flip(img, img, 0);
	BIND_TEX(7, img)
	
	img = imread("../Texture/BuildingFloor.jpg");
	flip(img, img, 0);
	BIND_TEX(8, img)

	img = imread("../Texture/BuildingFloor2.jpg");
	flip(img, img, 0);
	BIND_TEX(9, img)

	img = imread("../Texture/BuildingRoof.jpg");
	BIND_TEX(10, img)

	img = imread("../Texture/grass.jpg");
	flip(img, img, 0);
	BIND_TEX(11, img)

	GLuint ID = 12;

	base = "../Texture/HouseRoof";

	for(char i = 1; i <= 3; i++){
		img = imread(base + to_string(i) + ".jpg");
		flip(img, img, 0);
		BIND_TEX(ID, img)
		rotate(img, img, ROTATE_90_CLOCKWISE);
		BIND_TEX(ID+1, img)
		ID+=2;
	}
	
	base = "../Texture/HouseWall";

	for(char i = 1; i <= 9; i++){
		img = imread(base + to_string(i) + ".jpg");
		rotate(img, img, ROTATE_180);
		BIND_TEX(ID, img)
		ID++;
	}

	base = "../Texture/BuildingWall";
	
	for(char i = 1; i <= 16; i++){
		img = imread(base + to_string(i) + ".jpg");
		rotate(img, img, ROTATE_180);
		BIND_TEX(ID, img)
		ID++;
	}

	img.release();
}

void Init(){
	srand (time(NULL));
	houses.reserve(36);
	normalBuildings.reserve(8);
	mirrorBuildings.reserve(4);

	Vertex2D position;	

	for(char i = -14; i <= 14; i+2){
		for(char j = -14 ; j <= 14; j+2){
			position = {GLfloat(i), GLfloat(j)};
			if(abs(i) != abs(j)){
				houses.push_back(HousesClass(position, hsText(), rfText()));
			}else{
				if(i != 2 && i != -2){
					normalBuildings.push_back(BuildingsClass<false,false>(position, bdSize(), bdText()));
				}else if(i != 0){
					mirrorBuildings.push_back(BuildingsClass<false, true>(position, bdSize(), bdText()));
				}
			}
		}
	}

	Binds();
}

void drawScene(){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 1.0, 0.98, 1.0f);
	
	glEnable(GL_COLOR_MATERIAL);

	glDisable(GL_LIGHTING);
	drawLandscape();
	glEnable(GL_LIGHTING);
	drawCityFloor();

	light.basicMaterial();
	
	for(auto h:houses){
		h.draw();
	}
	for(auto b:normalBuildings){
		b.draw(light);
	}
	for(auto b:mirrorBuildings){
		b.draw(light);
	}

	p.draw(light);

	light.ambient_light();
	light.lighting();

	glutSwapBuffers();
}

void drawCityFloor(){
	glPushMatrix();

	glBindTexture(GL_TEXTURE_2D, 7);

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

	glBindTexture(GL_TEXTURE_2D, 1);

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

	glBindTexture(GL_TEXTURE_2D, 2);

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

	glBindTexture(GL_TEXTURE_2D, 3);

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

	glBindTexture(GL_TEXTURE_2D, 4);

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

	glBindTexture(GL_TEXTURE_2D, 5);

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

	glBindTexture(GL_TEXTURE_2D, 6);

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