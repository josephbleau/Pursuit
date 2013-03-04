#include "UIElement.h"

#include "Game.h"

UIElement::UIElement( int x, int y, int w, int h ) 
{
	mRect.x = x;
	mRect.y = y;
	mRect.w = w;
	mRect.h = h;
}

void UIElement::update( Game* game )
{
}

void UIElement::render( SDL_Surface* screen ) const
{
}