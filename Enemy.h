#pragma once

#include "GameObject.h"


class Enemy :public GameObject
{
public:
	Enemy(const char* filename);
	~Enemy();
	void Update();

};