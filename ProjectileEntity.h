#ifndef PROJECTILE_ENTITY
#define PROJECTILE_ENTITY

#include "Entity.h"

class Game;

class ProjectileEntity : public Entity
{
private:
	float mVelocityX;
	float mVelocityY;

public:
	ProjectileEntity( Game* game, int x, int y, int w, int h, float vx, float vy );

	void executeMisc();
};

#endif