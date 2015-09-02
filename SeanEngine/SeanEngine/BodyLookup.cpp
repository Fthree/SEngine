#include "BodyLookup.h"

std::vector<bodyInfo> bodytable::bodies;

void bodytable::makeDynamicBody(b2World *world, b2Vec2 position, b2Vec2 size, double restitution, double mass, std::string id, int idNum)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(position.x, position.y);
	bodyDef.angularDamping = 0.1f;
	bodyDef.linearDamping = 0.1f;
	

	// Define another box shape for our dynamic body.
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(size.x, size.y, b2Vec2(0, 0), 0);

	// Define the dynamic body fixture.
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;

	// Set the box density to be non-zero, so it will be dynamic.
	fixtureDef.density = 1.0f;

	// Override the default friction.
	fixtureDef.friction = 0.1f;
	fixtureDef.restitution = restitution;
	// Add the shape to the body.
	b2Body* bod = world->CreateBody(&bodyDef);

	bodyInfo newbody;
	newbody.id = id;
	newbody.idNum = idNum;
	newbody.size = size;
	newbody.body = bod;

	bodies.push_back(newbody);
	bodies.back().body->CreateFixture(&fixtureDef);
} 