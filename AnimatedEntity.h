#ifndef ANIMATEDENTITY_H
#define ANIMATEDENTITY_H

#include "Entity.h"

class SpriteAnimation;

class AnimatedEntity : public Entity
{
private:
	std::shared_ptr<SpriteAnimation> mAnimation;
	bool mAnimationEnabled;

	void executeMisc(); //override, final

public:
	AnimatedEntity( Game* game, int x, int y, int w, int h );
	virtual ~AnimatedEntity() = 0 {};

	void disableAnimation();
	void enableAnimation();
	bool isAnimationEnabled() const;

	virtual void render( SDL_Surface* screen) const;
};

#endif