/*BEING FIXED*/






//#ifndef __PROJECTILE__
//#define __PROJECTILE__
//
//#include "GFX.h"
//#include "Vector.h"
//#include "SPhysics.h"
//#include "DataLoader.h"
//#include "Timer.h"
//#include "SpriteHandler.h"
//
//class projectile
//{
//public:
//	projectile(
//		vector position,
//		double force,
//		double angle,
//		double time,
//		std::string whichParticles,
//		std::string data);
//	~projectile(){}
//
//	std::shared_ptr<SPhysics> getPhysics() { return physics_; }
//
//	void update();
//	void render();
//
//	bool isAlive() { return alive; }
//
//	double getAngle() { return angle_; }
//
//	void kill() { alive = false; }
//
//private:
//	double angle_;
//	double force_;
//
//	std::shared_ptr<SPhysics> physics_;
//	std::shared_ptr<sprite> sprite_;
//
//	bool alive;
//	double emitTime;
//	std::shared_ptr<timer> time_;
//};
//
//#endif