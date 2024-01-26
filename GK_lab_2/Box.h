#pragma once
#include <vector>
#include <GL/glut.h>

class Box
{
private:
	std::vector<std::vector<GLfloat>> dots;
	GLfloat y_offset;
	GLboolean flag;
	GLint coeficientA;
	GLint screenHeight;
	GLint coeficientK;

	void update();
	GLfloat getMaxY();
	GLfloat getMinY();
public:
	Box();
	void display();
};

