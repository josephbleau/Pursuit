#include "UIHealthBar.h"

#include "EBStats.h"
#include "Entity.h"
#include "Game.h"

UIHealthBar::UIHealthBar( int x, int y, int w, int h ) :
	UIElement( x, y, w, h ),
	mPct( 1.0f )
{
	
}

void UIHealthBar::update( Game* game )
{
	/* The health bar is only concerned with our players
	   health, so we're going to query the game state for it
	   as well as it's max health, and from there we'll have
	   our percentage. */

	std::shared_ptr<Entity> playerEntity( game->getPlayerEntity() );

	EBStats* playerStats = playerEntity->getBehaviorByClass<EBStats>();

	if( playerStats != NULL )
	{
		int curHealth = playerStats->getHealth();
		int maxHealth = playerStats->getMaxHealth();

		if( maxHealth != 0 )	// Why would it be? Not sure. Better safe than sorry.
		{
			mPct = static_cast<float>(curHealth) / static_cast<float>(maxHealth);
		}
		else
		{
			mPct = 0.0f;
		}
	}
}

void UIHealthBar::render( SDL_Surface* screen ) const
{
	/* TODO: I need to devise some way of determining the screen size 
	         so I can scale user interface elements appropriately, right now
			 I'm just going to draw them at fixed locations since I probably
			 won't have very many for this application. */

	/* The health bar is just two rects, 1 outter black rect,
	   and one inner red rect which is mPct percent of the black rects
	   width (with a sliver off the width and height for a border ) */

	/* *NOTE*: Cheating here and casting constness away, because I know that SDL_FillRect doesn't
	   actually modify our rect, it just wont accept a const parameter because whoever wrote SDL
	   hates const correctness. */
	SDL_FillRect( screen, const_cast<SDL_Rect*>(&mRect), SDL_MapRGB( screen->format, 0, 0, 0 ) ); // BG & Border
	
	// Offset 1 pixel on each side for border.
	SDL_Rect innerRect = mRect;
	innerRect.x++;
	innerRect.y++;
	innerRect.h -= 2;
	innerRect.w = std::max(static_cast<Uint8>( mPct * mRect.w  ) - 2, 0);
	
	SDL_FillRect( screen, &innerRect, SDL_MapRGB( screen->format, 255, 0, 0 ) );	// Red part. :D
}

