#ifndef RENDERABLE_H
#define RENDERABLE_H

#include "SDL/SDL.h"

class Renderable 
{
public:
	virtual ~Renderable() = 0 {};
	virtual void render(SDL_Surface* screen) const = 0;
};

#endif