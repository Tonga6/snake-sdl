#pragma once
#include "Game.h"


class GameObject {
public:
	GameObject(const char* texSheet, SDL_Renderer* renderer) {};
	GameObject() {};
	~GameObject() {};

	void Render() { SDL_RenderCopy(renderer, objTex, NULL, &dstRect); };
	Vec2 GetPos() { return Vec2(dstRect.x, dstRect.y); };
	void SetPos(Vec2 pos) {
		dstRect.x = pos.x;
		dstRect.y = pos.y;
	};
	void MoveRect() {};
	SDL_Rect GetRect() { return dstRect; };
	bool isIntersecting(SDL_Rect rect) { return SDL_HasIntersection(&GameObject::GetRect(), &rect); };

protected:
	SDL_Texture* objTex;
	SDL_Rect srcRect, dstRect;
	SDL_Renderer* renderer;
};