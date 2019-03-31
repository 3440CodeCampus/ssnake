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
	gfx.DrawRectDim(loc.x*dimension, loc.y*dimension, dimension, dimension, c);
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
	return loc.x +10  >= 10 && loc.x < gfx.ScreenWidth - 10 &&
		loc.y +10 >= 10 && loc.y < gfx.ScreenHeight - 10;

	// return loc.x >= 0 && loc.x < width &&
	//	loc.y >= 0 && loc.y < height;
}

void Board::DrawWall() const
{
	int scrWidth = gfx.ScreenWidth;
	int scrHeight = gfx.ScreenHeight;
	int thick = 0;
	do {
		for (int x = 10; x <= scrWidth - 10; x++)
			{
				gfx.PutPixel(x, 5+thick, 152, 234, 230);
				gfx.PutPixel(x, 585 + thick, 152, 234, 230);
			}
		thick++;
	} while (thick <= 5);
	thick = 0;
	do {
		for (int y = 10; y <= scrHeight - 10; y++)
		{
			gfx.PutPixel(10+thick, y, 152, 234, 230);
			gfx.PutPixel(785+thick, y, 152, 234, 230);
		}
		thick++;
	} while (thick <= 5);
	

}
