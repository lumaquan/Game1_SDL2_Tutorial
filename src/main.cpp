#include "Game.h"
#include <iostream>

Game* game;


/*
		Some resources:
		https://github.com/xesxfs/SDL
*/


int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	game = new Game();

	Uint32 frameStart;
	int frameTime;

	game->init("Super Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (game->running())
	{
		frameStart = SDL_GetTicks();
		game->handle_events();
		game->update();
		game->render();
		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}

	}

	game->clean();

	delete game;
	return 0;
}