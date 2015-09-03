#ifndef __GAMEHANDLER__
#define __GAMEHANDLER__

#include "Event.h"
#include "GFX.h"
#include "ResourceManager.h"
#include "Input.h"
#include "Rope.h"
#include "AssetLoader.h"

#include <iostream>
#include <Box2D\Box2D.h>

class gameHandler
{
public:
	gameHandler();
	~gameHandler() {}

	void update();
	void render();

	void enter();
	void setupResources();

private:
	void makeDynamicBody(b2Vec2 position);
	int current;

	std::string whichShader;

	b2World *world_; 
	b2Body *ground;

	rope rope;
	
	b2Vec2 gravity;

	graphics gfx;

	b2Vec2 groundSize;
	b2Vec2 bodySize;

	inputSystem input;

	float32 timestep;
	int32 velocityIts;
	int32 positionIts;

	b2Vec2 bodypos;
	b2Vec2 groundpos;

	std::vector<double> colourValX;
	std::vector<double> colourValY;
	std::vector<double> colourValZ;
};

#endif