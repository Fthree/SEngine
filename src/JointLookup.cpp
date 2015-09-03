#include "JointLookup.h"

std::vector<b2WeldJoint*> JointTable::jointsWeld;
std::vector<b2RevoluteJoint*> JointTable::jointsRevolute;

void JointTable::makeWeld(b2World* w, b2Body* A, b2Body* B)
{
	b2WeldJointDef weldDef;
	weldDef.Initialize(A, B, B->GetWorldCenter());
	//weldDef.dampingRatio = 1.0;

	b2WeldJoint *weld = (b2WeldJoint*)w->CreateJoint(&weldDef);
	jointsWeld.push_back(weld);
}

void JointTable::makeRevolute(b2World* w, b2Body* A, b2Body* B)
{
	b2RevoluteJointDef RevDef;
	RevDef.Initialize(A, B, B->GetWorldCenter());
	


	b2RevoluteJoint *Rev = (b2RevoluteJoint*)w->CreateJoint(&RevDef);
	jointsRevolute.push_back(Rev);
}