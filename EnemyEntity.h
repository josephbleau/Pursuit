#ifndef ENEMYENTITY_H
#define ENEMYENTITY_H

#include <map>
#include <string>

#include "AnimatedEntity.h"

class EntityBehavior;
class Game;

class EnemyEntity : public AnimatedEntity 
{
public:
	virtual void executeMisc();
	EnemyEntity( Game* parent, int x, int y, int w, int h );
};

#endif