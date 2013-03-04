#ifndef UIHEALTHBAR_H
#define UIHEALTHBAR_H

#include "UIElement.h"

class UIHealthBar  : public UIElement
{
private:
	float mPct; // Bar fill percentage

public:
	UIHealthBar( int x, int y, int w, int h );

	void update( Game* game ); // override
	void render( SDL_Surface* screen ) const; //override
};

#endif