#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <memory>
#include <string>
#include <vector>

class Resource;

class ResourceManager 
{
private:
	std::vector<std::shared_ptr<Resource>> mResources;

public:
	ResourceManager();

	std::shared_ptr<Resource> getResource( int handle );
	int loadTexture( std::string filename );
};

#endif