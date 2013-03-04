#ifndef ENTITYPROPERTIES_H
#define ENTITYPROPERTIES_H

/* Entity properties are different than EntityBehaviors, properties are simply
   things that the entity "are", not things that the entity "can do." For example
   one such property might be 'collidable.' If a property becomes more than a
   simple flag it should be recreated as a behavior. */

enum EntityProperty {
	COLLIDABLE,			// Entity cannot be passed through. (TODO: Fully implement.)
	INVINCIBLE,			// Entity cannot be damaged 
	PLAYERCONTROLLED,	// Entity is controlled by player input
	HIDDEN,				// Entity isn't drawn
	DESTROY_ON_DEATH,	// Entity is destroyed when it runs out of health (if it has EBStats behavior) 
	SLOWED_HALF			// Entity moves at half its normal speed. (We're going to implement this by forcing them to skip every other update. )
};

#endif