#include "Box.h"

Box::Box()
{
	this->dots.push_back(std::vector<GLfloat> { 10.0f, 50.0f });
	this->dots.push_back(std::vector<GLfloat>{50.0f, 50.0f});
	this->dots.push_back(std::vector<GLfloat>{50.0f, 10.0f});
	this->dots.push_back(std::vector<GLfloat>{10.0f, 10.0f});

	this->y_offset = 10;
	this->flag = true;
	this->coeficientA = 2;
	this->screenHeight = 580;
	this->coeficientK = 2;
}

void Box::update()
{
	if (this->getMaxY() + this->y_offset + this->coeficientA * 0.5 * 0.5 > 580)
		flag = false;
	else if (this->getMinY() + this->y_offset + this->coeficientA * 0.5 * 0.5 < 0)
		flag = true;

	if (flag == true)
		this->y_offset += this->coeficientA * 0.5 * 0.5;
	else if(flag == false)
		this->y_offset -= this->coeficientA * 0.5 * 0.5;
}

void Box::display()
{
	glLoadIdentity();

	glPushMatrix();

	glTranslatef(350.0f, y_offset, 0.0f);

	this->update();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
	for (std::vector<GLfloat> vertexes : this->dots)
		glVertex3f(vertexes.at(0), vertexes.at(1), 0);
	glEnd();

	glPopMatrix();
	glutSwapBuffers();
}

GLfloat Box::getMaxY()
{
	GLfloat maxY = 0.0;

	for (std::vector<GLfloat> iter : this->dots)
		if (iter.at(1) > maxY)
			maxY = iter.at(1);

	return maxY;
}

GLfloat Box::getMinY()
{
	GLfloat minY = 0.0;

	for (std::vector<GLfloat> iter : this->dots)
		if (iter.at(1) < minY)
			minY = iter.at(1);

	return minY;
}
