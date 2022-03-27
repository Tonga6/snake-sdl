#include "Game.h"
#include "TextureManager.h"
#include "SnakePiece.h"

struct Node {
	SnakePiece* data;
	Node* next;
};
Game::Game() {

}

Game::~Game() {

}
Node* head;
Node* tail;
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
				head = n;
			else
				temp = n;
		}
		
	}
};

void Game::handleEvents() {

};

void Game::update() {
};

void Game::render() {
	SDL_RenderClear(renderer);
	Node* loop = head;
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

