#ifndef __ENTITYSTATEHANDLER__
#define __ENTITYSTATEHANDLER__

#include <memory>

#include "Enums.h"
#include "Event.h"

class weaponState
{
public:
	weaponState() {}
	void handle(gameEvent<playerKeyPresses> playerKeyPressEv);

private:
	gameEvent<playerStates> _states;
};


#endif