#ifndef __UTILS__
#define __UTILS__

# define S_PI 3.14159265358979323846 

#include <random>
#include <time.h>
#include <sstream>
#include <iostream>


namespace utils
{
	static void nullToEmpty(char const* &val)
	{
		if (!val)
		{
			val = "";
		}
	}

	template<class K>
	static void streamData(const char* input, K &output)
	{
		std::stringstream valueStream;

		valueStream << input;
		valueStream >> output;

		valueStream.clear();
	}

	template<class K>
	static void makeVec2D(std::vector<std::vector<K>> &vec, int width, int height, K startVal)
	{
		vec.resize(height, std::vector<K>(width, startVal));
	}

	static void outputVec2D(const std::vector<std::vector<int>> vec)
	{
		for (int i = 0; i != vec.size(); i++)
		{
			for (int j = 0; j != vec.size(); j++)
			{
				std::cout << vec[i][j] << " ";
			}
			std::cout << "\n";
		}
	}

	static double RandVal()
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<double> realDistribution(0, RAND_MAX);
		return realDistribution(gen);
	}

	static double RandRealRange(double low, double high)
	{
		if (low > high)
		{
			std::swap(low, high);
		}

		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_real_distribution<double> dist(low, high);

		return dist(mt);
	}

	static std::vector<double> RandRealRangeSAV(double low, double high, int N)
	{
		std::vector<double> randomNumbers;

		if (low > high)
		{
			std::swap(low, high);
		}

		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_real_distribution<double> dist(low, high);

		for (int i = 0; i != N; i++)
		{
			randomNumbers.push_back(dist(mt));
		}
	
		return randomNumbers;
	}

	static double RandIntRange(int low, int high)
	{
		if (low > high)
		{
			std::swap(low, high);
		}

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> realDistribution(low, high);

		return realDistribution(gen);
	}

	static bool RandBool()
	{
		int b = RandIntRange(0, 2);

		if (b > 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	template<class K>
	static K randVector(K min, K max)
	{
		double x;
		double y;

		x = RandRealRange(min._X, max._X);
		y = RandRealRange(min._Y, max._Y);

		return K(x, y);
	}
	
	static double clamp(double value, double min, double max)
	{
		if (value < min)
		{
			return min;
		}
		if (value > max)
		{
			return max;
		}
		return value;
	}

	static int cycleValues(int value, int min, int max)
	{
			if (value < min)
			{
				return max;
			}
			if (value > max)
			{
				return min;
			}
			return value;
	}

	template<class K>
	static bool isInRange(K value, K min, K max)
	{
		//if ((current._X < (goal._X - buffer._X)) || (current._X >(goal._X + buffer._X)))
		//{
		//	return true;
		//}

		//return false;
        return value > min || value < max;
	}

	static double norm(double value, double min, double max)
	{
		return (value - min) / (max - min);
	}

	static double lerp(double norm, double min, double max)
	{
		return (max - min) * norm + min;
	}

	static double mapNormLerp(double value, double sourceMin, double sourceMax, double destMin, double destMax)
	{
		return lerp(norm(value, sourceMin, sourceMax), destMin, destMax);
	}

#ifdef WINDOWS
	static double inline __declspec (naked) __fastcall SeanSqrt(double n)
	{
		_asm fld qword ptr [esp + 4]
		_asm fsqrt
		_asm ret 8
	}
#else
	static double inline SeanSqrt(double n)
	{
        return sqrt(n);
	}
#endif

	static double radsToDeg(double input)
	{
		return input * (180 / S_PI);
	}
	
	static double degToRads(double input)
	{
		return input * (S_PI / 180);
	}

	
};

#endif
