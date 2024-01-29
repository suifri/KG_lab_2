#include "Box.h"

Box::Box()
{
	this->dots.push_back(std::vector<GLfloat> { 10.0f, 50.0f });
	this->dots.push_back(std::vector<GLfloat>{50.0f, 50.0f});
	this->dots.push_back(std::vector<GLfloat>{50.0f, 10.0f});
	this->dots.push_back(std::vector<GLfloat>{10.0f, 10.0f});

	this->y_offset = 10;
	this->x_offset = 2;
	this->flag = true;
	this->coeficientA = 2;
	this->screenHeight = 580;
	this->coeficientK = 5;
	this->scaleFlag = true;
	this->screenWidth = 740;
	this->currentX = this->screenWidth / 2.0;
	this->xFlag = true;

	this->scaleStep = this->coeficientK / 100.0;
	this->scaleCounter = 1 + this->scaleStep;
}

void Box::update()
{
	GLboolean testingFlag = true;

	if (this->getMaxY()  + this->y_offset + this->coeficientA * this->x_offset * this->x_offset + 5> 580)
	{
		flag = false;

		if (xFlag == false)
			xFlag = true;
		else if (xFlag == true)
			xFlag = false;
	}
	else if (this->getMinY()  + this->y_offset + this->coeficientA * this->x_offset * this->x_offset - 5< 0)
	{
		flag = true;
		testingFlag = true;
	}

	if (flag == true)
	{
		this->y_offset += this->coeficientA * this->x_offset * this->x_offset;
		this->x_offset += 0.01;
	}
	
	else if (flag == false)
	{
		this->y_offset -= this->coeficientA * this->x_offset * this->x_offset;
		this->x_offset -= 0.01;
	}


	if (this->xFlag == true)
	{
		this->currentX += 5;
	}
	else if (this->xFlag == false)
	{
		this->currentX -= 5;
		
	}

}

void Box::setCoeficientK(const GLint coeficientK)
{
	this->coeficientK = coeficientK;

	this->scaleStep = this->coeficientK / 100.0;
	this->scaleCounter = 1 + this->scaleStep;
}

GLfloat Box::getMinX()
{
	GLfloat minX = 0.0;

	for (std::vector<GLfloat> iter : this->dots)
		if (iter.at(0) < minX)
			minX = iter.at(0);

	return minX;
}

GLfloat Box::getMaxX()
{
	GLfloat maxX = 0.0;

	for (std::vector<GLfloat> iter : this->dots)
		if (iter.at(0) > maxX)
			maxX = iter.at(0);

	return maxX;
}

void Box::setCoeficientA(const GLint coeficientA)
{
	this->coeficientA = coeficientA;
}

void Box::display()
{
	glLoadIdentity();

	glPushMatrix();


	glTranslatef(currentX, y_offset, 0.0f);
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
