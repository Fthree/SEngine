#include "game.h"

game::~game()
{
	exit();
}

bool game::init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen)
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		_window = SDL_CreateWindow(title, xPos, yPos, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

		_context = SDL_GL_CreateContext(_window);

		if (_context)
		{
			glewExperimental = GL_TRUE;
			GLenum glewError = glewInit();
			if (glewError != GLEW_OK)
			{
				printf("Error initializing GLEW! %s\n", glewGetErrorString(glewError));
			}
		}
    }

	SDL_GL_SetSwapInterval(1);

	std::cout << "SDL init success \n";

	_timer = std::shared_ptr<GameTick>(new GameTick);
	
	int currentWindowWidth = 0;
	int currentWindowHeight = 0;
	SDL_GetWindowSize(_window, &currentWindowWidth, &currentWindowHeight);

	gameData::instance().setData(_renderer, _window, xPos, yPos, currentWindowWidth, currentWindowHeight, fullscreen);

	_stateHandler = std::shared_ptr<stateHandlerGen>(new stateHandlerGen);
	_input.reset(new inputSystem);

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");


	_running = true;

	return true;
}

void game::render()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	_stateHandler->render(_timer->getdt());

	SDL_GL_SwapWindow(_window);
}

void game::update()
{
	_running = gameData::instance().getExit();

	SDL_Event e;

	while (SDL_PollEvent(&e) != 0)
	{
		gameInput::instance().getFrameEvents().push_back(e);
	}

	_timer->FPSCounter();
	_timer->FPSString(50);
	_stateHandler->update(_timer->getdt());

	gameInput::instance().clearEvents();
}

void game::exit()
{
	std::cout << "cleaning game \n";

	_stateHandler.reset();
	_stateHandler = nullptr;

	std::cout << "game cleaned\n";

	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();

	std::cout << "SDL cleaned \n\nfinalized cleaning \n";
}

