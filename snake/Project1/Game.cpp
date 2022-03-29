#include "Game.h"
#include "TextureManager.h"
#include "SnakePiece.h"

template<class L>
struct node {
	L* data;
	node* next;
};
template<class L>
struct LinkedList {
	node<L>* head;
	node<L>* tail;

	void Add(node<L>* newNode) {
		if (head == NULL) {
			head = newNode;
			tail = head;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}
};

Game::Game() {

}

Game::~Game() {

}
LinkedList<SnakePiece>* snake = new LinkedList<SnakePiece>;
LinkedList<SnakePiece>* dirQueue = new LinkedList<SnakePiece>;
//LinkedList<LinkedList>* dirQueue = new LinkedList<LinkedList>;
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

		node<SnakePiece>* n;
		node<SnakePiece>* temp = nullptr;
		dirQueue->head = nullptr;
		dirQueue->tail = dirQueue->head;

		int startCount = 4;
		for (int i = 0; i < 4; i++) {
			n = new node<SnakePiece>;
			n->data = new SnakePiece("Assets/1x/block.png", renderer);
			n->data->SetPos((width / 2 + ((i + 1) * 32)),height/2);
			n->next = temp;
			if (i == startCount-1)
				snake->head = n;
			if (i == 0)
				snake->tail = n;
			
			temp = n;
		}
		waitedTicks = SDL_GetTicks();
		targetTicks = waitedTicks + 2000;//2 seconds
	}
};

void Game::newCycle() {
	Log("New Cycle");
	node<SnakePiece>* loop = snake->head;
	while (loop != NULL) {
		loop->data->MovePiece();
		loop = loop->next;
	}
	UpdateDirections();
	targetTicks = SDL_GetTicks() + 1000;
}
void Game::UpdateDirections() {
	node<SnakePiece>* loop = dirQueue->head;
	while (loop != NULL && loop->next != NULL) {
		loop->next->data->SetDir(loop->data->GetDir());
		loop = loop->next;
	}
}
void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	movementDir newDir = NONE;
	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			key = SDL_GetKeyboardState(nullptr);
			
			if (key[SDL_SCANCODE_W]) {
				Log("W");
				newDir = UP;
			}
			else if (key[SDL_SCANCODE_A]) {
				Log("A");
				newDir = LEFT;
			}

			else if (key[SDL_SCANCODE_S]) {
				Log("S");
				newDir = DOWN;

			}
			else if (key[SDL_SCANCODE_D]) {
				Log("D");
				newDir = RIGHT;
			}
		default:
			break;
	}
	if (newDir != NONE) {
		snake->head->data->SetDir(newDir);
		dirQueue->Add(snake->head);
	}


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
	node<SnakePiece>* loop = snake->head;
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

