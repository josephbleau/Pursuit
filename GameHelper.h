#ifndef GAMEHELPER_H
#define GAMEHELPER_H

#include <vector>
#include <varargs.h>

/* Random shit: if it's not object specific, and would make sense 
   inlined, but will be used in more than one place, it probably goes
   here. */

namespace GameHelper
{

__forceinline bool rectsCollide( const SDL_Rect& r1, const SDL_Rect& r2 ) 
{
	bool outside =  (r1.x + r1.w < r2.x) ||	// Test if we're outside to the west
	                (r1.x > r2.x + r2.w) ||	// Test if we're outside to the east
	                (r1.y + r1.h < r2.y) ||	// Test if we're outsode to the north
		            (r1.y > r2.y + r2.h);	// Test if we're outside to the south;

	return !outside; // If we're not outside, we're collidin'.		   
}

};
#endif