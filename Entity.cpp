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
	mProperties(),
	mSkipFrame( false )
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

}

SDL_Color Entity::getColor() const
{
	return mColor;
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

int Entity::getSpeedPerTick() const
{
	return mSpeedPerTick;
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
	if( hasProperty( EntityProperty::SLOWED_HALF )  )
	{
		mSkipFrame = !mSkipFrame;
	}

	if( !mSkipFrame )
	{
		executeBehaviors( this );
		executeMisc();	// Overriden by derived Entities to provide custom innate behavior outside EntityBehavior's
	}
}