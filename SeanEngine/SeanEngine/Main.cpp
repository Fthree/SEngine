#include <memory>
#include "AssetLoader.h"
#include "game.h"



int main(int argc, char* argv[])
{
	std::shared_ptr<game> mainGame;
 
	mainGame.reset(new game);

	mainGame->init("SEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (mainGame->running())
	{
		mainGame->update();
		mainGame->render();
	}

	mainGame.reset();

	std::cin.get(); //debug, grab the game before it exits.
	return 0;
}
