#include "WeaponState.h"

void weaponState::handle(gameEvent<playerKeyPresses> playerKeyPressEv)
{
	playerKeyPressEv.pollEvents();

	if (playerKeyPressEv.type() == NO_KEY)
	{
		_states.setEventType(PLAYER_WALK);
	}
	else
	{
		_states.setEventType(PLAYER_IDLE);
	}
}