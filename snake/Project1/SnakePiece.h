#pragma once
#include "GameObject.h"
class SnakePiece : public GameObject {
public:
	SnakePiece() {};
	SnakePiece(const char* texSheet, SDL_Renderer* renderer);

	void Update();
	bool isIntersecting(SDL_Rect rect) { return SDL_HasIntersection(&GameObject::GetRect(), &rect); };

private:

};