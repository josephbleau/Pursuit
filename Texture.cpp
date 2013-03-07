#include "Texture.h"

Texture::Texture( SDL_Surface* texture ) :
	mSurface( texture )
{

}

Texture::~Texture()
{
	SDL_FreeSurface( mSurface ); // Safe even if surface is NULL
}

int Texture::getWidth() const 
{
	if( mSurface ) 
		return mSurface->w;

	return 0;
}

int Texture::getHeight() const
{
	if( mSurface )
		return mSurface->h;

	return 0;
}