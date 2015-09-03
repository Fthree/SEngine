#ifndef S_PLAY
#define S_PLAY

#include "StateGen.h"
#include "world.h"

#include <string>
#include <functional>


class splay : public stateGen
{
public:
	splay();

	virtual ~splay() { exit(); std::cout << "play state cleaned\n\n"; }

	virtual bool enter();
	virtual bool exit();

	virtual bool update(double dt);
	virtual bool render(double dt);

	virtual int getID() { return ID; }

private:
	std::shared_ptr<world> _world;

	const int ID = 1;
};

#endif