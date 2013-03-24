#ifndef SPELL_H
#define SPELL_H

#include <memory>

#include "SDL/SDL.h"

#include "AnimatedEntity.h"


class Spell : public AnimatedEntity
{
private:
	std::shared_ptr<Entity> mSource;
	std::shared_ptr<Entity> mTarget;

	bool mIsPassive;

public:
	Spell(Game* game,
		  std::shared_ptr<Entity> source, 
		  std::shared_ptr<Entity> target,
		  std::string spellScript);

	void executeMisc(); // Override

};

#endif