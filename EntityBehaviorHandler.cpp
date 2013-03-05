#include "EntityBehaviorHandler.h"

#include "Entity.h"
#include "EntityBehavior.h"

EntityBehaviorHandler::EntityBehaviorHandler() :
	mBehaviors()
{
}


EntityBehaviorHandler::~EntityBehaviorHandler()
{
}

void EntityBehaviorHandler::executeBehaviors( Entity* owner )
{
	for( auto behavior = mBehaviors.begin();
		 behavior != mBehaviors.end();
		 ++behavior )
	{
		(*behavior)->runAs( owner );
	}
}

void EntityBehaviorHandler::giveBehavior( EntityBehavior* behavior )
{
	if( behavior == NULL )
	{
		return;
	}

	/* Entity Behaviors can have sub-behaviors, and when they do they 
	   are instructed to override getParentType and have it return the type
	   which owns them. In the default case, Entity's type name is returned
	   and that's how we know we're just inserting a regular behavior. Otherwise
	   we search for the parent behavior, and insert the sub-behavior there. */
	std::string parentType = behavior->getParentType( );
	if( behavior->getParentType() == typeid( Entity ).name() )
	{
		mBehaviors.push_back( std::shared_ptr<EntityBehavior>( behavior ) );
	}
	else
	{
		for( auto parent = mBehaviors.begin();
			 parent != mBehaviors.end();
			 ++parent )
		{
			if( (*parent)->getMyType() == behavior->getParentType() )
			{
				(*parent)->giveBehavior( behavior );
			}
		}
	}
}


void EntityBehaviorHandler::giveBehavior( std::shared_ptr<EntityBehavior> behavior ) 
{
	std::string parentType = behavior->getParentType( );
	if( behavior->getParentType() == typeid( Entity ).name() )
	{
		mBehaviors.push_back( behavior  );
	}
	else
	{
		for( auto parent = mBehaviors.begin();
			 parent != mBehaviors.end();
			 ++parent )
		{
			if( (*parent)->getMyType() == behavior->getParentType() )
			{
				(*parent)->giveBehavior( behavior );
			}
		}
	}
}