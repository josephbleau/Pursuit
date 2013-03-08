#include <string>

#include "AnimatedEntity.h"
#include "AnimationPlayer.h"
#include "EntityProperties.h"
#include "Game.h"


AnimatedEntity::AnimatedEntity( Game* game, int x, int y, int w, int h ) :
	Entity( game, x, y, w, h ),
	AnimationPlayer( game->getResourceManager() )
{

}

void AnimatedEntity::executeMisc()
{

}

void AnimatedEntity::render( SDL_Surface* screen ) const
{
	if( !hasProperty( EntityProperty::HIDDEN ) )
	{
		if( isAnimationEnabled() == true )
		{
			renderAt( screen, getRect().x, getRect().y );
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