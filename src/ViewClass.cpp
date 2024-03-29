#include "ViewClass.hpp"

using namespace std;

ViewClass::ViewClass(Vertex3D p1, Vertex3D p2){
	pMin = p1;
	pMax = p2;
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
	if((cameraX + val) > pMax.x){
		cameraX = pMax.x - 0.5;
	}else if((cameraX + val) < pMin.x){
		cameraX = pMin.x + 0.5;
	}else{
		cameraX += val;
	}
}

void ViewClass::MoveCameraY(GLfloat val){
	if((cameraY + val) > pMax.y){
		cameraY = pMax.y - 0.5;
	}else if((cameraY + val) < pMin.y){
		cameraY = pMin.y + 0.5;
	}else{
		cameraY += val;
	}
}

void ViewClass::MoveCameraZ(GLfloat val){
	if((cameraZ + val) > pMax.z){
		cameraZ = pMax.z - 0.5;
	}else if((cameraZ + val) < 0){
		cameraZ = pMin.z + 0.5;
	}else{
		cameraZ += val;
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
	cameraX = -5;
	cameraY = 5;
	cameraZ = 9;
	centerX = 0;
	centerY = 0;
	centerZ = 3;
	viewUpX = 1;
	viewUpY = 0;
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