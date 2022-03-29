#include "SDL.h"
#include "stdio.h"
#include "Game.h"

Game *game = nullptr;
int main(int argc, char* argv[]) {
	const int fps = 60;
	const int frameDelay = 1000 / fps;

	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->init("Golf", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600);

	//loop while game is running
	while (game->checkRunning()) {
		frameStart = SDL_GetTicks();
		game->handleEvents();
		game->update();
		game->render();
		frameTime = SDL_GetTicks() - frameStart;

		//limit fps to 60
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}

	//else clean up before quitting
	game->clean();
	return 0;
}

