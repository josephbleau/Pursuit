#include "EnemyEntity.h"

#include "EntityBehavior.h"
#include "EntityProperties.h"
#include "EBFollow.h"
#include "EBSpikey.h"
#include "EBStats.h"
#include "Game.h"

#include <iostream>

EnemyEntity::EnemyEntity( Game* parent, int x, int y, int w, int h ) :
	Entity( parent, x, y, w, h )
{
	giveBehavior( new EBFollow() );
	giveBehavior( new EBStats() );
	giveBehavior( new EBSpikey(3) );	// Spikes do 3 damage on contact.
	giveProperty( EntityProperty::COLLIDABLE );
	giveProperty( EntityProperty::DESTROY_ON_DEATH );
}


void EnemyEntity::executeMisc()
{
}
