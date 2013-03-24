#include "ProjectileEntity.h"

#include <iostream>

#include "Game.h"

ProjectileEntity::ProjectileEntity( Game* game, int x, int y, int w, int h, float vx, float vy )
	: Entity(game, x, y, w, h)
	, mVelocityX(vx)
	, mVelocityY(vy)
{}

void ProjectileEntity::executeMisc()
{
	const SDL_Rect rect = getRect();
	const SDL_Rect worldRect = getGame()->getWorldRect();

	if(rect.x < worldRect.x || rect.x > worldRect.x + worldRect.w ||
	   rect.y < worldRect.y || rect.y > worldRect.y + worldRect.h )
	{
		destroy();
		return;
	}

	teleport(rect.x + mVelocityX, rect.y + mVelocityY);
}