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
	GLboolean scaleFlag;
	int counter = 0;
	GLfloat scaleCounter = 0;
	GLfloat scaleStep = 0;

	void update();
	GLfloat getMaxY();
	GLfloat getMinY();
public:
	Box();
	void display();
	void setCoeficientA(const GLint coeficientA);
	void setCoeficientK(const GLint coeficientK);
};

