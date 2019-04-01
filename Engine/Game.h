
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Board.h"
#include <random>
#include "Location.h"
#include "Snake.h"
#include "Goal.h"
class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	/********************************/
	Board brd;
	Snake snek;
	Location delta_loc = { 1,0 };	
	std::mt19937 rng;
	Goal goal;
	static constexpr int snekMovePeriod = 20;
	int snekMoveCounter = 0;
	bool gameIsOver = false;
	bool gameIsStarted = false;
};