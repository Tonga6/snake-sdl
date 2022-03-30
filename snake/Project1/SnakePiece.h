#pragma once
#include "GameObject.h"
enum movementDir {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	NONE
};
class SnakePiece : public GameObject {

public:
	SnakePiece() {};
	SnakePiece(const char* texSheet, SDL_Renderer* renderer);

	void Update();
	bool isIntersecting(SDL_Rect rect) { return SDL_HasIntersection(&GameObject::GetRect(), &rect); };

	void SetDir(movementDir newDir) { dir = newDir; };
	movementDir GetDir() { return dir; };
	bool hasNewDir = false;
	void MovePiece();
	movementDir dir = RIGHT;

private:
};

