#ifndef __GFXLINE__
#define __GFXLINE__

#include "Vector.h"

class GfxLine
{
public:
	GfxLine() {}
	GfxLine(vector A, vector B) : _A(A), _B(B) {}
	~GfxLine() {}

	vector PointA() { return _A; }
	vector PointB() { return _B; }

private:
	vector _A;
	vector _B;
};

#endif