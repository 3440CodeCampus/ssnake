#include "Goal.h"

Goal::Goal(std::mt19937 & rng, const Board & brd, const Snake & snake)
{
	Respawn(rng, brd, snake);
}

void Goal::Respawn(std::mt19937 & rng, const Board & brd, const Snake & snake)
{
	std::uniform_int_distribution<int> xDist(0, brd.getGridWidth() - 1);
	std::uniform_int_distribution<int> yDist(0, brd.getGridHeight() - 1);
	
	Location newLoc;
	do {
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);
	} while (snake.IsInTile(newLoc)  && brd.IsInsideBoard(newLoc));

	loc = newLoc;


}

void Goal::Draw(Board & brd)
{
	brd.DrawCell(loc, c);
}

const Location& Goal::getLocation() const
{
	return loc;
}
