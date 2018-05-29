#pragma once
#include "Pit.h"
#include <vector>
#include "Disc.h"

class Plate
{
protected:
	float width;
	float height;

public:
	Plate();
	~Plate();
	virtual void draw();

protected:
	void drawPlate();
};

class Board : Plate {
public:
	static const int nrow = 6;
	static const int ncol = 7;

	Disc blackDisc, redDisc;
	enum Status { black, red } status;

public:
	Disc discStatus;
	Pit pits[nrow][ncol];

public:
	Board();
	~Board();
	Board(float newWidth, float newHeight);
	void draw();
};
