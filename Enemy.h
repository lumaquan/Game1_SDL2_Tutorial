#pragma once

#include "GameObject.h"


class Enemy:public GameObject
{
public:
	Enemy(const char* filename, SDL_Renderer* renderer);
	~Enemy();
	void Update();

};