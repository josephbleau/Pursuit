#ifndef UIELEMENT_H
#define UIELEMENT_H

#include "SDL/SDL.h"

#include "Renderable.h"

class Game;

class UIElement : public Renderable
{
protected:
	SDL_Rect mRect;

public:
	UIElement( int x, int y, int w, int h );
	virtual ~UIElement() = 0 {};

	virtual void update( Game* game ) = 0;
	virtual void render( SDL_Surface* screen ) const = 0;
};

#endif