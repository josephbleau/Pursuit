#include "Spell.h"

Spell::Spell( Game* game,
	          std::shared_ptr<Entity> source,
			  std::shared_ptr<Entity> target,
			  std::string spellScript ) :
	AnimatedEntity(game, 0, 0, 0, 0),
	mSource(source),
	mTarget(target)
	{}

void Spell::executeMisc()
{
}