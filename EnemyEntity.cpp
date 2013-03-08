#include "EnemyEntity.h"

#include "AnimatedEntity.h"
#include "EntityBehavior.h"
#include "EntityProperties.h"
#include "EBFollow.h"
#include "EBSpikey.h"
#include "EBStats.h"
#include "Game.h"
#include "ImageLoadException.h"
#include "SpriteAnimation.h"

#include <iostream>

EnemyEntity::EnemyEntity( Game* parent, int x, int y, int w, int h ) :
	AnimatedEntity( parent, x, y, w, h )
{
	giveBehavior( new EBFollow() );
	giveBehavior( new EBStats() );
	giveBehavior( new EBSpikey(3) );					// Spikes do 3 damage on contact.
	giveProperty( EntityProperty::COLLIDABLE );
	giveProperty( EntityProperty::DESTROY_ON_DEATH );	

	setAnimation("enemy");
	//enableAnimation();
}
