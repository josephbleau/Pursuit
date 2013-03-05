#include "EntityBehavior.h"
#include "Entity.h"

#include <typeinfo>

EntityBehavior::EntityBehavior() :
	mFriendly( false )
{

}

std::string EntityBehavior::getParentType() const 
{
	return typeid( Entity ).name();
}

bool EntityBehavior::isFriendly() 
{
	return mFriendly;
}

void EntityBehavior::makeHarmful()
{
	mFriendly = false;
}

void EntityBehavior::makeFriendly()
{
	mFriendly = true;
}

void EntityBehavior::runAs( Entity* owner )
{
	if( owner == NULL )
		return;

	this->run( owner );
	this->executeBehaviors( owner );
}
