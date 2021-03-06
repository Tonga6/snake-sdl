#include "SnakePiece.h"
#include "TextureManager.h"


SnakePiece::SnakePiece(const char* texSheet, SDL_Renderer* ren) {
	renderer = ren;
	objTex = TextureManager::LoadTexture(texSheet, renderer);
	dstRect.x = 100;
	dstRect.y = 100;
	dstRect.h = 32;
	dstRect.w = 32;
	//dir = RIGHT;
};

void SnakePiece::MovePiece() {
	switch (dir) {
		case UP:
			dstRect.y -= 32;
			break;
		case DOWN:
			dstRect.y += 32;
			break;
		case LEFT:
			dstRect.x -= 32;
			break;
		case RIGHT:
			dstRect.x += 32;
			break;
		default:
			break;

	}
}
void SnakePiece::Update() {
	
	dstRect.h = 64;

};

