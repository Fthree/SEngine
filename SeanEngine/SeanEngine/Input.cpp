#include "input.h"

inputSystem::inputSystem()
: _keyState(0)
{
	_keyUp = true;
	if (_mouseBtnStates.size() == 0)
	{
		initMouse();
	}
}

void inputSystem::initMouse()
{
	for(int i = 0; i < 5; i++)
	{
		_mouseBtnStates.push_back(false);
	}
}

bool inputSystem::isKeyDown(SDL_Scancode key)
{
	if (_keyState)
	{
		if (_keyState[key])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

void inputSystem::onKeyDown()
{
	_keyState = SDL_GetKeyboardState(0);
}

void inputSystem::onKeyUp()
{
	_keyState = SDL_GetKeyboardState(0);
}

bool inputSystem::getMouseBtnState(int mouseButton)
{
	return _mouseBtnStates[mouseButton];
}

void inputSystem::onMouseBtnDown(SDL_Event &event)
{
	SDL_MouseButtonEvent k;

	switch (event.button.button)
	{
	case SDL_BUTTON_LEFT:
		_mouseBtnStates[LEFT] = true;
		break;
	case SDL_BUTTON_MIDDLE:
		_mouseBtnStates[MIDDLE] = true;
		break;
	case SDL_BUTTON_RIGHT:
		_mouseBtnStates[RIGHT] = true;
		break;
	case SDL_BUTTON_X1:
		_mouseBtnStates[X1] = true;
		break;
	case SDL_BUTTON_X2:
		_mouseBtnStates[X2] = true;
		break;
	}
}

void inputSystem::onMouseBtnUp(SDL_Event &event)
{
	switch (event.button.button)
	{
	case SDL_BUTTON_LEFT:
		_mouseBtnStates[LEFT] = false;
		break;
	case SDL_BUTTON_MIDDLE:
		_mouseBtnStates[MIDDLE] = false;
		break;
	case SDL_BUTTON_RIGHT:
		_mouseBtnStates[RIGHT] = false;
		break;
	case SDL_BUTTON_X1:
		_mouseBtnStates[X1] = false;
		break;
	case SDL_BUTTON_X2:
		_mouseBtnStates[X2] = false;
		break;
	}

}

void inputSystem::onMouseMove(SDL_Event &event)
{
	int dx = 0;
	int dy = 0;

	SDL_GetMouseState(&dx, &dy);

	_mousePos = vector(dx, dy);
}

bool inputSystem::update()
{
	/*Event loop is global; not internal, this allows for more instances to be updated at once.*/

	for (int i = 0; i != gameInput::instance().getFrameEvents().size(); i++)
	{
		SDL_Event e = gameInput::instance().getFrameEvents()[i];

		switch (gameInput::instance().getFrameEvents()[i].type)
		{
		case SDL_QUIT:
			gameData::instance().setExit(false);
			break;
		case SDL_MOUSEBUTTONUP:
			onMouseBtnUp(e);
			break;
		case SDL_MOUSEBUTTONDOWN:
			onMouseBtnDown(e);
			break;
		case SDL_MOUSEMOTION:
			onMouseMove(e);
			break;
		case SDL_KEYDOWN:
			onKeyDown();
			break;
		case SDL_KEYUP:
			onKeyUp();
			break;
		default:
			break;
		}
	}

	return true;
}