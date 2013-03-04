#include "Entity.h"

#include "Game.h"
#include "EBStats.h"
#include "EntityBehavior.h"
#include "EntityProperties.h"
#include "Destroyable.h"

#include <algorithm>
#include <iostream>
#include <type_traits>

Entity::Entity( Game* parent, int x, int y, 
			    int w, int h ) :
	Renderable(),
	Destroyable(),
	mRect(),
	mColor(),
	mParent(parent),
	mProperties()
{
	mRect.x = x;
	mRect.y = y;
	mRect.w = w;
	mRect.h = h;

	// White
	mColor.r = 255;
	mColor.g = 255;
	mColor.b = 255;

	mSpeedPerTick = 1; // 60 px/s (at 60Hz)
}

Entity::~Entity()
{
}


void Entity::render( SDL_Surface* screen ) const
{
	if( !hasProperty( EntityProperty::HIDDEN ) )
	{
		SDL_Rect rectCopy = mRect;

		SDL_FillRect( screen, &rectCopy, 
			          SDL_MapRGB( 
					      screen->format, 
						  mColor.r,
						  mColor.g,
						  mColor.b
				      ) 
		); 
	}
}

void Entity::executeMisc()
{
	/* Handle keyboard input if the 
	   Entity is Player Controlled. */
	if( hasProperty( EntityProperty::PLAYERCONTROLLED ) )
	{
		/* TODO: Generalize input, allow customization. 
		   possibly via an EntityBehavior? */
		Uint8* keyState = SDL_GetKeyState( NULL );
		SDL_Rect newRect = mRect;

		if( keyState['d'] )
		{
			newRect.x +=  mSpeedPerTick;
		}
		if( keyState['a'] ) 
		{
			newRect.x -= mSpeedPerTick;
		}
		if( keyState['w'] ) 
		{
			newRect.y -= mSpeedPerTick;
		}
		if( keyState['s'] ) 
		{
			newRect.y += mSpeedPerTick;
		}

		SDL_Rect worldRect = mParent->getWorldRect();
		if( newRect.x > worldRect.x &&
			newRect.y > worldRect.y &&
			newRect.x + newRect.w < worldRect.x + worldRect.w &&
			newRect.y + newRect.h < worldRect.y + worldRect.h )
		{
			mRect = newRect;
		}
	}
}


// **NOTE**: Despite returning a handle to the owner
// of Entity, this method maintains appropriate constness
// both bitwise and logically, as Game does not expose or
// break the encapsulation of Entity.
Game* Entity::getGame()  const
{
	return mParent;
}

const SDL_Rect& Entity::getRect() const
{
	return mRect;
}

bool Entity::hasProperty( EntityProperty property ) const
{
	auto search = std::find( mProperties.begin(), mProperties.end(), property );
	return search != mProperties.end();
}

void Entity::giveProperty( EntityProperty property )
{
	if( !hasProperty( property ) )
	{
		mProperties.push_back( property );
	}
}

void Entity::removeProperty( EntityProperty property )
{
	auto search = std::find( mProperties.begin(), mProperties.end(), property );
	if( search != mProperties.end() )
	{
		mProperties.erase( search );
	}
}

void Entity::setColor( Uint8 r, Uint8 g, Uint8 b )
{
	mColor.r = r;
	mColor.g = g;
	mColor.b = b;
}

void Entity::setSpeedPerTick( int speed )
{
	mSpeedPerTick = speed;
}

void Entity::teleport(int x, int y)
{
	mRect.x = x;
	mRect.y = y;
}

void Entity::update() 
{
	executeBehaviors( this );
	executeMisc();	// Overriden by derived Entities to provide custom innate behavior outside EntityBehavior's
}