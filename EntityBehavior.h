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
	bool mFriendly;	// This is set to false by default, when it's true the behavior should NOT affect the player.

public:
	EntityBehavior();
	virtual ~EntityBehavior() = 0;
	
	virtual std::string getMyType() const = 0;
	virtual std::string getParentType() const;

	virtual inline bool isFriendly();
	virtual inline void makeHarmful();
	virtual inline void makeFriendly();

	void runAs( Entity* owner );
	virtual void run( Entity* owner ) = 0;
};

#endif