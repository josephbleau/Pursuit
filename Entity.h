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

	virtual Game* getGame() const;
	virtual const SDL_Rect& getRect() const;
	virtual int getSpeedPerTick() const;

	virtual bool hasProperty( EntityProperty property ) const;
	virtual void giveProperty( EntityProperty property );
	virtual void removeProperty (EntityProperty property );

	virtual void setColor( Uint8 r, Uint8 g, Uint8 b );
	virtual void setSpeedPerTick( int speed );

	virtual void teleport( int x, int y );

	void update();
};

#endif