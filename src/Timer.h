#ifndef __TIMER__
#define __TIMER__

#include <SDL2/SDL.h>

#include <sstream>
#include <string>

class timer
{
public:
	timer() { currentTime = 0; startTime = 0; timerStatus = false; }

	void startTimer() 
	{ 
		startTime = SDL_GetTicks();
		startTime /= 1000;

		timerStatus = true;
	}

	bool hasReachedSecond(double seconds)
	{
		currentTime = SDL_GetTicks();

		if ((currentTime / 1000) - startTime > seconds)
		{
			return true;
		}
		else 
		{
			return false;
		}
	}

	void stopTimer()
	{
		currentTime = 0; 
		startTime = 0;
		timerStatus = false;
	}

	void resetTimer()
	{
		currentTime = 0;
		startTimer();
	}

	bool hasStarted()
	{
		return timerStatus;
	}

	void toString(std::string head)
	{
		std::stringstream ss;

		char outputValue;

		ss << (currentTime / 1000) - startTime;
		ss >> outputValue;

		//std::cout << head << " " <<  outputValue << "\n";
	}

private:
	double currentTime;
	double startTime;
	bool timerStatus;
};

#endif
