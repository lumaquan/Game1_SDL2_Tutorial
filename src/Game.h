#ifndef GAME_H 
#define GAME_H 

#include "SDL.h"

class Game {
public:
	Game();
	~Game();
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen);
	void handle_events();
	void update();
	void render();
	void clean();
	bool running();

private:
	int count = 0;
	bool isRunning = false;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
};

#endif GAME_H


