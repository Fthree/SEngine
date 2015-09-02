#include "GSPlay.h"

splay::splay()
{
	_world.reset(new world);
}

bool splay::enter()
{
	if (_world->enter())
	{
		return true;
	}
	return false;
}

bool splay::update(double dt)
{
	_world->update(dt);

	return true;
}

bool splay::render(double dt)
{
	if (_world->render(dt))
	{
		return true;
	}

	return false;
}

bool splay::exit()
{
	_world->exit();
	return true;
}
