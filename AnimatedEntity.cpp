#include <string>

#include "AnimatedEntity.h"
#include "Game.h"
#include "SpriteAnimation.h"

AnimatedEntity::AnimatedEntity( Game* game, int x, int y, int w, int h ) :
	Entity( game, x, y, w, h ),
	mAnimationEnabled( true )
{

}

void AnimatedEntity::disableAnimation()
{
	mAnimationEnabled = false;
}

void AnimatedEntity::enableAnimation()
{
	mAnimationEnabled = true;
}

bool AnimatedEntity::isAnimationEnabled() const
{
	return mAnimationEnabled;
}

void AnimatedEntity::executeMisc()
{
	if( mAnimation != NULL )
	{
		mAnimation->update();
	}
}

void AnimatedEntity::render( SDL_Surface* screen ) const
{
	if( mAnimationEnabled )
	{
		mAnimation->renderAt( screen, getRect().x, getRect().y );
	}
	else
	{
		// Still draw something even if the animation failed to load.
	}

}