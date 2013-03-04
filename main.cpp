#include "Game.h"

int main( int argc, char* argv[] )
{
	Game game;
	
	if( game.init() == false ) 
	{
		return EXIT_FAILURE;
	}

	game.execute();
	
	return EXIT_SUCCESS;
}