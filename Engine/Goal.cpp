#include "Goal.h"
#include "Graphics.h"

Goal::Goal(std::mt19937 & rng, const Board & brd, const Snake & snake)
{
	Respawn(rng, brd, snake);
}

void Goal::Respawn(std::mt19937 & rng, const Board & brd, const Snake & snake)
{
	std::uniform_int_distribution<int> xDist(2, brd.getGridWidth() - 2);
	std::uniform_int_distribution<int> yDist(2, brd.getGridHeight() - 2);
	
	Location newLoc;
	
	do {
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);

		
	} while (snake.IsInTile(newLoc));

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
