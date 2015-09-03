#include "world.h"

world::world()
{
	//Setup graphics
	ResourceManager::loadShader("shader.vertex", "shader.fragment", "main");
	ResourceManager::loadShader("ShaderDebug.vertex", "ShaderDebug.fragment", "debug");

	float lowerX = -90.0f, upperX = 90.0f, lowerY = -15.0f, upperY = 25.0f;
	glm::mat4 projection = glm::ortho(lowerX, upperX, lowerY, upperY, -1.0f, 1.0f);

	ResourceManager::getShader("main").use().setInt("image", 0);
	ResourceManager::getShader("main").setMat4("projection", projection);

	ResourceManager::getShader("debug").use().setInt("image", 0);
	ResourceManager::getShader("debug").setMat4("projection", projection);

	_gameHandler.reset(new gameHandler);
}

bool world::enter()
{
	return true;
}

bool world::update(double dt)
{
	_gameHandler->update();

	return true;
}

bool world::render(double dt)
{
	_gameHandler->render();
	
	return true;
}

void world::reloadData()
{
	std::cout << "Shoved that data right up the software's ass\n";
}


bool world::exit()
{
	return true;
}
