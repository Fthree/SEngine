#include "StateHandlerGen.h"

stateHandlerGen::stateHandlerGen()
{
	pushState(std::make_shared<splay>());
}

void stateHandlerGen::render(double dt)
{
	_states.back()->render(dt);
}

bool stateHandlerGen::update(double dt)
{
	if (!_states.back()->update(dt))
	{
		changeStateGen();
	}

	return true;
}

void stateHandlerGen::popState()
{
	_states.back()->exit();
	_states.pop_back();
}

void stateHandlerGen::pushState(std::shared_ptr<stateGen> newState)
{
	_states.push_back(newState);
	_states.back()->enter();
}

void stateHandlerGen::changeStateGen()
{
}