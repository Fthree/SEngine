#ifndef __EVENTSYS__
#define __EVENTSYS__

#include <vector>

template<class T>
class gameEvent {
public:
	gameEvent() : currentEvent_(T()), currentPosInPolling_(0) {}

	void setEventType(T enumVal)
	{
		allEvents_.push_back(enumVal); //Keep the enum inside a vector for polling later
	}

	bool pollEvents()
	{
		if (allEvents_.size() > 0)
		{
			//Poll from the beginning of the vector.
			//Ensure all events are polled before reseting all the values to 0.
			if (currentPosInPolling_ < allEvents_.size())
			{
				currentEvent_ = allEvents_[currentPosInPolling_];
				currentPosInPolling_++;
			}
			else
			{
				//Done
				
				return true;
			}
		}
		else
		{
			//No events to poll
			return false;
		}
	}

	void clearEventQueue()
	{
		currentPosInPolling_ = 0;
		allEvents_.clear();
	}

	T type() const
	{
		//Get the current event for handling later
		return currentEvent_;
	}

	void outputEvent() const
	{
		//Mostly for debugging
		std::cout << currentEvent_ << "\n";
	}

private:

	std::vector<T> allEvents_;
	T currentEvent_;
	unsigned int currentPosInPolling_;
};

#endif