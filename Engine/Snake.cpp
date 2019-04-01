#include "Snake.h"
#include <assert.h>
#include <ctime>

Snake::Snake(const Location& loc)
{
	constexpr int nBodyColor = 4;
	constexpr Color bodyColors[nBodyColor] = {
		{10,100,32},
		{10,130,48},
		{18,160,48},
		{10,130,48}
	};
	for (int i = 0; i < nSegmentsMax; i++) {
		segments[i].InitBody(bodyColors[i  % nBodyColor]);

	}
	segments[0].InitHead(loc);

}
void Snake::MoveBy(const Location& delta_loc)
{
	for (int i = nSegments - 1; i > 0; i--)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);
}

void Snake::Grow()
{
	if (nSegments < nSegmentsMax)
	{
		//segments[nSegments].InitBody();
		nSegments++;
	}
}

void Snake::Draw(Board& brd)const
{
	for(int i = 0; i<nSegments; i++)
	{
		segments[i].Draw(brd);
	}
}

bool Snake::IsInTile(const Location& target) const
{
	for (int i = 0; i < nSegments; i++)
		if (segments[i-1].getLocation() == target )
		{
			return true;
		}
	return false;
}


void Snake::Segment::InitHead(const Location& in_loc)
{
	loc = in_loc;
	c = Snake::headColor;
	
	
}

void Snake::Segment::InitBody(Color c_in)
{
	//c = Snake::bodyColor;
	c = c_in;
	
	
}

void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
	
}

void Snake::Segment::MoveBy(const Location& delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.Add(delta_loc);
}

Location Snake::getNextHeadLocation(const Location & delta_loc)const
{
	Location l(segments[0].getLocation());
	l.Add(delta_loc);
	return l;
}

void Snake::Segment::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);
}

const Location& Snake::Segment::getLocation() const
{
	return loc;
}
