#ifndef TEXTURE_H
#define TEXTURE_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include "Resource.h"

class Texture : public Resource
{
private:
	SDL_Surface* mSurface;
	
public:
	Texture( SDL_Surface* source );
	~Texture();

	int getWidth() const;
	int getHeight() const;
};

#endif