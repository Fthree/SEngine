#ifndef __EVENTQUEUE__
#define __EVENTQUEUE__

#include <vector>
#include <SDL2\SDL.h>

template<class K>
class eventQueue
{
public:
	eventQueue() {}
	~eventQueue() {}

	std::vector<K>& getEvent()
	{
		return events;
	}

	void addEvent(K v)
	{
		events.push_back(v);
	}

	void clearEvents()
	{
		events.clear();
	}

	void outputCurrentEvents()
	{
		for (int i = 0; i != events.size(); i++)
		{
			std::cout << events[i] << "\n";
		}

		std::cout << "\n";
	}

private:
	

	std::vector<K> events;

};

#endif