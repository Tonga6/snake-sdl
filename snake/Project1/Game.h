#pragma once
#include "iostream"
#include "SDL.h"
#include "SDL_image.h"

struct Vec2 {
	Vec2() {};
	Vec2(float inX, float inY) {
		x = inX;
		y = inY;
	}
	float x, y;
	void Set(float newX, float newY) {
		x = newX; y = newY;
	};
	
	void Log() { std::cout << "x: " << x << ", y: " << y << std::endl; };
};



class Game {
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height);
	void handleEvents();
	void update();
	void render();
	void clean();
	void newCycle();
	bool checkRunning() { return isRunning; };

	template <typename T>
	static void Log(T var) { std::cout << var << std::endl; };
	bool IsFoodEaten();

private:
	const Uint8* key;
	bool isRunning = false;
	SDL_Window *window;
	SDL_Renderer* renderer;
	//void UpdateDirections(node* piece);
	void MoveSnake();
	//void UpdateDirections(movementDir newDir);
};