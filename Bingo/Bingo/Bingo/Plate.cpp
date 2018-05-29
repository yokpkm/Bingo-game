#include "Plate.h"
#include <GL\glut.h>
#include <vector>
#include "disc.h"

void Plate::draw() {
	drawPlate();
}

void Plate::drawPlate() {
	glBegin(GL_QUADS);
	glColor3f(0.51, 0.68, 0.89);
	glVertex3f(-width / 2, -height / 2.0, 0);
	glVertex3f(width / 2, -height / 2, 0);
	glVertex3f(width / 2, height / 2, 0);
	glVertex3f(-width / 2, height / 2, 0);
	glEnd();
}

Plate::Plate()
{
	width = 7;
	height = 6;
}

Plate::~Plate()
{
}

Board::Board() {
	width = 9;
	height = 8;
	discStatus.definePos(3, 3);
	discStatus.defineRGB(0, 0, 0);
	status = Status::black;
	for (int i = 0; i < nrow; i++)
	{
		for (int j = 0; j < ncol; j++)
		{
			pits[i][j].x = i - 3;
			pits[i][j].y = j - 3;
		}
	}
}

Board::~Board() {
}

Board::Board(float newWidth, float newHeight) {
	width = newWidth;
	height = newHeight;
}

void Board::draw() {
	drawPlate();
	for (int i = 0; i < nrow; i++) {
		for (int j = 0; j < ncol; j++) {
			glPushMatrix();
			glTranslatef(j - 3.0, i - 3.0, 0);
			pits[i][j].draw();
			glPopMatrix();
		}
	}
	discStatus.draw();
}