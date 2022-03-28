#pragma once
#include "GameObject.h"
enum movementDir {
	UP,
	DOWN,
	LEFT,
	RIGHT
};
class SnakePiece : public GameObject {

public:
	SnakePiece() {};
	SnakePiece(const char* texSheet, SDL_Renderer* renderer);

	void Update();
	bool isIntersecting(SDL_Rect rect) { return SDL_HasIntersection(&GameObject::GetRect(), &rect); };

	void SetDir(movementDir newDir) { dir = newDir; };

	void MovePiece();
private:
	movementDir dir;
};

