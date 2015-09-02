#ifndef STATEHANDLER
#define STATEHANDLER
#include <vector>
#include <memory>

#include "GameData.h"
#include "GSPlay.h"

class stateHandlerGen
{
public:
	stateHandlerGen();
	~stateHandlerGen() {}

	void render(double dt);
	bool update(double dt);

private:
	std::vector<std::shared_ptr<stateGen> > _states;

	void popState();
	void pushState(std::shared_ptr<stateGen> newState);
	void changeStateGen();
	
};

#endif