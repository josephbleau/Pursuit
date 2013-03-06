#include <string>

#include "AnimatedEntity.h"
#include "Game.h"
#include "SpriteAnimation.h"

AnimatedEntity::AnimatedEntity( Game* game, int x, int y, int w, int h, 
							    std::shared_ptr<SpriteAnimation> animation ) :
	Entity( game, x, y, w, h ),
	mAnimation( animation )
{

}

void AnimatedEntity::updateMisc()
{
	if( mAnimation != NULL )
	{
		mAnimation->update();
	}
}

void AnimatedEntity::render( SDL_Surface* screen ) const
{
	mAnimation->renderAt( screen, getRect().x, getRect().y );
}