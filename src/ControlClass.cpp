#include "ControlClass.hpp"

void ControlClass::keyboard(unsigned char key, int x, int y, ViewClass & viewC){
	key = tolower(key);
	if(ProgramStart){
		switch (key){
			// ZOOM
			case '+': // ZOOM IN
				viewC.ZoomIn();
				break;
			case '-': // ZOOM OUT
				viewC.ZoomOut();
				break;

			// reset to first view
			case 'r':
				viewC.ResetAll();
				break;
			case 'f': // up
				viewC.MoveCenterY(0.5);
				viewC.MoveCameraY(0.5);
				break;
			case 't': // down
				viewC.MoveCenterY(-0.5);
				viewC.MoveCameraY(-0.5);
				break;

			default:
				break;
		}
	}else{
		if (key== 's'){
			ProgramStart = true;
		}
	}
}

void ControlClass::keyboard_special(int key, int x, int y, ViewClass & viewC){
	if(ProgramStart){
		switch (key){
			case GLUT_KEY_RIGHT:
				viewC.MoveCenterX(0.5);
				viewC.MoveCameraX(0.5);
				break;
			case GLUT_KEY_LEFT:
				viewC.MoveCenterX(-0.5);
				viewC.MoveCameraX(-0.5);
				break;
			case GLUT_KEY_UP:
				viewC.MoveCameraZ(0.5);
				break;
			case GLUT_KEY_DOWN:
				viewC.MoveCameraZ(-0.5);
				break;
			default:
				break;
		}
	}
}

ControlClass::ControlClass(){
}


ControlClass::~ControlClass(){
}
