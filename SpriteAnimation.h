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

class SpriteAnimation
{
private:
	/* NOTE: mTicksPerFrame's ticks are fundamentally different than "game-ticks", 
	         ticks here refers to actual 'real time' as reported by SDL_GetTicks(); */	      
	int mNumRows;
	int mNumCols;
	int mFrameWidth;
	int mFrameHeight;

	bool mIsLooping;	

	SDL_Surface* mResource;

public:
	/* Note: ctor can throw an ImageLoadException */
	SpriteAnimation(); // Default ctor for std::map
	SpriteAnimation( std::string filename, int framewidth, int frameheight );
	~SpriteAnimation();

	SDL_Rect getFrameRect( int frame ) const;
	int getNumFrames() const;

	bool isLooping() const;
	Uint32 getTicksPerFrame() const;
	const SDL_Surface* getTexture() const;
	
	
};

#endif