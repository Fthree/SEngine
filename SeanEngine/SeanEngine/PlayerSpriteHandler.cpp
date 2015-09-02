#include "PlayerSpriteHandler.h"

spriteManager::spriteManager()
{
	AHTorso_.reset(new animationHandler("ENTITIES", "NigelTorso", "idle"));
	AHLegs_.reset(new animationHandler("ENTITIES", "NigelLegs", "idle"));
}

spriteManager::~spriteManager()
{

}

void spriteManager::update(playerStates state, playerStates weaponState, vector position, double lookAngle, double walkAngle)
{
	switch (state)
	{
	case PLAYER_WALK:
		if (currentTorsoAnim != state && currentTorsoAnim != weaponState)
		{
			AHTorso_->newAnimation("walk");
			currentTorsoAnim = state;
		}

		if (currentLegsAnim != state)
		{
			AHLegs_->newAnimation("walk");
			currentLegsAnim = state;
		}

	case PLAYER_IDLE:
		if (currentTorsoAnim != state && currentTorsoAnim != weaponState)
		{
			AHTorso_->newAnimation("idle");
			currentTorsoAnim = state;
		}

		if (currentLegsAnim != state)
		{
			AHLegs_->newAnimation("idle");
			currentLegsAnim = state;
		}
	}

	switch (weaponState)
	{
	case PLAYER_ATTACK:

		if (currentTorsoAnim != weaponState)
		{
			AHTorso_->newAnimation("firing");
			currentTorsoAnim = weaponState;
		}
	}

	AHTorso_->setAngle(lookAngle);
	AHLegs_->setAngle(walkAngle);

	vector legsPosition = position + (AHTorso_->getAnim()->getSizeOfFrame() / 2 - AHLegs_->getAnim()->getSizeOfFrame() / 2);

	AHTorso_->update(position);
	AHLegs_->update(legsPosition);
}

void spriteManager::render()
{
	AHLegs_->render();
	AHTorso_->render();
}