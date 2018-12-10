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
BuildingsClass<true, false> p({0.0,0.0}, 12.0f, "../Texture/BuildingWall16.jpg");

GLuint vecTexture[42];

using namespace std;

GLfloat bdSize(){
	return 3 + rand()%6;
}

string bdText(){
	return "../Texture/BuildingWall" + to_string((rand()%16)+1) + ".jpg";
}

string hsText(){
	return "../Texture/HouseWall" + to_string((rand()%9)+1) + ".jpg";
}

string rfText(){
	return "../Texture/HouseRoof" + to_string((rand()%3)+1) + ".jpg";
}

GLuint img2Texture(cv::Mat &mat){
	GLuint textureID;
	glGenTextures(1, &textureID);
 	glBindTexture(GL_TEXTURE_2D, textureID);
 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
 
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, mat.cols, mat.rows, 0, GL_BGR, GL_UNSIGNED_BYTE, mat.ptr());
	return textureID;
}

void TextureBind(){
	glEnable(GL_TEXTURE_2D);

	string floorTexture = "../Texture/CityFloor.jpg";
	Mat img = imread(floorTexture);
	flip(img, img, 0);
	vecTexture[0] = img2Texture(img);

	string landscapeTexture = "../Texture/skybox3";
	img = imread(landscapeTexture+"-down.jpg");
	flip(img, img, 0);
	vecTexture[1] = img2Texture(img);
	
	img = imread(landscapeTexture+"-up.jpg");
	flip(img, img, 0);
	vecTexture[2] = img2Texture(img);

	img = imread(landscapeTexture+"-side4.jpg");
	flip(img, img, 0);
	flip(img, img, 1);
	vecTexture[3] = img2Texture(img);
	
	img = imread(landscapeTexture+"-side3.jpg");
	flip(img, img, 0);
	vecTexture[4] = img2Texture(img);

	img = imread(landscapeTexture+"-side2.jpg");
	flip(img, img, 0);
	vecTexture[5] = img2Texture(img);

	img = imread(landscapeTexture+"-side1.jpg");
	flip(img, img, 0);
	flip(img, img, 1);
	vecTexture[6] = img2Texture(img);


	glDisable(GL_TEXTURE_2D);
	img.release();
}
void DeleteBinds(){
	glDeleteTextures(1, vecTexture);
}

void Init(){
	srand (time(NULL));
	houses.reserve(36);
	normalBuildings.reserve(8);
	mirrorBuildings.reserve(4);

	TextureBind();

	Vertex2D position;	

	for(char i = -12; i <= 12; i+=4){
		for(char j = -12 ; j <= 12; j+=4){
			position = {i, j};
			if(abs(i) != abs(j)){
				if(i == 0){
					if (abs(j) == 12){
						mirrorBuildings.push_back(BuildingsClass<false, true>(position, bdSize(), bdText()));
					}else{
						houses.push_back(HousesClass(position, hsText(), rfText()));
					}
				}else if(abs(i) == 12){
					if(j == 0){
						mirrorBuildings.push_back(BuildingsClass<false, true>(position, bdSize(), bdText()));
					}else{
						houses.push_back(HousesClass(position, hsText(), rfText()));
					}
				}else{
						houses.push_back(HousesClass(position, hsText(), rfText()));
				}
			}else{
				if(i != 4 && i != -4){
					normalBuildings.push_back(BuildingsClass<false,false>(position, bdSize(), bdText()));
				}else if(i != 0){
					mirrorBuildings.push_back(BuildingsClass<false, true>(position, bdSize(), bdText()));
				}
			}
		}
	}
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

	/*string floorTexture = "../Texture/CityFloor.jpg";
	Mat img = imread(floorTexture);
	flip(img, img, 0);
	SET_TEXTURE_PARAM(img)*/

	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, vecTexture[0]);

	glBegin(GL_QUADS);
	    glTexCoord2f(0.0, 14.0); glVertex2d(-14.0, 14.0);
	    glTexCoord2f(0.0, 0.0); glVertex2d(-14.0, -14.0);
	    glTexCoord2f(14.0, 0.0); glVertex2d(14.0, -14.0);
	    glTexCoord2f(14.0, 14.0); glVertex2d(14.0, 14.0);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	// img.release();
}

