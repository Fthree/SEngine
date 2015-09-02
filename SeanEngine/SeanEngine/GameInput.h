#ifndef __GAMEINPUT__
#define __GAMEINPUT__

#include <vector>
#include <SDL2\SDL.h>

class gameInput
{	
public:
	static gameInput &instance()
	{
		static gameInput *instance_ = new gameInput();
		return *instance_;
	}

	std::vector<SDL_Event>& getFrameEvents()
	{
		return events;
	}

	void clearEvents()
	{
		events.clear();
	}

	void outputCurrentEventQueue()
	{
		for (int i = 0; i != events.size(); i++)
		{
			std::cout << events[i].type << "\n";
		}

		std::cout << "\n";
	}

private:

	gameInput()
	{
		clearEvents();
	}

	std::vector<SDL_Event> events;
};

#endif