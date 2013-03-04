#include "EntityBehavior.h"
#include "Entity.h"

#include <typeinfo>

EntityBehavior::EntityBehavior() 
{

}

EntityBehavior::~EntityBehavior()
{

}

std::string EntityBehavior::getParentType() const 
{
	return typeid( Entity ).name();
}

void EntityBehavior::runAs( Entity* owner )
{
	if( owner == NULL )
		return;

	this->run( owner );
	this->executeBehaviors( owner );
}