#include "SpriteAnimation.h"

#include <iostream>

#include "ImageLoadException.h"
#include "ResourceManager.h"

SpriteAnimation::SpriteAnimation( std::string filename, int framewidth, int frameheight ) :
	mNumRows( 0 ),
	mNumCols( 0 ),
	mFrameWidth( framewidth ),
	mFrameHeight( frameheight ),
	mIsLooping( true ),
	mResource ( NULL )
{
	/* Maybe I should throw an exception here? Our object is pretty 
	   useless if this is the case anyway. */
	if( frameheight < 1 ||
		framewidth < 1 )
	{
		std::cerr << "Error in SpriteAnimation, either frame width, or frame height found to be less than one.";
		
		// Provide a usable width and height. 
		frameheight = std::max(frameheight, 1);
		framewidth = std::max(framewidth, 1);
	}

	SDL_Surface* image = NULL;
	image = IMG_Load( filename.c_str() );
	if( image == NULL )
	{
		throw ImageLoadException( filename );
	}

	mResource = std::shared_ptr<SDL_Surface>( image );

	const int imageWidth = mResource->w;
	const int imageHeight = mResource->h;
	mNumRows = imageWidth / framewidth;
	mNumCols = imageHeight / frameheight;
}

SDL_Rect SpriteAnimation::getFrameRect( int frame ) const
{
	SDL_Rect frameRect = { 
		(frame / std::max( mNumCols, 1 ))  * mFrameHeight,
		(frame % std::max( mNumCols, 1 )) * mFrameWidth,
		frameRect.w = mFrameWidth,
		frameRect.h = mFrameHeight
	};

	return frameRect;
}

int SpriteAnimation::getNumFrames() const
{
	return mNumRows * mNumCols;  
}

const std::shared_ptr<SDL_Surface>& SpriteAnimation::getTexture() const
{
	return mResource;
}


bool SpriteAnimation::isLooping() const
{
	return mIsLooping;
}