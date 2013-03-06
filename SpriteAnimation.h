#ifndef SPRITEANIMATION_H
#define SPRITEANIMATION_H

/* SpriteAnimation is a simple 2D sprite animation class that clips a 
   picture according to its constructor and displays a new frame every 
   x-ticks (real time) as specified. It depends on SDL_Image which
   depends on numerous 3rd party libraries for image loading. */

#include <memory>
#include <string>

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include "Renderable.h"

class SpriteAnimation
{
private:
	/* NOTE: mTicksPerFrame's ticks are fundamentally different than "game-ticks", 
	         ticks here refers to actual 'real time' as reported by SDL_GetTicks(); */	      
	Uint32 mTicksPerFrame;		
	Uint32 mLastTick;

	SDL_Rect mClipRect;

	int mCurFrame;
	int mNumRows;
	int mNumCols;
	int mFrameWidth;
	int mFrameHeight;

	bool mIsLooping;	
	bool mIsPaused;

	std::shared_ptr<SDL_Surface> mResource;	// The sprite

public:
	/* Note: ctor can throw an ImageLoadException */
	SpriteAnimation( std::string filename, int framewidth, int frameheight );

	void update();
	void renderAt( SDL_Surface* screen, int x, int y ) const;
};

#endif