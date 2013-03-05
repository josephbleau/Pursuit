#ifndef ENTITYBEHAVIORHANDLER_H
#define ENTITYBEHAVIORHANDLER_H

#include <iostream>
#include <memory>
#include <typeinfo>
#include <vector>

class Entity;
class EntityBehavior;

class EntityBehaviorHandler
{
private:
	std::vector<std::shared_ptr<EntityBehavior>> mBehaviors;

public:
	EntityBehaviorHandler();
	virtual ~EntityBehaviorHandler();

	void executeBehaviors( Entity* owner);
	void giveBehavior( EntityBehavior* behavior );
	void giveBehavior( std::shared_ptr<EntityBehavior> behavior );
	
	template <typename T>
	void giveBehavior()
	{
		mBehaviors.push_back( std::make_shared<T>( T() ) );
	}

	template <typename T>
	T* getBehaviorByClass()
	{
		for( auto it = mBehaviors.begin();
			 it != mBehaviors.end();
			 ++it )
		{
			try {
				T* behavior = dynamic_cast<T*>( (*it).get() );	// If the user passes an unexpected type, this will throw.
				T const *  t;
			
				if(behavior == NULL )
					continue;

				if( behavior->getMyType().compare( typeid( t ).name() ) == 0 ) 
				{
					return behavior;
				}
			}
			catch (...) {
				return NULL;
			}
		}

		return NULL;
	}

	template <typename T>
	bool hasBehavior()
	{
		return ( getBehaviorByClass<T>() != NULL );
	}

};

#endif