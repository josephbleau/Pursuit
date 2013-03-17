#ifndef ENTITY_H
#define ENTITY_H

#include <memory>
// #include <initializer_list> <--- cmon msvc!
#include <vector>

#include "SDL/SDL.h"

#include "EntityBehaviorHandler.h"
#include "Destroyable.h"
#include "Renderable.h"

class EntityBehavior;
enum EntityProperty;
class Game;

class Entity : public EntityBehaviorHandler, public Renderable,
	           public Destroyable
{
private:
	SDL_Rect mRect;
	SDL_Color mColor;

	int mTTD;	// Ticks until entity self-destructs
	int mSpeedPerTick;
	bool mSkipFrame;		// True if we're not going to update this frame.

	Game* mParent;			// Is not owned by Entity. 

	/* Properties are simple boolean flags which
	   further describe our entity, see EntityProperties.h
	   for a better description. */
	std::vector<EntityProperty> mProperties; 

protected:
	virtual void executeMisc() = 0;

public:
	Entity( Game* parent, int x, int y, 
		    int w, int h );
	
	virtual ~Entity() = 0 {};
	
	void render( SDL_Surface* screen ) const;

	SDL_Color getColor() const;
	Game* getGame() const;
	const SDL_Rect& getRect() const;
	int getSpeedPerTick() const;

	bool hasProperty( EntityProperty property ) const;
	void giveProperty( EntityProperty property );
	void removeProperty (EntityProperty property );

	void setColor( Uint8 r, Uint8 g, Uint8 b );
	void setSpeedPerTick( int speed );
	void setTTD( int ttd );

	void teleport( int x, int y );

	void update();
};

#endif