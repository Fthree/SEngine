#ifndef STATEINTERFACE
#define STATEINTERFACE

#include <memory>
#include <vector>

#include "GameData.h"

enum GAMESTATES
{
	PLAY = 1,
	PAUSE = 2
};

class stateGen
{
public:
	stateGen(){}
	virtual ~stateGen() { std::cout << "\t\tbase state cleaned\n\n"; }

	virtual bool enter() { return false; }
	virtual bool exit() { return false; }

	virtual bool update(double dt) { return true; }
	virtual bool render(double dt) { return false; }

	virtual void resetStateP() {}

	virtual int getID() { return -1; }
};

#endif