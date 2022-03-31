#include "Game.h"
#include "TextureManager.h"
#include "SnakePiece.h"
#include "Food.h"
struct node {
	SnakePiece* data;
	node* next;
	node* prev;
};
struct LinkedList {
	node* head;
	node* tail;

	void Add(SnakePiece* data) {
		node* newNode = new node;
		newNode->data = data;
		if (head == NULL) {
			head = newNode;
			tail = head;
			head->next = NULL;
			head->prev = NULL;
		}
		else {
			tail->next = newNode;
			newNode->prev = tail;
			newNode->next = NULL;
			tail = newNode;
		}
	}
};

Game::Game() {

}

Game::~Game() {

}
LinkedList* snake = new LinkedList;
Food* food = new Food;
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

		snake->head = NULL;
		snake->tail = NULL;
		SnakePiece* s;
		for (int i = 0; i < 4; i++) {
			s = new SnakePiece("Assets/1x/block.png", renderer);
			s->SetPos((width / 2 + ((i + 1) * 32)), height / 2);
			snake->Add(s);
		}
		food = new Food("Assets/1x/block.png", renderer);
		food->SetPos(220, 220);

		waitedTicks = SDL_GetTicks();
		targetTicks = waitedTicks + 2000;//2 seconds
	}
};

void Game::newCycle() {
	Log("New Cycle");
	MoveSnake();
	if (IsFoodEaten()) {
		SnakePiece* s;
		s = new SnakePiece("Assets/1x/block.png", renderer);
		snake->Add(s);
		s->SetPos(100,100);
		Log("FOOD ATE");
	}
	targetTicks = SDL_GetTicks() + 1000;
}

bool Game::IsFoodEaten() {
	if (snake->head->data->isIntersecting(food->GetRect()))
		return true;
	return false;
}
void UpdateDirections(node* n) {
	if (n->next != nullptr) {
		n->next->data->SetDir(n->data->GetDir());
		n->next->data->hasNewDir = true;
		n->data->hasNewDir = false;
	}
}

void Game::MoveSnake() {
	node* loop = snake->tail;
	while (loop != nullptr) {
		loop->data->MovePiece();
		if (loop->data->hasNewDir == true) {
			Log("Update Directions");
			UpdateDirections(loop);
		}
		loop = loop->prev;
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
		snake->head->data->SetDir(newDir);
		snake->head->data->hasNewDir = true;
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
	node* loop = snake->head;
	int i = 0;
	while (loop != NULL) {
		loop->data->Render();
		loop = loop->next;
		i++;
	}
	food->Render();
	SDL_RenderPresent(renderer);
};

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
};

