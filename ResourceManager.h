#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <algorithm>
#include <map>
#include <memory>
#include <string>

#include "SpriteAnimation.h"

class ResourceManager 
{
	std::map< std::string, std::shared_ptr<SpriteAnimation> > mAnimations;

public:
	ResourceManager();
	ResourceManager( std::string atlusFileName );

	std::shared_ptr<SpriteAnimation> getAnimationResource( std::string resourceName );
};

#endif