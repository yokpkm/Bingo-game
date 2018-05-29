#pragma once
#include <vector>
class Pit
{
public:
	bool occupied;
	float r, g, b;
	float x, y;

public:
	Pit();
	~Pit();
	void draw();
	void draw(float x, float y);
	void toPos(float x, float y);
	void definePos(float newx, float newy);
	void defineRGB(float red, float green, float blue);
	void getPos(float & newx, float & newy);
};

