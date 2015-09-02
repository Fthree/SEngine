#ifndef __PLAYERSPRITEHANDLER__
#define __PLAYERSPRITEHANDLER__

#include <memory>

#include "Vector.h"
#include "SpriteHandler.h"
#include "EventQueue.h"
#include "Enums.h"
#include "AnimationHandler.h"

class spriteManager
{
public:
	spriteManager();
	~spriteManager();

	void update(playerStates state, playerStates weaponState, vector position, double lookAngle, double walkAngle);
	void render();

	AnimationStates getCurrentAnim() { return AHTorso_->getAnimInfo(); }

	std::shared_ptr<sprite> getTorso() { return AHTorso_->getAnim(); }

private:

	std::shared_ptr<animationHandler> AHTorso_;
	std::shared_ptr<animationHandler> AHLegs_;

	playerStates currentTorsoAnim;
	playerStates currentLegsAnim;
};

#endif