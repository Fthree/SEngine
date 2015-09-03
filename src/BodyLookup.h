#ifndef __LOOKUP__
#define __LOOKUP__

#include <Box2D/Box2D.h>
#include <vector>
#include <string>

struct bodyInfo
{
public:
	std::string id;
	int idNum;
	b2Vec2 size;
	b2Body* body;
};

class bodytable
{
public:
	static void makeDynamicBody(b2World *world, b2Vec2 position, b2Vec2 size, double restitution = 0.0f, double mass = 1.0f, std::string id = "", int idNum = -1);
	static void makeStaticBody(b2World *world, b2Vec2 position, b2Vec2 size, std::string id = "", int idNum = -1);

	static b2Body *getDataByID(std::string id) {
		for (int i = 0; i != bodies.size(); i++)
		{
			if (bodies[i].id == id)
			{
				return bodies[i].body;
			}
		}
	}
	static b2Body *getData(int which) { return bodies[which].body; }
	static b2Vec2 getSize(int which) { return bodies[which].size; }
	static int getNumberObjs() { return bodies.size(); }
private:
	static std::vector<bodyInfo> bodies;

	bodytable() {}
};

#endif
