#ifndef ANIMATEDENTITY_H
#define ANIMATEDENTITY_H

#include <map>
#include <string>

#include "Entity.h"

#include "AnimationPlayer.h"
#include "ResourceManager.h"

class AnimationPlayer;
class SpriteAnimation;

class AnimatedEntity : public Entity
{
private:
	std::shared_ptr<AnimationPlayer> mAnimationPlayer;

	virtual void executeMisc() = 0; //override

public:
	AnimatedEntity( Game* game, int x, int y, int w, int h );
	virtual ~AnimatedEntity() = 0 {};

	virtual void render( SDL_Surface* screen) const;

	void setAnimation( std::string animationName );
	void setAnimationSpeed( Uint32 ticksPerFrame );
};

#endif