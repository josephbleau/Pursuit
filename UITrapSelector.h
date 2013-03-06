#ifndef UITRAPSELECTOR_H
#define UITRAPSELECTOR_H

#include "UIElement.h"

class UITrapSelector : public UIElement
{
public:
	UITrapSelector( int x, int y, int w, int h);

	void update( Game* game ); // override
	void render( SDL_Surface* screen ); //render
};

#endif