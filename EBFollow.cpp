#include "EBFollow.h"

#include "SDL/SDL.h"
#include "Entity.h"
#include "Game.h"

EBFollow::EBFollow() : 
	EntityBehavior()
{

}

EBFollow::~EBFollow() 
{

}

std::string EBFollow::getMyType() const
{
	return typeid( this ).name();
}

void EBFollow::run( Entity* owner)
{
	/* Query game for player's location, approach it on y
	   and x-axis. */
	const SDL_Rect& playerRect = owner->getGame()->getPlayerRect();

	if( owner->getRect().x < playerRect.x ) 
	{
		owner->teleport( owner->getRect().x + 1, owner->getRect().y );
	}
	else if ( owner->getRect().x > playerRect.x ) 
	{
		owner->teleport( owner->getRect().x - 1, owner->getRect().y );
	}

	if( owner->getRect().y < playerRect.y )
	{
		owner->teleport( owner->getRect().x, owner->getRect().y + 1 );
	}
	else if ( owner->getRect().y > playerRect.y )
	{
		owner->teleport( owner->getRect().x, owner->getRect().y - 1 );
	}
}