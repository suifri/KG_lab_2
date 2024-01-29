#pragma once
#include <vector>
#include <GL/glut.h>
#include <iostream>

class Box
{
private:
	std::vector<std::vector<GLfloat>> dots;
	GLfloat y_offset;
	GLfloat x_offset;
	GLfloat currentX;
	GLboolean flag;
	GLboolean xFlag;
	GLint coeficientA;
	GLint screenHeight;
	GLint screenWidth;
	GLint coeficientK;
	GLboolean scaleFlag;
	int counter = 0;
	GLfloat scaleCounter = 0;
	GLfloat scaleStep = 0;

	void update();
	GLfloat getMaxY();
	GLfloat getMinY();
	GLfloat getMinX();
	GLfloat getMaxX();
public:
	Box();
	void display();
	void setCoeficientA(const GLint coeficientA);
	void setCoeficientK(const GLint coeficientK);
};

