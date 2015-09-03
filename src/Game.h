#ifndef MAINGAME
#define MAINGAME

#include <SDL2\SDL.h>

#include <iostream>

#include "GameTick.h"
#include "GameData.h"
#include "GameInput.h"
#include "StateHandlerGen.h"
#include "input.h"

class game
{
public:
	~game();
	bool init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);
    void render();
    void update();
	bool running() { return _running; }
	void exit();

private:
	bool _running;

	SDL_Window* _window;
	SDL_Renderer* _renderer;
	SDL_GLContext _context;

	std::shared_ptr<stateHandlerGen> _stateHandler;
	std::shared_ptr<GameTick> _timer;
	std::shared_ptr<inputSystem> _input;
};

#endif
