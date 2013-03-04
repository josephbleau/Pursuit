#ifndef ENTITYBEHAVIOR_H
#define ENTITYBEHAVIOR_H

#include <functional>
#include <string>
#include <typeinfo>

#include "EntityBehaviorHandler.h"

class Entity;

class EntityBehavior : public EntityBehaviorHandler
{
public:
	EntityBehavior();
	virtual ~EntityBehavior() = 0;
	
	virtual std::string getMyType() const = 0;
	virtual std::string getParentType() const;

	void runAs( Entity* owner );
	virtual void run( Entity* owner ) = 0;
};

#endif