#include "ResourceManager.h"

#include <algorithm>

#include "SDL/SDL_image.h"

ResourceManager::ResourceManager() :
	mSpriteAnimations()
{
	/* Load from resource manifest. */

	/* NOTE THIS IS JUST TEMPORARY FOR TESTING */
	mSpriteAnimations["enemy"] = std::shared_ptr<SpriteAnimation>( 
		new SpriteAnimation("enemy_anim.png", 32, 32)
	);
}

std::shared_ptr<SpriteAnimation> ResourceManager::getSpriteAnimation( std::string name )
{
	if( mSpriteAnimations.find( name ) == mSpriteAnimations.end() )
		return NULL;

	return mSpriteAnimations[name];
}