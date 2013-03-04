#include "EBSpikey.h"

#include "EBStats.h"
#include "Entity.h"
#include "EntityProperties.h"
#include "Game.h"
#include "GameHelper.h"

EBSpikey::EBSpikey( int value ) :
	mDamageValue( value )
{
}

std::string EBSpikey::getMyType() const
{
	return typeid( this ).name();
}

void EBSpikey::run( Entity* owner )
{
	Game* game = owner->getGame();
	auto& entities = game->getEntities(); 
	for( auto entity : entities )
	{
		if( entity.get() == owner )	// Doesn't hurt the owner.
			continue;
			
		if( GameHelper::rectsCollide( owner->getRect(), entity->getRect() ) )
		{
			/* Only affects players who have the EBStats behavior,
			   are collidable, and aren't invincibile */
			if( entity->hasBehavior<EBStats>() &&
			    entity->hasProperty( EntityProperty::COLLIDABLE ) &&
			    !entity->hasProperty( EntityProperty::INVINCIBLE ) )
			{
				// This should not damage the player if the behavior is friendly. 
				if( isFriendly() && entity == game->getPlayerEntity() )
					break;

				entity->getBehaviorByClass<EBStats>()->damage( mDamageValue );
			}
		}
	}
}