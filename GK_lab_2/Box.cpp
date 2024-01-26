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
	this->coeficientK = 5;
	this->scaleFlag = true;

	this->scaleStep = this->coeficientK / 100.0;
	this->scaleCounter = 1 + this->scaleStep;
}

void Box::update()
{
	if (this->getMaxY() * scaleCounter + this->y_offset + this->coeficientA * 0.5 * 0.5 > 580)
		flag = false;
	else if (this->getMinY() * scaleCounter + this->y_offset + this->coeficientA * 0.5 * 0.5 < 0)
		flag = true;

	if (flag == true)
		this->y_offset += this->coeficientA * 0.5 * 0.5;
	else if(flag == false)
		this->y_offset -= this->coeficientA * 0.5 * 0.5;
}

void Box::setCoeficientK(const GLint coeficientK)
{
	this->coeficientK = coeficientK;

	this->scaleStep = this->coeficientK / 100.0;
	this->scaleCounter = 1 + this->scaleStep;
}

void Box::setCoeficientA(const GLint coeficientA)
{
	this->coeficientA = coeficientA;
}

void Box::display()
{
	glLoadIdentity();

	glPushMatrix();


	glTranslatef(350.0f, y_offset, 0.0f);
	this->update();

	if (counter <= 100)
	{
		glScalef(scaleCounter, scaleCounter, 0);

		scaleCounter += scaleStep;
	}

	if (counter > 100)
	{
		scaleCounter -= scaleStep;
		glScalef(scaleCounter, scaleCounter, 0);
	}

	++counter;
	if (counter > 201)
	{
		counter = 0;
	}


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
