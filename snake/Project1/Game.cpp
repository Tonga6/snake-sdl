#include "Game.h"
#include "TextureManager.h"
#include "SnakePiece.h"

struct Node {
	SnakePiece* data;
	Node* next;
};
struct LinkedList {
	Node* head;
};
Game::Game() {

}

Game::~Game() {

}
LinkedList* snake = new LinkedList;
float targetTicks, waitedTicks;
//set up SDL window and renderer
void Game::init(const char* title, int xpos, int ypos, int width, int height) {
	int flags = 0;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window == 0) {
			std::cout << "Error creating window" << std::endl;
			return;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer == 0) {
			std::cout << "Error creating renderer" << std::endl;
			return;
		}
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		isRunning = true;

		Node* n;
		Node* temp = nullptr;
		int startCount = 4;
		for (int i = 0; i < 4; i++) {
			n = new Node;
			n->data = new SnakePiece("Assets/1x/block.png", renderer);
			n->data->SetPos((width / 2 + ((i + 1) * 32)),height/2);
			n->next = temp;
			if (i == startCount-1)
				snake->head = n;
			else
				temp = n;
		}
		waitedTicks = SDL_GetTicks();
		targetTicks = waitedTicks + 2000;//2 seconds
	}
};

void Game::newCycle() {
	Log("New Cycle");
	targetTicks = SDL_GetTicks() + 2000;
}
void Game::handleEvents() {

};

void Game::update() {
	if (waitedTicks > targetTicks) {
		newCycle();
	}
	else {
		waitedTicks = SDL_GetTicks();
	}
};

void Game::render() {
	SDL_RenderClear(renderer);
	Node* loop = snake->head;
	while (loop != NULL) {
		loop->data->Render();
		loop = loop->next;
	}

	SDL_RenderPresent(renderer);
};

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
};

