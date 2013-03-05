#ifndef RETICULEENTITY_H
#define RETICULEENTITY_H

#include "Entity.h"

class ReticuleEntity : public Entity
{
public:
	ReticuleEntity( Game* parent, int x, int y, 
		            int w, int h );

	void executeMisc(); 	// Override
};

#endif