#include "ViewClass.hpp"

using namespace std;

ViewClass::ViewClass(){
	ResetAll();
	visAngle = 45;
	fAspect = 0;
}


ViewClass::~ViewClass(){
}

// Specify the virtual observer position
void ViewClass::ObserverPos(){
	// Coordinate system model
	glMatrixMode(GL_MODELVIEW);
	// Initialize system
	glLoadIdentity();
	// Specify observer and target position
	gluLookAt(cameraX, cameraY, cameraZ, centerX, centerY, centerZ, viewUpX, viewUpY, viewUpZ);
}

void ViewClass::VisParamSpecify(){
	// Projection coordinate
	glMatrixMode(GL_PROJECTION);
	// Initialize projection coordinate system
	glLoadIdentity();
	// Specify projection type - perspective
	gluPerspective(visAngle, fAspect, 0.5, 10000);

	ObserverPos();
}

void ViewClass::windowReshape(GLsizei w, GLsizei h){
	// Prevent division by 0
	if (h == 0) h = 1;
	// Viewport size
	glViewport(0, 0, w, h);
	// Aspect correction
	fAspect = (GLfloat) w / (GLfloat) h;

	VisParamSpecify();
}

void ViewClass::MoveCenterX(GLfloat val){
	centerX += val * (visAngle / 90.0);
}

void ViewClass::MoveCenterY(GLfloat val){
	centerY += val * (visAngle / 90.0);
}

void ViewClass::MoveCenterZ(GLfloat val){
	centerZ += val;
}

void ViewClass::MoveCameraX(GLfloat val){
	cameraX += val;
}

void ViewClass::MoveCameraY(GLfloat val){
	cameraY += val;
}

void ViewClass::MoveCameraZ(GLfloat val){
	if (val > 0){
		cameraZ += val;
	} else{
		if ((cameraZ + val) > 0.5){
			cameraZ += val;
		} else{
			cameraZ = 0.5;
		}
	}
}

void ViewClass::MoveViewUpX(GLfloat val){
	viewUpX += val;
}

void ViewClass::MoveViewUpY(GLfloat val){
	viewUpY += val;
}

void ViewClass::MoveViewUpZ(GLfloat val){
	viewUpZ += val;
}

void ViewClass::SetCameraPos(GLfloat x, GLfloat y, GLfloat z){
	cameraX = x;
	cameraY = y;
	cameraZ = z;
}

void ViewClass::SetCenterPos(GLfloat x, GLfloat y, GLfloat z){
	centerX = x;
	centerY = y;
	centerZ = z;
}

void ViewClass::SetViewUpPos(GLfloat x, GLfloat y, GLfloat z){
	viewUpX = x;
	viewUpY = y;
	viewUpZ = z;
}

void ViewClass::ResetCenter(){
	centerX = 0;
	centerY = 0;
	centerZ = 0;
}

void ViewClass::ResetCamera(){
	cameraX = 0;
	cameraY = 0;
	cameraZ = 0;
}

void ViewClass::ResetAll(){
	cameraX = 0;
	cameraY = 0;
	cameraZ = 40;
	centerX = 0;
	centerY = 0;
	centerZ = 0;
	viewUpX = 0;
	viewUpY = 1;
	viewUpZ = 0;
}

void ViewClass::ZoomIn(){
	// prevent visAngle from reaching 0
	if (visAngle > 179.75){
		visAngle -= 0.01;
	} else if (visAngle > 179){
		visAngle -= 0.1;
	} else if (visAngle > 1){
		visAngle -= 1;
	} else if (visAngle > 0.25){
		visAngle -= 0.1;
	} else if (visAngle > 0.01){
		visAngle -= 0.01;
	}
}

void ViewClass::ZoomOut(){
	// prevent visAngle from reaching 180
	if (visAngle < 0.25){
		visAngle += 0.01;
	} else if (visAngle < 1){
		visAngle += 0.1;
	} else if (visAngle < 179){
		visAngle += 1;
	} else if (visAngle < 179.75){
		visAngle += 0.1;
	} else if (visAngle < 179.99){
		visAngle += 0.01;
	}
}