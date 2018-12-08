#include "ControlClass.hpp"

void ControlClass::keyboard(unsigned char key, int x, int y, ViewClass & viewC){
	switch (key){
		// ZOOM
		case '+': // ZOOM IN
			viewC.ZoomIn();
			break;
		case '-': // ZOOM OUT
			viewC.ZoomOut();
			break;
			// Camera and ViewUp in Z
		case 'w': // up
		case 'W':
			viewC.MoveCameraZ(5);
			break;
		case 's': // down
		case 'S':
			viewC.MoveCameraZ(-5);
			break;
		case 'a': // left
		case 'A':
			viewC.MoveViewUpZ(-1);
			break;
		case 'd': // right
		case 'D':
			viewC.MoveViewUpZ(1);
			break;
			// reset to first view
		case 'r':
		case 'R':
			viewC.ResetAll();
			break;

			// numeric - ViewUp
		case '8': // up
			viewC.MoveViewUpY(1);
			break;
		case '5': // down
			viewC.MoveViewUpY(-1);
			break;
		case '4': // left
			viewC.MoveViewUpX(1);
			break;
		case '6': // right
			viewC.MoveViewUpX(-1);
			break;
		default:
			break;
	}
}

void ControlClass::keyboard_special(int key, int x, int y, ViewClass & viewC){
	switch (key){
		case GLUT_KEY_RIGHT:
			viewC.MoveCameraX(10);
			break;
		case GLUT_KEY_LEFT:
			viewC.MoveCameraX(-10);
			break;
		case GLUT_KEY_UP:
			viewC.MoveCameraY(10);
			break;
		case GLUT_KEY_DOWN:
			viewC.MoveCameraY(-10);
			break;
		default:
			break;
	}
}

ControlClass::ControlClass(){
}


ControlClass::~ControlClass(){
}
