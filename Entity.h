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

	Game* mParent;		// Is not owned by Entity. 

	/* Properties are simple boolean flags which
	   further describe our entity, see EntityProperties.h
	   for a better description. */
	std::vector<EntityProperty> mProperties; 

protected:
	virtual void executeMisc();

public:
	Entity( Game* parent, int x, int y, 
		    int w, int h );
	
	~Entity();
	
	void render( SDL_Surface* screen ) const;

	Game* getGame() const;
	const SDL_Rect& getRect() const;

	bool hasProperty( EntityProperty property ) const;
	void giveProperty( EntityProperty property );
	void removeProperty (EntityProperty property );

	void setColor( Uint8 r, Uint8 g, Uint8 b );
	void setSpeedPerTick( int speed );

	void teleport( int x, int y );

	template <typename T>
	void triggerBehaviorEvent( std::string eventName,  std::vector<int> arguments )
	{
		if( hasBehavior<T>() )
		{
			getBehaviorByClass<T>()->triggerEvent( eventName, arguments );
		}
	}

	void update();
};

#endif