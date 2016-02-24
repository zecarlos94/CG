#include <GL/glut.h>

#define _USE_MATH_DEFINES
#include <math.h>

float baseRadius = 0.1, height = 0.5;
int slices = 5 , stacks = 3;

void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if (h == 0) h = 1;

	// compute window's aspect ratio 
	float ratio = w * 1.0 / h;

	// Set the projection matrix as current
	glMatrixMode(GL_PROJECTION);

	// Load Identity Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set perspective
	gluPerspective(45.0f, ratio, 1.0f, 1000.0f);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}



void renderScene(void) {

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	gluLookAt(2.5, 0.0, 2.5, 0.0, 0.0, 0.0, 0.0f, 1.0f, 0.0f);

	// put drawing instructions here
    glutWireCone (baseRadius,height,slices,stacks);
    //enable growing effect
    if (baseRadius < 1.5 | height < 1.5 | slices < 15 | stacks < 30) {
        baseRadius+=0.01;
        height+=0.01;
        slices+=1;
        stacks+=1;
    }

	// End of frame
	glutSwapBuffers();
}




int main(int argc, char **argv) {

	// put init here
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Aula 1");

	// put callback registration here
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);

	// OpenGL settings 
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	// enter GLUT's main loop
	glutMainLoop();

	return 1;
}