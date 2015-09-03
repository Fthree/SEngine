#ifndef __WORLD__
#define __WORLD__

#include "Utils.h"
#include "Timer.h"
#include "GameHandler.h"
#include "GFX.h"
#include "ResourceManager.h"
#include "GameData.h"

#include <string>
#include <functional>

class world
{
public:
	world();

	virtual bool enter();
	virtual bool exit();

	virtual bool update(double dt);
	virtual bool render(double dt);

	virtual void reloadData();

private:
	//Entities
	std::shared_ptr<gameHandler> _gameHandler;

	//Events
	SDL_Event _event;

	//Locals
	double _dt;
	bool _stopMap;

	timer time;

};

#endif
