#include "Projectile.h"

projectile::projectile(
	vector position,
	double force,
	double angle, 
	double time, 
	std::string whichParticles,
	std::string data
	)
	:force_(force), angle_(angle), emitTime(time)
{ 
	physics_.reset(new SPhysics(position));
	sprite_.reset(new sprite("PARTICLES", whichParticles, data, position));
	physics_->setProperties(sprite_->getSizeOfFrame(), 2);

	alive = true; 
	time_.reset(new timer);
	time_->startTimer();
}

void projectile::update()
{
	physics_->update(-50, 50);
	physics_->applyForce(force_, angle_);
	
	vector pos = physics_->getPosition() - (sprite_->getSizeOfFrame() / 2);
	
	sprite_->update(pos);

	

	if (time_->hasReachedSecond(emitTime))
	{
		time_->stopTimer();
		alive = false;
	}
}

void projectile::render()
{
	sprite_->setAngle(angle_);
	sprite_->render(true);
}