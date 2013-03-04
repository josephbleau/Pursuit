#ifndef EBSTICKY_H
#define EBSTICKY_H

/* EBSticky is an EntityBehavior which gives players who collide with the
   entity who owns it the 'SLOWED_HALF' property. See EntityProperties.h 
   for more details about SLOWED_HALF */

#include "EntityBehavior.h"

class EBSticky : public EntityBehavior
{
public:
	EBSticky( );

	std::string getMyType() const; // Override
	void run( Entity* owner ); // Override
};

#endif