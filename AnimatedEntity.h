#ifndef ANIMATEDENTITY_H
#define ANIMATEDENTITY_H

#include "AnimationPlayer.h"
#include "Entity.h"

class SpriteAnimation;

class AnimatedEntity : public Entity, public AnimationPlayer
{
private:
	void executeMisc(); //override, final

public:
	AnimatedEntity( Game* game, int x, int y, int w, int h );
	virtual ~AnimatedEntity() = 0 {};

	virtual void render( SDL_Surface* screen) const;
};

#endif