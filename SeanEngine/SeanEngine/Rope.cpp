#include "Rope.h"

void rope::Initialize(b2World *world, b2Vec2 startPosition, b2Vec2 endPosition, b2Vec2 segmentSize)
{
	b2Vec2 length = startPosition - endPosition;
	length.x = glm::abs(length.x);
	length.y = glm::abs(length.y);
	length.y /= 2;

	int howMany = length.y / segmentSize.y;

	double yPosition = 0;
	double mass = 0;

	//howMany -= 2;

	for (int i = 0; i != howMany; i++)
	{
		yPosition = (startPosition.y - (segmentSize.y * 2) * (i + 1)) + segmentSize.y / 2;

		bodytable::makeDynamicBody(world, b2Vec2(startPosition.x, yPosition), segmentSize, 1.0f);
		
		if (i > 0)
		{
			JointTable::makeWeld(world, bodytable::getData(i - 1), bodytable::getData(i));
		}
	}

	JointTable::makeRevolute(world, ground_, bodytable::getData(0)/*first body, top*/);
}