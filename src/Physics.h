#ifndef __PHYSICSINTERFACE__
#define __PHYSICSINTERFACE__

#include "Parameters.h"
#include "Vector.h"
#include "Enums.h"
#include "Event.h"

#include <math.h>
#include <memory>

class Physics
{
public: 
	Physics() {}
	virtual ~Physics() {}

	virtual void update(double dt) {}
	virtual void update(std::shared_ptr<parameters> params, double dt) {}
	virtual void update(double dt, gameEvent<PLAYERMOVEMENT> &ev) {}
	virtual void update(double dt, gameEvent<PLAYERMOVEMENT> &ev, double angle) {}

	virtual vector getSize() { return vector(0, 0); }

	virtual vector &getVelocity() { return _tVel = vector(0, 0); }
	virtual vector &getPosition() { return _tPos = vector(0, 0); }
	virtual vector &getAcceleration() { return _tAcc = vector(0, 0); }
	virtual vector &getCap() { return _tCap = vector(0, 0); }

	virtual bool hasPassedWindow(int width) { return false; }
	virtual void scaleSpeed(double x) {}
	virtual void resetAll() {}
	virtual void stopMovement() {}
	virtual void startMovement() {}

	virtual bool isMoving() { bool failure = false; return failure; }
	virtual bool hasCollided() { bool failure = false; return failure; }

	virtual void moveTo(vector position) {}

private:
	vector _tVel;
	vector _tPos;
	vector _tCap;
	vector _tAcc;
};

#endif