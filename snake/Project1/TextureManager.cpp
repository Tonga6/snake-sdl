#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture, SDL_Renderer* renderer) {
	SDL_Texture* tex = IMG_LoadTexture(renderer, texture);
	return tex;
}