#include "EntityBehavior.h"
#include "Entity.h"

#include <typeinfo>

EntityBehavior::EntityBehavior() :
	mFriendly( false )
{

}

EntityBehavior::~EntityBehavior()
{

}

std::string EntityBehavior::getParentType() const 
{
	return typeid( Entity ).name();
}

inline bool EntityBehavior::isFriendly() 
{
	return mFriendly;
}

inline void EntityBehavior::makeHarmful()
{
	mFriendly = false;
}

inline void EntityBehavior::makeFriendly()
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
