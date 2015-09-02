#ifndef __SEANROOM__
#define __SEANROOM__

#include "SeanRect.h"
#include "Vector.h"

#include <memory>

class SeanRoom
{
public:
	SeanRoom();
	~SeanRoom();

	void create(vector position, vector size);
	void createWithCorner(int corner, vector size);

	void setParent(std::shared_ptr<SeanRoom> parent) { parent_ = parent; }

	SeanRect &getThisRoom() { return thisRoom_; }
	std::shared_ptr<SeanRoom> getParent() { return parent_; }
	vector &getPosition() { return position_; }
	vector getSize() { return size_; }
	int getParentVert() { return whichParentVertice; }

	void setCornerToCornerOfParent(int corner) {}

private:
	vector position_;
	vector size_;

	SeanRect thisRoom_;
	std::shared_ptr<SeanRoom> parent_;

	int whichParentVertice;

	void placeInCorner(int corner);
};

#endif