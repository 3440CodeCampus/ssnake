#pragma once
#include "Graphics.h"
#include "Location.h"
#include <assert.h>

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c);
	int getGridWidth() const;
	int getGridHeight() const;
	bool IsInsideBoard(const Location& loc)const;
	//void DrawWall()const;

private:
	static constexpr int dimension = 20;
	static constexpr int width = 40;
	static constexpr int height = 30;
	
	Graphics& gfx;

};
