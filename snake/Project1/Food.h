#pragma once
#include "GameObject.h"

class Food : public GameObject {

public:
	Food() {};
	Food(const char* texSheet, SDL_Renderer* renderer);
	void Spawn() { SetPos(Vec2(rand()%25 * 32, rand()%18 * 32)); };
};

