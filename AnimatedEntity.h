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

	void executeMisc(); //override, final
public:
	AnimatedEntity( Game* game, int x, int y, int w, int h );
	virtual ~AnimatedEntity() = 0 {};

	virtual void render( SDL_Surface* screen) const;

	void setAnimation( std::string animationName );
};

#endif