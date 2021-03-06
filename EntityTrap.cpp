#include "EntityTrap.h"

#include "EntityBehavior.h"
#include "EBSpikey.h"
#include "EBSticky.h"
#include "TrapTypes.h"

EntityTrap::EntityTrap( Game* game, int x, int y, int w, int h, TrapType type, bool friendly ) :
	Entity( game, x, y, w, h ),
	mType( type ),
	mFriendly ( friendly )
{
	setTTD(150);

	/* Based on the trap type, we're going to give it
	   different behaviors. */
	EntityBehavior* behavior = NULL;
	switch( mType )
	{
		case TrapType::STICKY: 
		{
			setColor( 0, 255, 0 );	// Green
			behavior = new EBSticky();
			break;
		}
		case TrapType::EXPLOSIVE:
		{
			setColor( 255, 0, 0 );	// Red
			behavior = new EBSpikey( 10 );
			break;
		}
		default: 
		{
			break;
		}
	}

	if( behavior != NULL && mFriendly )
	{
		behavior->makeFriendly();
		giveBehavior( behavior );
	}
}

void EntityTrap::executeMisc()
{

}