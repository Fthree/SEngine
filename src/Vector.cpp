 #include "Vector.h"

void vector::step(vector &current, vector goal, vector step)
{
	if ((current._X > (goal._X - step._X)) && (current._X < (goal._X + step._X)))
	{
		current._X = step._X;
		return;
	}
	else if (current._X < goal._X)
	{
		current._X -= step._X;
	}
	else if (current._X > goal._X)
	{
		current._X += step._X;
	}
}

void vector::normalize()
{
	double l = length();
	if (l > 0)
	{
		(*this) *= 1 / l;
	}
}

double vector::findAngleTo(vector B) {

	double dot = _X * B._X + _Y + B._Y;
	double determ = _X * B._Y + _Y * B._X;

	double angle = atan2(dot, determ);

	angle = utils::radsToDeg(angle);

	return angle; //Radians angle
}