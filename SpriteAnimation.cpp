#include "SpriteAnimation.h"

#include "ImageLoadException.h"

SpriteAnimation::SpriteAnimation( std::string filename, int framewidth, int frameheight ) :
	mTicksPerFrame( 0 ),
	mLastTick( 0 ),
	mNumRows( 0 ),
	mNumCols( 0 ),
	mFrameWidth( framewidth ),
	mFrameHeight( frameheight ),
	mIsLooping( false ),
	mIsPaused( false )
{
	SDL_Surface* image = NULL;
	image = IMG_Load( filename.c_str() );

	if( image == NULL ) 
	{
		throw ImageLoadException( filename );
	}

	mResource = std::shared_ptr<SDL_Surface>( image );

	const int& imageWidth = mResource->w;
	const int& imageHeight = mResource->h;

	mNumRows = imageWidth / framewidth;
	mNumCols = imageHeight / frameheight;

	mClipRect.x = 0;
	mClipRect.y = 0;
	mClipRect.w = framewidth;
	mClipRect.h = frameheight;
}

void SpriteAnimation::update()
{
}

void SpriteAnimation::render( SDL_Surface* screen )
{
}