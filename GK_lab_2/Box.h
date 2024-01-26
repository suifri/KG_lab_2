#pragma once
#include <vector>
#include <GL/glut.h>

class Box
{
private:
	std::vector<std::vector<GLfloat>> dots;

public:
	Box();
	void display();
};

