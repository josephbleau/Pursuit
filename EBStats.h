#ifndef EBSTATS_H
#define EBSTATS_H

/* EBStats is an EntityBehavior which gives very basic statistics
   and the ability to act / work on those. Health is the only statistic
   currently implemented, with an interface to decrement it, and track
   whether or not the entity is 'alive.'

   TODO: Other behaviors may be interested in knowing whether or not
   our entity has died, some sort of event listener / registration
   may eventually work its way into EntityBehaviors in some general form. */

#include <vector>
#include <memory>

#include "EntityBehavior.h"
#include "Spell.h"
enum EntityProperty;

class EBStats : public EntityBehavior
{
private:
	bool mAlive;
	int mHealth;
	int mMaxHealth;
	int mEnergy;
	int mMaxEnergy;
	
	std::vector<Spell> mPassiveSpells;

public:
	EBStats();
	virtual ~EBStats();

	bool damage( int damage );
	bool depleteEnergy( int energy );

	int getHealth() const;
	int getMaxHealth() const;
	int getEnergy() const;
	int getMaxEnergy() const;

	std::string getMyType() const; // Override

	bool isAlive() const;

	void run( Entity* owner);
};

#endif