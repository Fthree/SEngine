#include <string>

enum ANIMPKGINFO
{
	A_CURRENT = 0,
	A_BRIDGE = 1,
	A_NEXT = 2
};

struct animPackage
{
	animPackage() { reverse_ = false; }
	animPackage(std::string name, int numFrames)
	{ 
		name_ = name; 
		numFrames_ = numFrames;
		reverse_ = false;
	}

	void reverse(bool val) { reverse_ = val; }

	bool checkStatus(int frameCount) 
	{ 
		if (!reverse_)
		{
			if (frameCount >= numFrames_ - 1)
			{
				return true;
			}
		}
		else
		{
			if (frameCount == 0)
			{
				return true;
			}
		}
		
		return false; 
	}

	std::string name_;
	int numFrames_;
	bool reverse_;
};
