#ifndef __VECTOR__
#define __VECTOR__

#include <iostream>
#include <math.h>
#include <string>

#include "Utils.h"

class vector
{
public:
	double _X;
	double _Y;

	double _angle;
	double _length;

	vector() { _X = 0; _Y = 0; }

	vector(double x, double y) : _X(x), _Y(y) {}
	
	vector operator+(const vector &v2) const { return vector(_X + v2._X, _Y + v2._Y); }
	vector operator-(const vector &v2) const { return vector(_X - v2._X, _Y - v2._Y); }
	vector operator*(double scalar) { return vector(_X * scalar, _Y * scalar); }
	vector operator/(double scalar) { return vector(_X / scalar, _Y / scalar); }
	vector operator=(const vector *RHS) { _X = RHS->_X; _Y = RHS->_Y; return *this; }
	
	void operator=(double scalar) { _X = scalar; _Y = scalar; }

	vector operator+=(const vector &v2) { _X += v2._X; _Y += v2._Y; return *this; }
	vector operator-=(const vector &v2) { _X -= v2._Y; _Y -= v2._Y; return *this; }
	vector &operator*=(double scalar) { _X *= scalar; _Y *= scalar; return *this; }
	vector &operator/=(double scalar) { _X /= scalar; _Y /= scalar; return *this; }

	bool operator>(vector &RHS) { if (_X > RHS._X && _Y > RHS._Y){ return true; } else { return false; } }
	bool operator<(vector &RHS) { if (_X < RHS._X && _Y < RHS._Y){ return true; } else { return false; } }

	bool operator>(double RHS) { if (_X > RHS && _Y > RHS){ return true; } else { return false; } }
	bool operator<(double RHS) { if (_X < RHS && _Y < RHS){ return true; } else { return false; } }

	bool operator==(vector &RHS) { if (_X == RHS._X && _Y == RHS._Y){ return true; } else { return false; } }
	bool operator!=(vector &RHS) { if (_X != RHS._X && _Y != RHS._Y){ return true; } else { return false; } }

	bool operator==(double RHS) { if (_X == RHS && _Y == RHS) { return true; } else { return false; } }
	bool operator!=(double RHS) { if (_X != RHS && _Y != RHS) { return true; } else { return false; } }

	vector operator++() { return vector(this->_X++, this->_Y++); }
	vector operator--() { return vector(this->_X--, this->_Y--); }
	
	double dot(vector B) { return _X * B._X + _Y * B._Y; }

	double length() { return utils::SeanSqrt(_X*_X + _Y*_Y); }

	void step(vector &current, vector goal, vector step); /*LERP*/

	void normalize();

	double findAngleTo(vector B);

	double getAngle() const { return _angle; }

	void setAngleAndLength(double angle, double length)
	{
		setAngle(angle);
		setLength(length);
	}

	void setAngle(double angle)
	{
		double radsAngle = utils::degToRads(angle);
		_angle = radsAngle;
	}

	void setLength(double length) {

		double c = cos(_angle);
		double s = sin(_angle);

		if (c < 0.0001 && c > -0.0001)
		{
			c = 0;
		}

		if (s < 0.0001 && s > -0.0001)
		{
			s = 0;
		}

		_X = c * length;
		_Y = s * length;
	}

	void toString(std::string heading)
	{
		std::cout << heading << " X: " << _X << " Y: " << _Y << "\n";
	}


	//Game related

	void addWithConstraints(vector addVal, double min, double max)
	{
		*this += addVal;

		if (min != 0 && max != 0)
		{
			_X = utils::clamp(_X, min, max);
			_Y = utils::clamp(_Y, min, max);
		}
	}

	void add(vector addVal)
	{
		*this += addVal;
	}

	void applyFriction(double frictionPercentage, bool &hasStopped)
	{
		if (*this < 0.2 && *this > -0.2)
		{
			*this = 0.0f;
			hasStopped = false;
		}
		else
		{
			*this *= frictionPercentage;
		}
	}
};

#endif
