#include <iostream>
#include <SDL2/SDL.h>

class GameTick
{
public:
	void FPSCounter()
	{
		startTime = SDL_GetTicks();

		static unsigned int countedFrames;

		++countedFrames;

		_FPS = countedFrames / ((SDL_GetTicks() - 800) / 1000.0f); //Find the current FPS based on the time between frames.

		_DT = 1.0f / _FPS;
	}

	void FPSString(int frames)
	{
		static unsigned int countedFrames;

		++countedFrames;

		if (countedFrames % frames == 0)
		{
			//std::cout << "DT: " << _DT << std::endl;
		}
	}

	void TimeCounter(double FPS)
	{
		_DT = 1.0f / _FPS;
	}


	double getdt() { return _DT; }
	double getFPS() { return _FPS; }
private:
	double _FPS;
	double _DT;
	double startTime;
	double FPS;
	double _time;
};