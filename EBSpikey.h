#ifndef EBSPIKEY_H
#define EBSPIKEY_H

/* EPSpikey is an Entitybehavior which causes any collision with
   the entity who owns it damage to the other entity, as determined
   by mDamageValue. 

   **NOTE**: Both entities must have the COLLIDABLE property, and the 
   other entity involved must not have the INVINCIBLE property, the other
   entity must also have the EBStats behavior. 
*/

#include "EntityBehavior.h"

class EBSpikey : public EntityBehavior
{
private:
	int mDamageValue;	// How much the spikes do.

public:
	EBSpikey( int value );

	std::string getMyType() const; // Override
	void run( Entity* owner ); // Override
};

#endif 