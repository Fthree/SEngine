#ifndef INPUTSYS
#define INPUTSYS

#include <SDL2/SDL.h>
#include <vector>
#include <iostream>

#include "vector.h"
#include "GameData.h"
#include "GameInput.h"

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2,
	X1 = 3,
	X2 = 4
};

/*-Input system
-Captures input data and outputs current key being pressed; Mouse click buttons/positions too.*/
class inputSystem
{
public:
	inputSystem();
	~inputSystem() { std::cout << "\tbase level input cleaned\n"; }
	void initMouse();
	bool getMouseBtnState(int mouseButton);

	vector getMousePos() {
		return _mousePos;
	}

	bool isKeyDown(SDL_Scancode key);
	bool update();

private:

	std::vector<bool> _mouseBtnStates;
	vector _mousePos;
	const Uint8 *_keyState;
	bool _keyUp;
	void onKeyDown();
	void onKeyUp();
	void onMouseMove(SDL_Event &event);
	void onMouseBtnDown(SDL_Event &event);
	void onMouseBtnUp(SDL_Event &event);

	
};

#endif
