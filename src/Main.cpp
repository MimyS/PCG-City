#include "City.hpp"

using namespace std;
//using namespace cv;

int main(int argc, char **argv){
	glutInit(&argc, argv);
	
	Init();

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Emily - City");

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glutIdleFunc(animate);

	glutDisplayFunc(drawScene);

	glutReshapeFunc(windowReshapeFunc);

	glutSpecialFunc(&keyboard_special);
	glutKeyboardFunc(&keyboard);

	glutMainLoop();

	return 0;

}