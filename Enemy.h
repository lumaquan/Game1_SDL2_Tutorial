#pragma once

#include "GameObject.h"


class Enemy :public GameObject
{
public:
	Enemy(const char* filename);
	virtual ~Enemy();
	void Update();
};