#ifndef __MAPMOVEMENTHANDLER__
#define __MAPMOVEMENTHANDLER__

#include "SeanPoint.h"
#include "SeanLine.h"

#include "SPhysics.h"

class MapMovementHandler
{
public:
	MapMovementHandler();
	~MapMovementHandler() {}

	void addPoint(SeanPoint &point) { points_.push_back(point); }
	void addLine(SeanLine &line) { lines_.push_back(line); }

	void update();

	void changeMovementMagnitude(double magnitude) { magnitude_ = magnitude; }

private:
	//Points to move

	std::vector<SeanPoint> &points_;

	//Lines to move -- maybe..

	std::vector<SeanLine> &lines_;

	double magnitude_;
};

#endif