#include "GameHandler.h"

gameHandler::gameHandler()
{
	whichShader = "main";
	setupResources();

	b2Vec2 gravity = b2Vec2(0.0f, -10.0f);
	world_ = new b2World(gravity);
	gfx = graphics(ResourceManager::getShader("main"));

	timestep = 1.0f / 60.0f;
	velocityIts = 6;
	positionIts = 2;
	current = 1;

	enter();
}

void gameHandler::setupResources()
{
	AssetLoader asset;
	asset.load("testAssets/assets.toml");

	//Load shaders into memory
	ResourceManager::loadShader("testAssets/shader.vertex", "testAssets/shader.fragment", "main");
	ResourceManager::loadShader("testAssets/ShaderDebug.vertex", "testAssets/ShaderDebug.fragment", "debug");

	//setup projection matrix

	float lowerX = -21.0f;
	float lowerY = -16.0f;

	float upperX = 21.0f;
	float upperY = 16.0f;
	
	glm::mat4 projection = glm::ortho(lowerX, upperX, lowerY, upperY, -1.0f, 1.0f);

	//load and setup various shaders
	ResourceManager::getShader("main").use().setInt("image", 0);
	ResourceManager::getShader("main").setMat4("projection", projection);

	ResourceManager::getShader("debug").use().setInt("image", 0);
	ResourceManager::getShader("debug").setMat4("projection", projection);

	//load and setup various textures
	ResourceManager::loadTexture(asset.get("textures.seg"), GL_TRUE, "seg");
	ResourceManager::loadTexture(asset.get("textures.box"), GL_TRUE, "smile");

}

//Make ground and body objects
void gameHandler::enter()
{
	double xMul = 3.5f;

	groundSize = b2Vec2(5.0f, 5.0f);
	bodySize = b2Vec2(0.2f, 0.5f);

	groundpos = b2Vec2(0.0f, 0.0f);

	{
		// Define the ground body.
		b2BodyDef groundBodyDef;
		groundBodyDef.position.Set(groundpos.x, groundpos.y);

		// Call the body factory which allocates memory for the ground body
		// from a pool and creates the ground box shape (also from a pool).
		// The body is also added to the world.

		ground = world_->CreateBody(&groundBodyDef);

		// Define the ground box shape.
		b2PolygonShape groundBox;

		// The extents are the half-widths of the box.
		groundBox.SetAsBox(groundSize.x, groundSize.y, b2Vec2(0, 0), 0);

		// Add the ground fixture to the ground body.
		ground->CreateFixture(&groundBox, 0.0f);
	}

	rope.setGround(ground);
	rope.Initialize(world_, b2Vec2(0.0f, 15.0f), b2Vec2(groundpos.x, groundpos.y + groundSize.y), bodySize);

	//Ball
	bodytable::makeDynamicBody(world_, b2Vec2(groundpos.x, groundpos.y + groundSize.y + 0.5), b2Vec2(0.5, 0.5), 0.1f);

	colourValX = utils::RandRealRangeSAV(0.1f, 1.0f, bodytable::getNumberObjs());
	colourValY = utils::RandRealRangeSAV(0.1f, 1.0f, bodytable::getNumberObjs());
	colourValZ = utils::RandRealRangeSAV(0.1f, 1.0f, bodytable::getNumberObjs());
}

void gameHandler::update()
{
	world_->Step(timestep, velocityIts, positionIts);

	/********************************************************************************************/
	/***********************************INPUT SECTION********************************************/
	/********************************************************************************************/

	input.update();

	if (input.isKeyDown(SDL_SCANCODE_UP))
	{
		b2Body *b = bodytable::getData(bodytable::getNumberObjs() - 2);

		b->ApplyForce(b2Vec2(0, 50), b->GetWorldCenter(), true);    
	}

	if (input.isKeyDown(SDL_SCANCODE_DOWN))
	{
		b2Body *b = bodytable::getData(bodytable::getNumberObjs() - 2);

		b->ApplyForce(b2Vec2(0, -50), b->GetWorldCenter(), true);
	}

	if (input.isKeyDown(SDL_SCANCODE_LEFT))
	{
		b2Body *b = bodytable::getData(bodytable::getNumberObjs() - 2);

		b->ApplyForce(b2Vec2(-50, 0), b->GetWorldCenter(), true);
	}

	if (input.isKeyDown(SDL_SCANCODE_RIGHT))
	{
		b2Body *b = bodytable::getData(bodytable::getNumberObjs() - 2);

		b->ApplyForce(b2Vec2(50, 0), b->GetWorldCenter(), true);
	}
}

void gameHandler::render()
{
	glm::vec3 colourground(1.0f, 0.0f, 0.0f);
	groundpos = ground->GetPosition();

	gfx.drawSprite(ResourceManager::getTexture("smile"), groundpos, groundSize, 0.0f, colourground);

	

	for (int i = 0; i != bodytable::getNumberObjs(); i++)
	{
		if (bodytable::getData(i) != NULL)
		{
			glm::vec3 colourbody(colourValX[i], colourValY[i], colourValZ[i]);
			bodypos = bodytable::getData(i)->GetPosition();

			gfx.drawSprite(ResourceManager::getTexture("seg"), bodypos, bodytable::getSize(i), bodytable::getData(i)->GetAngle(), colourbody);
		}
	}

	for (int i = 0; i != JointTable::getNumberObjs(); i++)
	{
		if (JointTable::getWeldJoints().size() > i)
		{
			gfx.drawLine(JointTable::getWeldJoints()[i]->GetBodyA()->GetPosition(), JointTable::getWeldJoints()[i]->GetBodyB()->GetPosition(), glm::vec3(0.0f, 0.0f, 1.0f));
		}
		if (JointTable::getRevJoints().size() > i)
		{
			//gfx.drawLine(JointTable::getRevJoints()[i]->GetBodyA()->GetPosition(), JointTable::getRevJoints()[i]->GetBodyB()->GetPosition(), glm::vec3(0.0f, 0.0f, 1.0f));
		}
	}
}