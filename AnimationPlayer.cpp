#include "AnimationPlayer.h"

#include <iostream>

#include "ResourceManager.h"
#include "SpriteAnimation.h"

AnimationPlayer::AnimationPlayer( std::shared_ptr<ResourceManager> resourceMgr ) :
	mResourceMgr( resourceMgr ),
	mCurFrame( 0 ),
	mLastTick( 0 ),
	mTicksPerFrame( 2000 ),
	mIsLooping( true ),
	mIsPaused( true ),
	mIsEnabled( false )
{
}

AnimationPlayer::AnimationPlayer( std::shared_ptr<ResourceManager> resourceMgr,
								  std::string animationName ) :
	mResourceMgr( resourceMgr ),
	mCurFrame( 0 ),
	mLastTick( 0 ),
	mTicksPerFrame( 2000 ),
	mIsLooping( false ),
	mIsPaused( false ),
	mIsEnabled( true )
{
	mAnimation = resourceMgr->getSpriteAnimation( animationName );
}

void AnimationPlayer::disableAnimation()
{
	mIsEnabled = false;
}

void AnimationPlayer::enableAnimation()
{
	mIsEnabled = true;
}

bool AnimationPlayer::isAnimationEnabled() const
{
	return mIsEnabled;
}


void AnimationPlayer::renderAt( SDL_Surface* screen, int x, int y ) const
{
	if( mIsEnabled == true )
	{
		SDL_Rect frameRect = mAnimation->getFrameRect( mCurFrame );
		SDL_Rect renderRect = { x, y, frameRect.w, frameRect.h };

		std::cout << "frame rect: " << frameRect.x << ", " << frameRect.y << ", " << frameRect.w << ", " << frameRect.h << std::endl;

		const std::shared_ptr<SDL_Surface>& texture = mAnimation->getTexture(); 

		SDL_BlitSurface( texture.get(), &frameRect, screen, &renderRect );
	}
}

void AnimationPlayer::animUpdate()
{
	if( mIsPaused == false && mIsEnabled == true )
	{
		const Uint32 curTick = SDL_GetTicks();
		const int numFrames = mAnimation->getNumFrames();

		std::cout << mCurFrame << std::endl;

		if( curTick - mLastTick >= mTicksPerFrame )
		{
			mLastTick = SDL_GetTicks();
			++mCurFrame;

			if( mCurFrame >= numFrames ) 
			{
				if( mIsLooping )
				{
					mCurFrame = 0;
				}
				else 
				{
					mIsPaused = true;
					--mCurFrame;	// Leave the frame as the last one.
				}
			}				
		}
	}
}

bool AnimationPlayer::setAnimation( std::string animationName )
{
	mAnimation = mResourceMgr->getSpriteAnimation( animationName );
	
	if( mAnimation != NULL )
	{
		std::cout << "?";
		mIsPaused = false;
		mIsEnabled = true;
		return true;
	}

	return false;
}