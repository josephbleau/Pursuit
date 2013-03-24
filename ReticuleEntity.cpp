#include "ReticuleEntity.h"

#include "SDL/SDL.h"
#include <iostream>

#include "EBStats.h"

#include "EntityTrap.h"
#include "ProjectileEntity.h"
#include "PlayerEntity.h"
#include "Game.h"

ReticuleEntity::ReticuleEntity( Game* parent, int x, 
							    int y, int w, int h ) :
	Entity( parent, x, y, w, h )
{
}

void ReticuleEntity::executeMisc()
{
	int mouseX = 0;
	int mouseY = 0;

	/* Seriously, what the fuck? SDL? Really? What the hell is this.
	   This is how I have to poll the mouse state if I don't want to use
	   SDL_Event. Now that's a paddlin'. */
	int clicking_right = SDL_GetMouseState( &mouseX, &mouseY ) & SDL_BUTTON_RMASK;
	int clicking_left = SDL_GetMouseState( & mouseX, &mouseY ) & SDL_BUTTON_LMASK;
	teleport( mouseX, mouseY );
	
	/* If the mouse is clicked, we need to check our PlayerEntity
	   and if he isn't on cooldown from the last trap, we need to place
	   the trap that he has readied. */

	/* I'm probably "doin' it wrong" but seriously, I wanted a std::shared_ptr<PlayerEntity> but
	   It has no way of coercing a std::shared_ptr<Entity> to that type (that I know of, please educate me
	   if I'm wrong!:D), so I cheated. */
	PlayerEntity* playerEntity = dynamic_cast<PlayerEntity*>( getGame()->getPlayerEntity().get() );  
	
	
	if( clicking_right )	
	{
		if( playerEntity->isTrapReady() )
		{
			EntityTrap* trap = playerEntity->getNextTrap(); // Trap timer is reset
			if( trap != NULL )
			{
				trap->teleport( mouseX, mouseY );
				getGame()->giveEntity( trap );
			}
		}
	}

	if( clicking_right )
	{
		/* Get stat block */
		EBStats* stats = playerEntity->getBehaviorByClass<EBStats>();
		if(stats->getEnergy()) {
			ProjectileEntity* projectile = new ProjectileEntity( 
				getGame(),
				mouseX,
				mouseY,
				5,
				5,
				1,
				1
			);

			getGame()->giveEntity( projectile );
		}
	}
}
