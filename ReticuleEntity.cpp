#include "ReticuleEntity.h"

#include "SDL/SDL.h"
#include <iostream>
ReticuleEntity::ReticuleEntity( Game* parent, int x, 
							    int y, int w, int h ) :
	Entity( parent, x, y, w, h )
{
}

void ReticuleEntity::executeMisc()
{
	int mouseX = 0;
	int mouseY = 0;
	SDL_GetMouseState( &mouseX, &mouseY );
	teleport( mouseX, mouseY );
}