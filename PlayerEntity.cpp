#include "PlayerEntity.h"

#include "Game.h"
#include "EntityTrap.h"
#include "TrapTypes.h"
#include "EntityProperties.h"

PlayerEntity::PlayerEntity( Game* game, int x, int y, int w, int h ) :
	Entity( game, x, y, w, h ),
	mTrapCooldownReady( true ),
	mTicksBetweenTrap( 200 ),
	mTrapTimer( 0 )
{
	setColor( 180, 180, 90 );

	/* Arm the player with 10 Sticky Traps. 
	   NOTE: At some point this should be moved into
	         some sort of level loading format, which
			 would determine the default traps available
			 at the beginning of a level. */

	for( int i = 0; i < 10; ++i )
		mTraps.push_back( std::unique_ptr<EntityTrap>( new EntityTrap( game, 0, 0, 20, 20, TrapType::STICKY ) ) );
}

void PlayerEntity::executeMisc()
{
	mTrapTimer--;
	if(mTrapTimer <= 0) 
	{
		mTrapCooldownReady = true;
	}

	/* Handle keyboard input if the 
	   Entity is Player Controlled. */
	if( hasProperty( EntityProperty::PLAYERCONTROLLED ) )
	{
		/* TODO: Generalize input, allow customization. 
		   possibly via an EntityBehavior? */
		Uint8* keyState = SDL_GetKeyState( NULL );
		SDL_Rect newRect = getRect();

		if( keyState['d'] )
		{
			newRect.x +=  getSpeedPerTick();
		}
		if( keyState['a'] ) 
		{
			newRect.x -= getSpeedPerTick();
		}
		if( keyState['w'] ) 
		{
			newRect.y -= getSpeedPerTick();
		}
		if( keyState['s'] ) 
		{
			newRect.y += getSpeedPerTick();
		}

		SDL_Rect worldRect = getGame()->getWorldRect();
		if( newRect.x > worldRect.x &&
			newRect.y > worldRect.y &&
			newRect.x + newRect.w < worldRect.x + worldRect.w &&
			newRect.y + newRect.h < worldRect.y + worldRect.h )
		{
			teleport(newRect.x, newRect.y);
		}
	}
}

bool PlayerEntity::isTrapReady() const
{
	return mTrapCooldownReady;
}

EntityTrap* PlayerEntity::getNextTrap()
{
	if( mTraps.empty() )
		return NULL;

	// Resets the trap timer
	mTrapCooldownReady = false;
	mTrapTimer = mTicksBetweenTrap;

	EntityTrap* trap = mTraps.at(0).release();
	mTraps.erase( mTraps.begin() );

	return trap;
}