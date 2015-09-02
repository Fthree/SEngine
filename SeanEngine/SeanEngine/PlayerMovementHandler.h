#ifndef __PLAYERMOVEMENTHANDLER__
#define __PLAYERMOVEMENTHANDLER__

#include "EntityPhysics.h"
#include "Event.h"
#include "SeanRect.h"
#include "PlayerInput.h"
#include "eventStaticQueue.h"
#include "SPhysics.h"
#include "EventQueue.h"
#include "Gfx_Primitives.h"

#include <memory>
#include <vector>

class movement
{
public:
	movement() {}
	~movement() {}
	movement(vector initialPos, vector sizeOfFrame);

	vector getPosition() { return physics_->getPosition(); }

	vector getCentre() 
	{ 
		return physics_->getPosition() + (size_ / 2);
	}

	bool isMoving() { return physics_->isMoving(); }
	double getAngle() { return lookAngle_; }
	double getWalkAngle() { return walkAngle_; }
	void setMousePos(vector mousePos) { mousePos_ = mousePos; }

	void setNewSizeOfFrame(vector sizeOfFrame) { size_ = sizeOfFrame; }

	void setCollisionRects(std::vector<SeanRect> collisionBoxes) { physics_->pushCollidable(collisionBoxes); }
	void setNonCollisionRects(std::vector<SeanRect> nonCollisionBoxes) { physics_->pushNonCollidable(nonCollisionBoxes); }

	void update(playerStates playerState);
	void render();

private:
	std::shared_ptr<SPhysics> physics_;

	PrimitiveGfx gfxp_;

	vector mousePos_;
	vector size_;
	
	double velocityAngle_;
	double lookAngle_;
	double walkAngle_;
};

#endif