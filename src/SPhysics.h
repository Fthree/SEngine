#ifndef __SEANPHYSICS__
#define __SEANPHYSICS__

#include <Box2D/Box2D.h>

#include "PhysicsUtils.h"
#include "Vector.h"
#include "eventQueue.h"
#include "Enums.h"

class SPhysics
{
public:
	SPhysics(b2World &world)
	: world_(world) 
	{
		timeStep = 1.0f / 60.0f;
		velocityIterations = 6;
		positionIterations = 2;
	}

	bool makeBody(b2Vec2 position, b2Vec2 size);

	void update();

	b2Body* getBody() { return body_; }
	b2World getWorld() { return world_; }


private:

	b2World &world_;
	b2Body *body_;

	float32 timeStep;
	int32 velocityIterations;
	int32 positionIterations; 
};

#endif
