#ifndef ANIMATIONPLAYER_H
#define ANIMATIONPLAYER_H

#include <memory>
#include <string>

#include "SDL/SDL.h"

class ResourceManager;
class SpriteAnimation;

class AnimationPlayer
{
private:
	std::shared_ptr<SpriteAnimation> mAnimation;
	std::shared_ptr<ResourceManager> mResourceMgr;

	int mCurFrame;
	Uint32 mLastTick;
	Uint32 mTicksPerFrame;

	bool mIsLooping;
	bool mIsPaused;
	bool mIsEnabled;

public:
	AnimationPlayer( std::shared_ptr<ResourceManager> resourceMgr );
	AnimationPlayer( std::shared_ptr<ResourceManager> resourceMgr, 
		             std::string animationName );

	void disableAnimation();
	void enableAnimation();
	bool isAnimationEnabled() const;

	void animUpdate();
	void renderAt( SDL_Surface* screen, int x, int y ) const;

	bool setAnimation( std::string animationName );
};

#endif