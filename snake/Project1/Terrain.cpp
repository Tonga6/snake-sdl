#include "Terrain.h"
#include "TextureManager.h"

Terrain::Terrain(const char* texSheet, SDL_Renderer* ren) {
	renderer = ren;
	objTex = TextureManager::LoadTexture(texSheet, renderer);
	pos->x = 0;
	pos->y = 0;
	dstRect.h = 32;
	dstRect.w = 32;
};