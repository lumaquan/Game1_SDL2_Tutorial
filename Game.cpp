#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Enemy.h"
#include "Mapa.h"
#include <iostream>


GameObject* mario;
GameObject* browser;
Mapa* mapa;

SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{
}

Game::~Game()
{

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen)
{
	int flags = 0;
	if (fullScreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystem initialized " << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window created!" << std::endl;
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
			if (renderer)
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				std::cout << "Renderer created!" << std::endl;
				isRunning = true;
				mapa = new Mapa();
				mario = new GameObject("assets/mario_fighter.png");
				browser = new Enemy("assets/browser.png");
			}
		}
	}
	else
	{
		std::cout << "Failed to initialize subsystems" << std::endl;
		isRunning = false;
	}

}

void Game::handle_events()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{
	count++;
	mario->Update();
	browser->Update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	mapa->drawMap();
	mario->Renderer();
	browser->Renderer();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned!" << std::endl;
}

bool Game::running()
{
	return isRunning;;
}
