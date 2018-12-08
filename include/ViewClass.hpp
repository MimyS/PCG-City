#pragma once

#include"Utils.hpp"

class ViewClass {
	GLfloat cameraX;
	GLfloat cameraY;
	GLfloat cameraZ;
	GLfloat centerX;
	GLfloat centerY;
	GLfloat centerZ;
	GLfloat viewUpX;
	GLfloat viewUpY;
	GLfloat viewUpZ;
	GLfloat visAngle;
	GLfloat fAspect;

public:

	void ObserverPos();
	void VisParamSpecify();
	void windowReshape(GLsizei, GLsizei);
	void MoveCenterX(int val);
	void MoveCenterY(int val);
	void MoveCenterZ(int val);
	void MoveCameraX(int val);
	void MoveCameraY(int val);
	void MoveCameraZ(int val);
	void MoveViewUpX(int val);
	void MoveViewUpY(int val);
	void MoveViewUpZ(int val);
	void SetCameraPos(GLfloat, GLfloat, GLfloat);
	void SetCenterPos(GLfloat x, GLfloat y, GLfloat z);
	void SetViewUpPos(GLfloat x, GLfloat y, GLfloat z);
	void ResetCenter();
	void ResetCamera();
	void ResetAll();
	void ZoomIn();
	void ZoomOut();

	ViewClass();
	~ViewClass();
};
