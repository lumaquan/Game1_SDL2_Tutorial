#pragma once
#include "Game.h"


class GameObject {

public:
	GameObject(const char* filename, SDL_Renderer* renderer);
	virtual ~GameObject();
	virtual void Update();
	virtual void Renderer();

protected:
	int xpos;
	int ypos;
	SDL_Rect srcRect;
	SDL_Rect destRect;

private:
	SDL_Texture* objTexture;
	SDL_Renderer* renderer;
};