#pragma once
#include "iostream"
#include "SDL.h"
#include "SDL_image.h"
struct Vec2 {
	float x, y;
	void Set(float newX, float newY) {
		x = newX; y = newY;
	}
	
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

	bool checkRunning() { return isRunning; };

	template <typename T>
	static void Log(T var) { std::cout << var << std::endl; };


private:
	bool isRunning = false;
	SDL_Window *window;
	SDL_Renderer* renderer;
};