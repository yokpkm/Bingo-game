#include "Disc.h"
#include <GL/glut.h>
#include <math.h>

Disc::Disc()
{
	r = 0;
	g = 0;
	b = 0;
	x = 0;
	y = 0;
	yDown = 0.005;
}

Disc::~Disc()
{
}

void Disc::draw() {
	float pi = 3.14159265;
	glPushMatrix();

	glTranslatef(x, y, z);
	//glRotatef(90, 1, 0, 0);
	glScalef(0.43, 0.43, 0.43);
	glColor3f(r, g, b);

	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i <= 20; i++) {
		float theta = i * 2 * pi / 20;
		glVertex3f(cos(theta), sin(theta), 1);
		glVertex3f(cos(theta), sin(theta), 0);
	}
	glEnd();

	glBegin(GL_POLYGON);
	for (int i = 0; i < 20; i++) {
		float theta = i * (2 * pi / 20);
		glVertex3f(cos(theta), sin(theta), 1);
	}
	glEnd();

	glBegin(GL_POLYGON);
	for (int i = 0; i < 20; i++) {
		float theta = i * (2 * pi / 20);
		glVertex3f(cos(theta), sin(theta), 0);
	}
	glEnd();

	glPopMatrix();
}

void Disc::defineGrey50() {
	r *= 0.5;
	g *= 0.5;
	b *= 0.5;
}

void Disc::defineRGB(float red, float green, float blue) {
	r = red;
	g = green;
	b = blue;
}

void Disc::definePos(float px, float py) {
	x = px;
	y = py;
}

void Disc::defineFallDown(float fallDown) { // for disc down
	yDown = fallDown;
}

float Disc::getFallDown() {
	return yDown;
}

float Disc::getYPos() {
	return y;
}

void Disc::defineYPos(float py) {
	y = py;
}

Discs::Discs() {
}

Discs::~Discs() {
}

void Discs::add(Disc d) {
	disc.push_back(d);
}

void Discs::draw() {
	for (unsigned i = 0; i < disc.size(); i++) {
		disc[i].draw();
	}
}