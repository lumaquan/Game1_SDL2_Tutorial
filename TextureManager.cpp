#include "TextureManager.h"
#include "SDL_image.h"

SDL_Texture* TextureManager::LoadTexture(const char* filename)
{
	SDL_Surface* tempSurface = IMG_Load(filename);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);
	return tex;
}

void TextureManager::Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Game::renderer, texture,&src, &dest);
}
