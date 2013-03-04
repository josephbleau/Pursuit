#ifndef GAME_H
#define GAME_H

#include <vector>
#include <memory>
#include "SDL/SDL.h"

class Entity;
class Destroyable;
class UIElement;

class Game
{
private:
	SDL_Surface* mScreen;			// Our actual SDL drawing context.
	SDL_Rect mScreenRect;			// A rect representing the screen size.

	std::vector<std::shared_ptr<Entity>> mEntities;	
	std::vector<std::shared_ptr<Entity>> mIncomingEntities;	// Entities we're adding to the scene, but not until the frame is over.
	std::shared_ptr<Entity> mPlayerEntity;
	std::vector<std::shared_ptr<UIElement>> mUIElements;

	void destroyDestroyables(); // Called once per frame to cleanup destroyed entities.

public:
	Game();
	~Game();

	void drawEntities();
	void drawUIElements();
	void execute();
	const SDL_Rect& getWorldRect();
	std::shared_ptr<Entity> getPlayerEntity();
	const SDL_Rect& getPlayerRect();
	void giveEntity( Entity* entity );
	const std::vector<std::shared_ptr<Entity>> getEntities();
	bool init( int w = 512, int h = 512 );
	void initBasicEntities();
	void updateEntities();
	void updateUIElements();
	void updateMouseCursor();
};

#endif