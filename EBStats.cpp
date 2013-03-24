#include "EBStats.h"

#include "Entity.h"
#include "EntityProperties.h"
#include "Game.h"

EBStats::EBStats() :
	mAlive( true ),
	mHealth( 100 ),
	mMaxHealth( 100 )
{
}


EBStats::~EBStats()
{
}

bool EBStats::depleteEnergy( int energy )
{
	if( mEnergy - energy <= 0 )
	{
		mEnergy = 0;
		return false;
	}
	else
	{
		mEnergy = mEnergy - energy;
	}

	return true;
}

bool EBStats::damage( int damage )
{
	if( mHealth - damage <= 0 )
	{
		mHealth = 0;
		mAlive = false;
	}
	else
	{
		mHealth = mHealth - damage;
	}

	return mAlive;
}

int EBStats::getHealth() const
{
	return mHealth;
}

int EBStats::getMaxHealth() const
{
	return mMaxHealth;
}

int EBStats::getEnergy() const
{
	return mEnergy;
}

int EBStats::getMaxEnergy() const 
{
	return mMaxEnergy;
}

std::string EBStats::getMyType() const
{
	return typeid( this ).name();
}

bool EBStats::isAlive() const
{
	return mAlive;
}

void EBStats::run( Entity* owner )
{
	if( !isAlive() && 
		owner->hasProperty( EntityProperty::DESTROY_ON_DEATH ) ) 
	{
		owner->destroy(); // Bye!
	}
}
