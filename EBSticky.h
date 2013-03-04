#ifndef EBSTICKY_H
#define EBSTICKY_H

#include "EntityBehavior.h"

class EBSticky : public EntityBehavior
{
public:
	EBSticky( );

	std::string getMyType() const; // Override
	void run( Entity* owner ); // Override
};

#endif