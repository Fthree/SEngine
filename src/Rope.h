#ifndef __PHYSICSDATA__
#define __PHYSICSDATA__

#include <Box2D/Box2D.h>
#include <vector>
#include "glm/glm.hpp"
#include "BodyLookup.h"
#include "JointLookup.h"

class rope
{
public:
	rope() {}
	~rope(){}

	void Initialize(b2World *world, b2Vec2 startPosition, b2Vec2 endPosition, b2Vec2 segmentSize);
	void setGround(b2Body *ground) { ground_ = ground; }
private:
	b2Body *ground_;
};

#endif
