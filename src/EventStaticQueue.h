#ifndef __EVENTSTATICQUEUE__
#define __EVENTSTATICQUEUE__

#include <vector>
#include <SDL2\SDL.h>

template<class K>
class eventStaticQueue
{
public:
	static eventStaticQueue &instance()
	{
		static eventStaticQueue *instance_ = new eventStaticQueue();
		return *instance_;
	}

	~eventStaticQueue() {}

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
	eventStaticQueue() {}

	std::vector<K> events;

};

#endif