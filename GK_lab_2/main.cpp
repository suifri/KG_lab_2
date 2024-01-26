#include <GL/glut.h>

const int SCREEN_WIDTH = 740;
const int SCREEN_HEIGHT = 580;

void init()
{
	glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1); 
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(400, 200);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Lab 2");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}

