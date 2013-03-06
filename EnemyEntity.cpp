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

	/* TODO: Resource handling, will probably need to introduce
	         a class which loads all resources and makes them 
		     accessible via some sort of handle. */
	try 
	{
		std::shared_ptr<SpriteAnimation> anim( new SpriteAnimation( "enemy_anim.png", 32, 32 ) );
	}
	catch( ImageLoadException e )
	{
		disableAnimation();
		std::cerr << e.what();
	}
}
