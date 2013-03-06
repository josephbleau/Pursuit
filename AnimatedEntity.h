#ifndef ANIMATEDENTITY_H
#define ANIMATEDENTITY_H

#include "Entity.h"

class SpriteAnimation;

class AnimatedEntity : public Entity
{
private:
	std::shared_ptr<SpriteAnimation> mAnimation;
	
	void updateMisc(); //override

public:
	AnimatedEntity( Game* game, int x, int y, int w, int h, 
		            std::shared_ptr<SpriteAnimation> animation );
	
	void render( SDL_Surface* screen) const;
};

#endif