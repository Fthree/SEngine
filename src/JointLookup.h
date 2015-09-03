#ifndef JOINT_LOOK_UP_H
#define JOINT_LOOK_UP_H

#include <vector>
#include <Box2D\Box2D.h>

class JointTable
{
public:
	static void makeWeld(b2World* w, b2Body* A, b2Body* B);
	static void makeRevolute(b2World* w, b2Body* A, b2Body* B);
	static int getNumberObjs() { int size = jointsWeld.size() + jointsRevolute.size(); return size; }
	static std::vector<b2WeldJoint*> getWeldJoints() { return jointsWeld; }
	static std::vector<b2RevoluteJoint*> getRevJoints() { return jointsRevolute; }

private:
	static std::vector<b2WeldJoint*> jointsWeld;
	static std::vector<b2RevoluteJoint*> jointsRevolute;

	JointTable() {}
	~JointTable() {}
};

#endif