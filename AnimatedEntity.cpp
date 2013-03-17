#include <string>

#include "AnimatedEntity.h"
#include "EntityProperties.h"
#include "Game.h"
#include "ResourceManager.h"


AnimatedEntity::AnimatedEntity( Game* game, int x, int y, int w, int h ) :
	Entity( game, x, y, w, h ),
	mAnimationPlayer( new AnimationPlayer(game->getResourceManager()) )
{}

void AnimatedEntity::executeMisc()
{
	if( mAnimationPlayer )
		mAnimationPlayer->animUpdate();
}

void AnimatedEntity::render( SDL_Surface* screen ) const
{
	if(!hasProperty( EntityProperty::HIDDEN ) )
	{
		if( mAnimationPlayer &&  mAnimationPlayer->isAnimationEnabled() == true )
		{
			mAnimationPlayer->renderAt( screen, getRect().x, getRect().y );
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

void AnimatedEntity::setAnimation( std::string animationName ) 
{
	if(mAnimationPlayer)
		mAnimationPlayer->setAnimation( animationName );
}