void drawLandscape(){
	// string landscapeTexture = "../Texture/skybox3";
	// Mat img = imread(landscapeTexture+"-down.jpg");
	// flip(img, img, 0);
	// SET_TEXTURE_PARAM(img)

	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, vecTexture[1]);
		glBegin(GL_QUADS);
			glTexCoord2d(0.0, 1.0); glVertex3d(pMin.x, pMax.y, pMin.z);
			glTexCoord2d(0.0, 0.0); glVertex3d(pMin.x, pMin.y, pMin.z);
			glTexCoord2d(1.0, 0.0); glVertex3d(pMax.x, pMin.y, pMin.z);
			glTexCoord2d(1.0, 1.0); glVertex3d(pMax.x, pMax.y, pMin.z);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();

	// img = imread(landscapeTexture+"-up.jpg");
	// flip(img, img, 0);
	// SET_TEXTURE_PARAM(img)

	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, vecTexture[2]);
		glBegin(GL_QUADS);
			glTexCoord2d(0.0, 1.0); glVertex3d(pMin.x, pMax.y, pMax.z);
			glTexCoord2d(0.0, 0.0); glVertex3d(pMin.x, pMin.y, pMax.z);
			glTexCoord2d(1.0, 0.0); glVertex3d(pMax.x, pMin.y, pMax.z);
			glTexCoord2d(1.0, 1.0); glVertex3d(pMax.x, pMax.y, pMax.z);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();

	/*img = imread(landscapeTexture+"-side4.jpg");
	flip(img, img, 0);
	flip(img, img, 1);
	SET_TEXTURE_PARAM(img)*/

	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, vecTexture[3]);
		glBegin(GL_QUADS);
			glTexCoord2d(0.0, 1.0); glVertex3d(pMin.x, pMax.y, pMax.z);
			glTexCoord2d(0.0, 0.0); glVertex3d(pMin.x, pMax.y, pMin.z);
			glTexCoord2d(1.0, 0.0); glVertex3d(pMax.x, pMax.y, pMin.z);
			glTexCoord2d(1.0, 1.0); glVertex3d(pMax.x, pMax.y, pMax.z);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();

	/*img = imread(landscapeTexture+"-side3.jpg");
	flip(img, img, 0);
	SET_TEXTURE_PARAM(img)*/

	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, vecTexture[4]);
		glBegin(GL_QUADS);
			glTexCoord2d(0.0, 1.0); glVertex3d(pMax.x, pMin.y, pMax.z);
			glTexCoord2d(0.0, 0.0); glVertex3d(pMax.x, pMin.y, pMin.z);
			glTexCoord2d(1.0, 0.0); glVertex3d(pMax.x, pMax.y, pMin.z);
			glTexCoord2d(1.0, 1.0); glVertex3d(pMax.x, pMax.y, pMax.z);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();

	/*img = imread(landscapeTexture+"-side2.jpg");
	flip(img, img, 0);
	SET_TEXTURE_PARAM(img)*/

	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, vecTexture[5]);
		glBegin(GL_QUADS);
			glTexCoord2d(0.0, 1.0); glVertex3d(pMin.x, pMin.y, pMax.z);
			glTexCoord2d(0.0, 0.0); glVertex3d(pMin.x, pMin.y, pMin.z);
			glTexCoord2d(1.0, 0.0); glVertex3d(pMax.x, pMin.y, pMin.z);
			glTexCoord2d(1.0, 1.0); glVertex3d(pMax.x, pMin.y, pMax.z);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();

	/*img = imread(landscapeTexture+"-side1.jpg");
	flip(img, img, 0);
	flip(img, img, 1);
	SET_TEXTURE_PARAM(img)*/

	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, vecTexture[6]);
		glBegin(GL_QUADS);
			glTexCoord2d(0.0, 1.0); glVertex3d(pMin.x, pMin.y, pMax.z);
			glTexCoord2d(0.0, 0.0); glVertex3d(pMin.x, pMin.y, pMin.z);
			glTexCoord2d(1.0, 0.0); glVertex3d(pMin.x, pMax.y, pMin.z);
			glTexCoord2d(1.0, 1.0); glVertex3d(pMin.x, pMax.y, pMax.z);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();
	// img.release();
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
