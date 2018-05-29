#pragma once
#include "Plate.h"
#include "Disc.h"
#include <vector>

class Game
{
public:
	Board board;
	Discs discsBlack;
	Discs discsRed;
	Disc discCurrent;
	enum Status { black = 0, red = 1 }status;

public:
	Game();
	~Game();
	void draw();
	void defineDiscCurrentPos(float x, float y);
	const int getNumberOfRow();
};

