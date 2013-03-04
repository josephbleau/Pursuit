#ifndef ENEMYENTITY_H
#define ENEMYENTITY_H

#include <map>
#include <string>

#include "Entity.h"

class EntityBehavior;
class Game;

class EnemyEntity : public Entity 
{
private:
	void updateMisc(); 	// Override

public:
	EnemyEntity( Game* parent, int x, int y, int w, int h );
};

#endif