#include "SnakePiece.h"
#include "TextureManager.h"


SnakePiece::SnakePiece(const char* texSheet, SDL_Renderer* ren) {
	renderer = ren;
	objTex = TextureManager::LoadTexture(texSheet, renderer);
	dstRect.x = 100;
	dstRect.y = 100;
	dstRect.h = 32;
	dstRect.w = 32;
};

void SnakePiece::Update() {
	
	dstRect.h = 64;

};

