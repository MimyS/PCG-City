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
BuildingsClass<true, false> p({0.0,0.0}, 12.0f);

TextureIDs texID;

GLuint houseRoofTx[6];
GLuint houseWallTx[9];
GLuint buildWallTx[16];

using namespace std;

GLfloat bdSize(){
	return 3 + rand()%6;
}

GLuint bdText(){
	return buildWallTx[(rand()%16)];
}

GLuint hsText(){
	return houseWallTx[(rand()%9)];
}

GLuint rfText(){
	return 2*(rand()%3);
}

void Binds(){
	
	string base = "../Texture/skybox3";
	Mat img = imread(base+"-down.jpg");
	flip(img, img, 0);
	texID.skyboxDown = bind_tex(&texID.skyboxDown, img);

	img = imread(base+"-up.jpg");
	flip(img, img, 0);
	texID.skyboxUp = bind_tex(&texID.skyboxUp, img);

	img = imread(base+"-side4.jpg");
	flip(img, img, 0);
	flip(img, img, 1);
	texID.skyboxSide4 = bind_tex(&texID.skyboxSide4, img);

	img = imread(base+"-side3.jpg");
	flip(img, img, 0);
	texID.skyboxSide3 = bind_tex(&texID.skyboxSide3, img);

	img = imread(base+"-side2.jpg");
	flip(img, img, 0);
	texID.skyboxSide2 = bind_tex(&texID.skyboxSide2, img);

	img = imread(base+"-side1.jpg");
	flip(img, img, 0);
	flip(img, img, 1);
	texID.skyboxSide1 = bind_tex(&texID.skyboxSide1, img);

	img = imread("../Texture/CityFloor.jpg");
	flip(img, img, 0);
	texID.cityFloor = bind_tex(&texID.cityFloor, img);

	img = imread("../Texture/BuildingFloor.jpg");
	flip(img, img, 0);
	texID.buildFloor = bind_tex(&texID.buildFloor, img);

	img = imread("../Texture/BuildingFloor2.jpg");
	flip(img, img, 0);
	texID.houseFloor = bind_tex(&texID.houseFloor, img);

	img = imread("../Texture/BuildingRoof.jpg");
	texID.buildRoof = bind_tex(&texID.buildRoof, img);

	img = imread("../Texture/grass.jpg");
	flip(img, img, 0);
	texID.grass = bind_tex(&texID.grass, img);

	base = "../Texture/HouseRoof";

	for(auto i = 1; i <= 6; i+=2){
		img = imread(base + to_string(i) + ".jpg");
		flip(img, img, 0);
		houseRoofTx[i] = bind_tex(&houseRoofTx[i], img);
		rotate(img, img, ROTATE_90_CLOCKWISE);
		houseRoofTx[i+1] = bind_tex(&houseRoofTx[i+1], img);
	}

	base = "../Texture/HouseWall";

	for(auto i = 1; i <= 9; i++){
		img = imread(base + to_string(i) + ".jpg");
		rotate(img, img, ROTATE_180);
		houseWallTx[i] = bind_tex(&houseWallTx[i], img);
	}

	base = "../Texture/BuildingWall";

	for(auto i = 1; i <= 16; i++){
		img = imread(base + to_string(i) + ".jpg");
		rotate(img, img, ROTATE_180);
		buildWallTx[i] = bind_tex(&buildWallTx[i], img);
	}

	img.release();
}

void Init(){
	srand (time(NULL));
	houses.reserve(23);
	normalBuildings.reserve(8);
	mirrorBuildings.reserve(4);

	Vertex2D position;

	Binds();

	for(char i = -12; i <= 12; i+=2){
		for(char j = -12 ; j <= 12; j+=2){
			position = {GLfloat(i), GLfloat(j)};
			if(abs(i) != abs(j) && (i == 0 && abs(j) == 12) && (j == 0 && abs(i) == 12)){
				int temp = rfText();
				houses.push_back(HousesClass(position, hsText(), houseRoofTx[temp], houseRoofTx[temp+1]));
			}else{
				if(i != 2 && i != -2){
					normalBuildings.push_back(BuildingsClass<false,false>(position, bdSize(), bdText()));
				}else if(i != 0){
					mirrorBuildings.push_back(BuildingsClass<false, true>(position, bdSize(), bdText()));
				}
			}
		}
	}
	p.setWallText(buildWallTx[16]);
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

	glBindTexture(GL_TEXTURE_2D, texID.cityFloor);

	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	    glTexCoord2f(0.0, 10.0); glVertex2d(-10.0, 10.0);
	    glTexCoord2f(0.0, 0.0); glVertex2d(-10.0, -10.0);
	    glTexCoord2f(10.0, 0.0); glVertex2d(10.0, -10.0);
	    glTexCoord2f(10.0, 10.0); glVertex2d(10.0, 10.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();
}

void drawLandscape(){

	glBindTexture(GL_TEXTURE_2D, texID.skyboxDown);

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

	glBindTexture(GL_TEXTURE_2D, texID.skyboxUp);

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

	glBindTexture(GL_TEXTURE_2D, texID.skyboxSide4);

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

	glBindTexture(GL_TEXTURE_2D, texID.skyboxSide3);

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

	glBindTexture(GL_TEXTURE_2D, texID.skyboxSide2);

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

	glBindTexture(GL_TEXTURE_2D, texID.skyboxSide1);

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
	glBindTexture(GL_TEXTURE_2D, 0);
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