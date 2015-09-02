#include "SPhysics.h"

void SPhysics::update()
{
	world_.Step(timeStep, velocityIterations, positionIterations);
}

bool SPhysics::makeBody(b2Vec2 position, b2Vec2 size)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(position.x, position.y);
	body_ = world_.CreateBody(&bodyDef);

	b2PolygonShape bodyShape_;
	bodyShape_.SetAsBox(size.x, size.y);
	
	b2FixtureDef bodyFixture_;
	bodyFixture_.shape = &bodyShape_;
	bodyFixture_.density = 1.0f;
	bodyFixture_.friction = 0.9f;

	body_->CreateFixture(&bodyFixture_);

	return true;
}