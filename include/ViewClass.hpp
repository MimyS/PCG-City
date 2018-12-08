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
	Vertex3D pMin;
	Vertex3D pMax;

public:

	void ObserverPos();
	void VisParamSpecify();
	void windowReshape(GLsizei, GLsizei);
	void MoveCenterX(GLfloat val);
	void MoveCenterY(GLfloat val);
	void MoveCenterZ(GLfloat val);
	void MoveCameraX(GLfloat val);
	void MoveCameraY(GLfloat val);
	void MoveCameraZ(GLfloat val);
	void MoveViewUpX(GLfloat val);
	void MoveViewUpY(GLfloat val);
	void MoveViewUpZ(GLfloat val);
	void SetCameraPos(GLfloat, GLfloat, GLfloat);
	void SetCenterPos(GLfloat x, GLfloat y, GLfloat z);
	void SetViewUpPos(GLfloat x, GLfloat y, GLfloat z);
	void ResetCenter();
	void ResetCamera();
	void ResetAll();
	void ZoomIn();
	void ZoomOut();

	ViewClass(Vertex3D, Vertex3D);
	~ViewClass();
};
