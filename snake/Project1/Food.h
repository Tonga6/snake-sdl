#pragma once
#include "GameObject.h"

class Food : public GameObject {

public:
	Food() {};
	Food(const char* texSheet, SDL_Renderer* renderer);

};

