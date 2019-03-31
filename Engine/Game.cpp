
#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	brd(gfx), 
	rng(std::random_device()()),
	snek({8,8}),
	goal(rng, brd, snek)
{
}
// game no change
void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if(!gameIsOver)
	{
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		delta_loc = {1,0};
	}

	else if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		delta_loc={-1,0};
	}

	else if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		delta_loc={0,1};
	}

	else if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		delta_loc={0,-1};
	}
	snekMoveCounter++;
	if (snekMoveCounter >= snekMovePeriod)
	{
		snekMoveCounter = 0;
		const Location next = snek.getNextHeadLocation(delta_loc);
		if(!brd.IsInsideBoard(next) || snek.IsInTile(next))
		{
			gameIsOver = true;
		}
		else {
			//if (wnd.kbd.KeyIsPressed(VK_CONTROL))
			const bool eating = next == goal.getLocation();
			if(eating)
			{
				snek.Grow();
			}
			snek.MoveBy(delta_loc);
			if (eating)
			{
				goal.Respawn(rng, brd, snek);
			}
		}
	}

}
}

void Game::ComposeFrame()
{
	//brd.DrawWall();
	snek.Draw(brd);
	goal.Draw(brd);
	if (gameIsOver)
	{
		
		SpriteCodex::DrawGameOver(400, 300, gfx);
	}
	
	
}
