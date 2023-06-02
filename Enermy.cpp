#include "Enemy.h"

Enemy::Enemy(const char* filename, SDL_Renderer* renderer):GameObject(filename, renderer) 
{
	xpos = 400;
	ypos = 0;
}

Enemy::~Enemy()
{
	
}

void Enemy::Update()
{
	xpos += -1;
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

