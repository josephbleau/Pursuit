#include <string>

#include "AnimatedEntity.h"
#include "EntityProperties.h"
#include "Game.h"
#include "SpriteAnimation.h"

AnimatedEntity::AnimatedEntity( Game* game, int x, int y, int w, int h ) :
	Entity( game, x, y, w, h ),
	mAnimationEnabled( false ),
	mAnimation( NULL )
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
	if( !hasProperty( EntityProperty::HIDDEN ) )
	{
		if( mAnimationEnabled )
		{
			mAnimation->renderAt( screen, getRect().x, getRect().y );
		}
		else {
	
			SDL_Rect rect = getRect();
			SDL_Color color = getColor();

			SDL_FillRect( screen, &rect, 
							SDL_MapRGB( 
								screen->format, 
								color.r,
								color.g,
								color.b
							) 
			); 	
		}
	}
}

void AnimatedEntity::setAnimation( std::shared_ptr<SpriteAnimation> animation )
{
	mAnimation = animation;
}