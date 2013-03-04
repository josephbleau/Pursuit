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
		if( entity.get() == owner )	// Don't compare to ourselves.
			continue;
			
		if( GameHelper::rectsCollide( owner->getRect(), entity->getRect() ) )
		{
			if( entity->hasBehavior<EBStats>() &&
			    entity->hasProperty( EntityProperty::COLLIDABLE ) &&
			    !entity->hasProperty( EntityProperty::INVINCIBLE ) )
			{
				entity->getBehaviorByClass<EBStats>()->damage( mDamageValue );
			}
		}
	}
}