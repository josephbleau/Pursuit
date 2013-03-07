#include "SpriteAnimation.h"

#include <iostream>

#include "ImageLoadException.h"
#include "ResourceManager.h"

SpriteAnimation::SpriteAnimation( std::string filename, int framewidth, int frameheight ) :
	mTicksPerFrame( 0 ),
	mLastTick( 0 ),
	mCurFrame( 0 ),
	mNumRows( 0 ),
	mNumCols( 0 ),
	mFrameWidth( framewidth ),
	mFrameHeight( frameheight ),
	mIsLooping( false ),
	mIsPaused( false ),
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

	const int imageWidth = mResource->w;
	const int imageHeight = mResource->h;
	mNumRows = imageWidth / framewidth;
	mNumCols = imageHeight / frameheight;

	mClipRect.x = 0;
	mClipRect.y = 0;
	mClipRect.w = framewidth;
	mClipRect.h = frameheight;
}

void SpriteAnimation::renderAt( SDL_Surface* screen, int x, int y ) const
{
	SDL_Rect renderRect = { x, y, mFrameWidth, mFrameHeight };
	SDL_BlitSurface( screen, const_cast<SDL_Rect*>(&mClipRect), mResource.get(), &renderRect ); 
}

void SpriteAnimation::update()
{
	if( mIsPaused == false )
	{
		const Uint8 curTick = SDL_GetTicks();
		const int numFrames = mNumRows * mNumCols;  

		if( curTick - mLastTick >= mTicksPerFrame )
		{
			mLastTick = SDL_GetTicks();
			++mCurFrame;

			if( mCurFrame == numFrames ) 
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

			mClipRect.x = (mCurFrame % mNumCols) * mFrameWidth;
			mClipRect.y = (mCurFrame / mNumCols)  * mFrameHeight;					
		}
	}
}