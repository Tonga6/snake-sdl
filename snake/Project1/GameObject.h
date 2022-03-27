#pragma once
#include "Game.h"


class GameObject {
public:
	GameObject(const char* texSheet, SDL_Renderer* renderer) {};
	GameObject() {};
	~GameObject() {};

	void Render() { SDL_RenderCopy(renderer, objTex, NULL, &dstRect); };
	void SetPos(int xPos, int yPos) {
		dstRect.x = xPos;
		dstRect.y = yPos;
	};
	void MoveRect() {};
	SDL_Rect GetRect() { return dstRect; };
protected:
	SDL_Texture* objTex;
	SDL_Rect srcRect, dstRect;
	SDL_Renderer* renderer;
};