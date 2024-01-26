#include "Box.h"

Box::Box()
{
	this->dots.push_back(std::vector<GLfloat> { 10.0f, 50.0f });
	this->dots.push_back(std::vector<GLfloat>{50.0f, 50.0f});
	this->dots.push_back(std::vector<GLfloat>{50.0f, 10.0f});
	this->dots.push_back(std::vector<GLfloat>{10.0f, 10.0f});
}

void Box::display()
{
	glColor3f(1, 0, 0);
	glBegin(GL_QUADS);

	for(std::vector<GLfloat> vertexes : this->dots)
		glVertex2f(vertexes.at(0), vertexes.at(1));

	glEnd();
}
