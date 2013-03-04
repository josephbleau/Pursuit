#include "EBSticky.h"

#include "Entity.h"
#include "EntityProperties.h"
#include "Game.h"
#include "GameHelper.h"

EBSticky::EBSticky(  ) 
{
}

std::string EBSticky::getMyType() const
{
	return typeid( this ).name();
}

void EBSticky::run( Entity* owner )
{
	Game* game = owner->getGame();
	auto& entities = game->getEntities(); 
	for( auto entity : entities )
	{
		if( entity.get() == owner )	// Don't compare to ourselves.
			continue;
			
		if( GameHelper::rectsCollide( owner->getRect(), entity->getRect() ) )
		{
			if( entity->hasProperty( EntityProperty::COLLIDABLE ) &&
			    !entity->hasProperty( EntityProperty::INVINCIBLE ) )
			{
				// Does not affect the player if the behavior is friendly
				if( isFriendly() && entity == game->getPlayerEntity() )
					break;

				entity->giveProperty( EntityProperty::SLOWED_HALF );
			}
		}
	}
}