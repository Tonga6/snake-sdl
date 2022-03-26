#include "SnakePiece.h"
#include "TextureManager.h"


SnakePiece::SnakePiece(const char* texSheet, SDL_Renderer* ren) {
	renderer = ren;
	objTex = TextureManager::LoadTexture(texSheet, renderer);
	pos->x = 100;
	pos->y = 100;
	dstRect.h = 32;
	dstRect.w = 32;
};

void SnakePiece::Update() {

	dstRect.x = pos->x;
	dstRect.y = pos->y;
	
	dstRect.h = 64;

};

