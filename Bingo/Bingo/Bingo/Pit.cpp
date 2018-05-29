#include "Pit.h"
#include <math.h>
#include <GL/glut.h>

Pit::Pit()
{
	occupied = false;
	r = 0;
	g = 0;
	b = 0;
}

Pit::~Pit()
{
}

void Pit::draw() {
	int npit = 42;
	float radius = 0.4;
	glColor3f(1, 1, 1); // pit color
	glBegin(GL_POLYGON);
	for (int i = 0; i < npit; i++) {
		float pi = 3.14159265;
		float thetar = i * 2.0* pi / npit;
		float x = radius * cos(thetar);
		float y = radius * sin(thetar);
		glVertex2f(x, y);
	}
	glEnd();
}

void Pit::draw(float posx, float posy) {
	glPushMatrix();
	toPos(posx, posy);
	draw();
	glPopMatrix();
}

void Pit::defineRGB(float red, float green, float blue) {
	r = red;
	g = green;
	b = blue;
}

void Pit::toPos(float newx, float newy) {
	glTranslatef(newx, newy, 0);
}

void Pit::definePos(float newx, float newy) {
	x = newx;
	y = newy;
}

void Pit::getPos(float & newx, float & newy) {
	newx = x;
	newy = y;
}

