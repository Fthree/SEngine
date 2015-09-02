#include "SeanRoom.h"


SeanRoom::SeanRoom()
{
}


SeanRoom::~SeanRoom()
{
}

void SeanRoom::create(vector position, vector size)
{
	position_ = position;
	size_ = size;
	thisRoom_ = SeanRect(size, position);
	parent_ = nullptr;
}

void SeanRoom::createWithCorner(int corner, vector size)
{
	size_ = size;
	placeInCorner(corner);
	thisRoom_ = SeanRect(size_, position_);
	whichParentVertice = corner;
}

void SeanRoom::placeInCorner(int corner)
{
	int x;
	int y;

	switch (corner)
	{
	case 0: //UL
		x = parent_->getThisRoom().allVertices[corner].position._X;
		y = parent_->getThisRoom().allVertices[corner].position._Y;
		break;
	case 1: //UR
		x = parent_->getThisRoom().allVertices[corner].position._X - size_._X;
		y = parent_->getThisRoom().allVertices[corner].position._Y;
		break;
	case 2: //LR
		x = parent_->getThisRoom().allVertices[corner].position._X - size_._X;
		y = parent_->getThisRoom().allVertices[corner].position._Y - size_._Y;
		break;
	case 3: //LL
		x = parent_->getThisRoom().allVertices[corner].position._X;
		y = parent_->getThisRoom().allVertices[corner].position._Y - size_._Y;
		break;
	}
	
	position_ = vector(x, y);
}