#pragma once
#include <vector>

class Disc
{
	float r, g, b;
	float x, y, z;
	float yDown;

public:
	Disc();
	~Disc();

	void draw();
	void defineRGB(float red, float green, float blue);
	void defineGrey50();

	void definePos(float px, float py);
	void defineFallDown(float fallDown);
	float getFallDown();
	float getYPos();
	void defineYPos(float py);
};

class Discs {
	std::vector<Disc> disc;
public:
	Discs();
	~Discs();
	void add(Disc d);
	void draw();
};

