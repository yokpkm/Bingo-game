#include <GL/glut.h>      
#include <stdio.h>
#include <math.h>
#include "Game.h"
#include <iostream>

#define RED 1.0,0.0,0.0		// RGB code for red color
#define WHITE_A 1.0,1.0,1.0,1.0 //REG code for white and alpha
Game game;
//bool flipDiscCurrent = false;
int colorMode = 0;
float phi = 3.14159265;
float deltaPhi = 0;
float fallPos = 0;

float unitWidth;
float unitHeight;
float unitx;
float unity;

// WCS volume limit
float left = -4;
float right = 4;
float bottom = -4;
float top = 4;
float znear = 0;
float zfar = -12.0;

float leftAspect = 0;
float rightAspect = 0;
float topAspect = 0;
float bottomAspect = 0;

// RCS for window  limit
int win_width = 800;
int win_height = 600; 
float win_position_x = 0;
float win_position_y = 0;

// mouse position start
float xstart = 0;
float ystart = 0;

int mouseTest = true;

void mouse(int button, int state, int x, int y) {
	float unit_x = (float)x / win_width * (rightAspect - leftAspect) + leftAspect;
	float unit_y = (float)(win_height - y) / win_height * (topAspect - bottomAspect) + bottomAspect;
	printf("mouse x=%d, y=%d, unit_x = %d, unit_y = %d\n", x, y, unit_x, unit_y);
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		game.defineDiscCurrentPos(floor(unit_x + 0.5), floor(unit_y + 0.5));
		int currentx = (int)floor(unitx + 0.5);
		for (int j = 0; j < game.board.nrow; j++)
		{
			if (game.board.pits[currentx + 3][j].occupied == false) {
					game.discCurrent.definePos(game.board.pits[currentx + 3][j].x, game.board.pits[currentx + 3][j].y);
					if (game.status == Game::Status::red)
					//if (game.board.status == Game::Status::red)
					//ลงแถวล่าง คอลัมน์สุดท้าย[3][3] แล้วมันเด้งไปที่จุด(0,0)
					//เช็คใน board(plate.cpp) i คือ nrow, j คือ ncol
					//แก้ให้ลงไม่ทับกันยังไม่ได้, ลงคอลัมน์สุดท้ายไม่ได้
					{
						game.discsRed.add(game.discCurrent);
						game.discCurrent.defineRGB(0, 0, 0);
						game.status = Game::Status::black;
						game.board.discStatus.defineRGB(0, 0, 0);
					}
					else
					{
						game.discsBlack.add(game.discCurrent);
						game.discCurrent.defineRGB(1, 0, 0);
						game.status = Game::Status::red;
						game.board.discStatus.defineRGB(1, 0, 0);
					}
					break;
			}
			else
			{
				continue;
			}
		}

		/*if (game.status == Game::Status::black)
		{
			game.discsBlack.add(game.discCurrent);
			game.status = Game::Status::red;
			game.discCurrent.defineRGB(1, 0, 0);
			game.board.discStatus.defineRGB(1, 0, 0);
			game.status = Game::Status::red;
		}
		else
		{
			game.discsRed.add(game.discCurrent);
			game.status = Game::Status::black;
			game.discCurrent.defineRGB(0, 0, 0);
			game.board.discStatus.defineRGB(0, 0, 0);
			game.status = Game::Status::black;
		}*/
	}
	glutPostRedisplay();
}

void motion(int x, int y)
{
	int unitWidth = rightAspect - leftAspect;
	int unitHeight = topAspect - bottomAspect;
	int unitx = (float)x / win_width * unitWidth - unitWidth / 2.0;
	int unity = (float)(win_height - y) / win_height * unitHeight - unitHeight / 2.0;
}

void passiveMotion(int x, int y) {
	if (mouseTest == true) {
		unitWidth = rightAspect - leftAspect;
		unitHeight = topAspect - bottomAspect;
		unitx = (float)x / win_width * unitWidth + leftAspect;
		unity = (float)(win_height - y) / win_height * unitHeight + bottomAspect;
		game.defineDiscCurrentPos(unitx, unity);
		printf("x=%.3f, y=%.3f\n", unitx, unity);
		glutPostRedisplay();
	}
}

void init(void) {
	glClearColor(WHITE_A);                 // Set display-window color to white.

	glMatrixMode(GL_PROJECTION);           // Set projection parameters.
	glLoadIdentity();
	glOrtho(left, right, bottom, top, znear, zfar);
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);            // Clear display window.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	game.draw();

	glFlush();     // Process all OpenGL routines as quickly as possible.
}

void reshape(int w, int h) {
	// update display
	win_width = w;
	win_height = h;
	// calculate aspect ratio
	float aspect = (float)w / h;

	// set viewport
	glViewport(0, 0, w, h);

	// set matrix mode to projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (aspect >= 1.0) {
		leftAspect = left * aspect;
		rightAspect = right * aspect;
		bottomAspect = bottom;
		topAspect = top;
	}
	else {
		leftAspect = left;
		rightAspect = right;
		bottomAspect = bottom / aspect;
		topAspect = top / aspect;
	}
	glOrtho(leftAspect, rightAspect, bottomAspect, topAspect, znear, zfar);

	glutPostRedisplay();
}

void keyboard(unsigned char c, int w, int h) {
	switch (c) {

	default:break;
	}
	glutPostRedisplay();
}

void idle() {

		/*if (fallPos <= -3) {
			fallPos == -3;
		}*/

	glutPostRedisplay();
}

void main(int argc, char** argv) {
	// initializing routine
	glutInit(&argc, argv);                              // Initialize GLUT.
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);        // Set display mode.
	glutInitWindowPosition(win_position_x, win_position_y); //Set top-left display-window position.
	glutInitWindowSize(win_width, win_height); // Set display-window width and height.
	glutCreateWindow("BINGO GAME");     // Create display window.

													   //user initialization routine
	init();															// user initializing routine

																	//callback register function
	glutDisplayFunc(display);					// Send graphics to display window.
	glutMouseFunc(mouse);								// callback for mouse button and position
	glutMotionFunc(motion);							// callback for mouse motion
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(idle);
	glutPassiveMotionFunc(passiveMotion);
	glutMainLoop();										// Loop over registered function
}														// Display everything and wait.
