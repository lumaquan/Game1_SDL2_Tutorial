#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* filename) : xpos{ 0 }, ypos{ 0 }
{
	objTexture = TextureManager::LoadTexture(filename);
}

GameObject::~GameObject()
{

}

void GameObject::Update()
{
	xpos += 1;
	ypos += 1;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.h = 64;
	srcRect.w = 64;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.h = 64;
	destRect.w = 64;
}

void GameObject::Renderer()
{
	SDL_RenderCopy(Game::renderer, objTexture, NULL, &destRect);
}


