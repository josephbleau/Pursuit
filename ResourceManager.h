#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <algorithm>
#include <map>
#include <memory>
#include <string>

#include "SpriteAnimation.h"

class ResourceManager 
{
	std::map<std::string, std::shared_ptr<SpriteAnimation> > mSpriteAnimations;

public:
	ResourceManager();

	std::shared_ptr<SpriteAnimation> getSpriteAnimation( std::string name );
};

#endif