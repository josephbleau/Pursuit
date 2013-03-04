#ifndef EBFOLLOW_H
#define EBFOLLOW_H

/* EBFollow is an EntityBehavior specifically designed for 
   enemies. It causes them to track to our player entity which
   is an entity referenced in a special member in our Game class.
   This property simply checks our entities location with respect
   to the players, and moves it closer by one SpeedPerTick */

#include "EntityBehavior.h"

class EBFollow : public EntityBehavior 
{
public:
	EBFollow();
	~EBFollow();

	std::string getMyType( ) const;	// Override
	void run( Entity* owner );	// Override
};

#endif