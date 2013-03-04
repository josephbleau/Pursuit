#ifndef PLAYERENTITY_H
#define PLAYERENTITY_H

#include "Entity.h"

class EntityTrap;

class PlayerEntity : public Entity
{
private:
	bool mTrapCooldownReady; // Is true if we're able to use another trap
	int mTicksBetweenTrap; // Number of ticks that must pass before we can use another trap
	int mTrapTimer;	// A timer that is decremented once per tick until zero is reached.

	std::vector< std::unique_ptr<EntityTrap> > mTraps;

public:
	PlayerEntity( Game* game, int x, int y, int w, int h);

	void executeMisc(); //override
	EntityTrap* getNextTrap();
	bool isTrapReady() const;
};

#endif