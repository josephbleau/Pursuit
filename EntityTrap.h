#ifndef ENTITYTRAP_H
#define ENTITYTRAP_H

#include "Entity.h"

enum TrapType;

class EntityTrap : public Entity
{
private:
	TrapType mType;
	bool mFriendly;	// If true then this trap will not hurt the player (true by default)

public:
	EntityTrap( Game* game, int x, int y, int w, int h, TrapType type, bool friendly = true );

	void executeMisc(); // override
};

#endif