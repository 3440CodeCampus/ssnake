#include "Board.h"

Board::Board(Graphics & gfx)
	:
	gfx(gfx)
{}

void Board::DrawCell(const Location& loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);
	gfx.DrawRectDim((loc.x*dimension), (loc.y*dimension), dimension, dimension, c);
}
int Board::getGridWidth() const
{
	return width;
}

int Board::getGridHeight() const
{
	return height;
}

bool Board::IsInsideBoard(const Location& loc) const
{
	 bool result = loc.x *20 >= 20 && loc.x*20 < gfx.ScreenWidth - 25 &&
		loc.y *20 >= 20 && loc.y*20 < gfx.ScreenHeight - 25;
	 return result;
	// return loc.x >= 0 && loc.x < width &&
	//	loc.y >= 0 && loc.y < height;
}

void Board::DrawWall() const
{
	int scrWidth = gfx.ScreenWidth;
	int scrHeight = gfx.ScreenHeight;
	int thick = 0;
	do {
		for (int x = 20; x <= scrWidth - 20; x++)
			{
				gfx.PutPixel(x, 20+thick, 152, 234, 230);
				gfx.PutPixel(x, 575 + thick, 152, 234, 230);
			}
		thick++;
	} while (thick <= 5);
	thick = 0;
	do {
		for (int y = 20; y <= scrHeight - 20; y++)
		{
			gfx.PutPixel(20+thick, y, 152, 234, 230);
			gfx.PutPixel(775+thick, y, 152, 234, 230);
		}
		thick++;
	} while (thick <= 5);
	

}
