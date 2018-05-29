#include "Game.h"

Game::Game()
{
	status = Status::black;
	discCurrent.definePos(0, 0);
}

Game::~Game()
{
}

void Game::draw()
{
	board.draw();
	discsBlack.draw();
	discsRed.draw();
	discCurrent.draw();
}

void Game::defineDiscCurrentPos(float newX, float newY)
{
	discCurrent.definePos(newX, newY);
}

const int Game::getNumberOfRow() {
	return Board::nrow;
}