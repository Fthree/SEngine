#ifndef __GFXPKG__
#define __GFXPKG__

#include "Vector.h"

#include <string>

struct GfxPackage
{
	GfxPackage(std::string path = "", std::string id = "", vector size = vector(0, 0), int frames = 0, double speedDiv = 0.0, std::string bridgeFrom = "", std::string bridgeTo = "", std::string type = "")
	{
		_path = path; 
		_id = id; 
		_size = size; 
		_frames = frames;
		_speedDivider = speedDiv;
		
		from_ = bridgeFrom;
		to_ = bridgeTo;

		type_ = type;
	}

	std::string _path;
	std::string _id;
	vector _size;
	int _frames;
	double _speedDivider;

	std::string from_;
	std::string to_;
	std::string type_;
};

#endif