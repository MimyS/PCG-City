#include "HousesClass.hpp"

const GLuint HousesClass::floorTextureID = 9;
const GLuint HousesClass::grassTextureID = 11;

void HousesClass::draw(){
    drawRoof();
    drawWalls();
    drawFloor();
	drawGrass();
}

HousesClass::HousesClass(Vertex2D pos, GLuint houseText, GLuint roofText1, GLuint roofText2){
    position = pos;
    houseTextureID = houseText;
	roofTextureID1 = roofText1;
	roofTextureID2 = roofText2;
}


HousesClass::~HousesClass(){
}

void HousesClass::drawFloor(){
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, floorTextureID);

	glTranslated(position.x-0.5f, position.y-0.5f, 0.05f);
	glBegin(GL_QUADS);
	    glTexCoord2f(0.0, 1.0); glVertex2f(0.0f, 0.0f);
	    glTexCoord2f(0.0, 0.0); glVertex2f(0.0f, 1.0f);
	    glTexCoord2f(1.0, 0.0); glVertex2f(1.0f, 1.0f);
	    glTexCoord2f(1.0, 1.0); glVertex2f(1.0f, 0.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);   
	glPopMatrix();
}

void HousesClass::drawRoof(){
    glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, roofTextureID1);

	glPushMatrix();
	{
		glTranslated(position.x, position.y, 0.0);
		
		glBegin(GL_QUADS);
			// up - trapeze
			glTexCoord2d(-0.5, 1.0);	glVertex3d(-0.5, 0.5, 1.0);
			glTexCoord2d(-0.2, 1.7);	glVertex3d(-0.2, 0.0, 1.7);
			glTexCoord2d(0.2, 1.7);		glVertex3d( 0.2, 0.0, 1.7);
			glTexCoord2d(0.5, 1.0);		glVertex3d( 0.5, 0.5, 1.0);
			// down - trapeze
			glTexCoord2d(-0.5, 1.0);	glVertex3d(-0.5, -0.5, 1.0);
			glTexCoord2d(-0.2, 1.7);	glVertex3d(-0.2,  0.0, 1.7);
			glTexCoord2d(0.2, 1.7);		glVertex3d( 0.2,  0.0, 1.7);
			glTexCoord2d(0.5, 1.0);		glVertex3d( 0.5, -0.5, 1.0);
		glEnd();
	}
	glPopMatrix();
	
	glBindTexture(GL_TEXTURE_2D, roofTextureID2);

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
	glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
}

void HousesClass::drawWalls(){
    glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, houseTextureID);

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
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);   
}

void HousesClass::drawGrass(){
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, grassTextureID);

	glTranslated(position.x-0.75f, position.y-0.75f, 0.025f);
	glBegin(GL_QUADS);
	    glTexCoord2f(0.0, 0.0); glVertex2f(0.0f, 0.0f);
	    glTexCoord2f(0.0, 1.5); glVertex2f(0.0f, 1.5f);
	    glTexCoord2f(1.5, 1.5); glVertex2f(1.5f, 1.5f);
	    glTexCoord2f(1.5, 0.0); glVertex2f(1.5f, 0.0f);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);   
	glPopMatrix();
}