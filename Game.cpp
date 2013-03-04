#include "Game.h"

#include <iostream>

#include "EBStats.h"
#include "Entity.h"
#include "EnemyEntity.h"
#include "EntityProperties.h"
#include "Destroyable.h"
#include "ReticuleEntity.h"
#include "UIElement.h"
#include "UIHealthBar.h"

Game::Game() :
	mScreen( NULL ),
	mEntities(),
	mUIElements(),
	mPlayerEntity( NULL )
{
	mUIElements.push_back( std::shared_ptr<UIElement>( new UIHealthBar( 5, 480, 100, 20) ) );
}

Game::~Game()
{
	if( mScreen != NULL )
	{
		SDL_FreeSurface( mScreen );
	}
}

void Game::drawEntities()
{
		for( auto entity = mEntities.begin();
			 entity != mEntities.end();
			 ++entity )
		{
			(*entity)->render( mScreen );
		}
}

void Game::drawUIElements() 
{
		for( auto element = mUIElements.begin();
			 element != mUIElements.end();
			 ++element )
		{
			(*element)->render( mScreen );
		}
}

void Game::destroyDestroyables() 
{
	/* *NOTE*: In the future we may have to account for deleting more than just
	           entities, as it's not the only type that might inherit from Destroyable.
	*/

	for( auto entity = mEntities.begin();
		 entity != mEntities.end();
		 entity++ )
	{
		if( (*entity)->toDestroy() )
		{
			entity = mEntities.erase( entity );

			/* Note: I put this here because I was getting a 
			   error: 'vector not incrementable.' when I erased
			   the last object. */
			if( entity == mEntities.end() )
				return;
		}
	}
}

void Game::execute()
{
	SDL_Event event;

	Uint32 lastTick = SDL_GetTicks();
	while( 1 )
	{
		/* Entire game-loop is fixed-step at 60Hz */
		if( SDL_GetTicks() - lastTick > 17 )
		{
			while( SDL_PollEvent( &event ) )
			{
				if( event.type == SDL_QUIT )
				{
					return;
				}
			}
			
			SDL_FillRect( mScreen, &mScreenRect, SDL_MapRGB( mScreen->format, 40, 40, 40 ) ); 
			updateEntities();
			updateUIElements();
			drawEntities();
			drawUIElements();
			SDL_Flip( mScreen );

			destroyDestroyables();	// Removes destroyables marked for destruction

			lastTick = SDL_GetTicks();
		} else {
			SDL_Delay( 1 );
		}
	}
}

const SDL_Rect& Game::getWorldRect()
{
	return mScreenRect;
}

std::shared_ptr<Entity> Game::getPlayerEntity()
{
	return mPlayerEntity;
}

const SDL_Rect& Game::getPlayerRect()
{
	return mPlayerEntity->getRect();
}

const std::vector<std::shared_ptr<Entity>> Game::getEntities()
{
	return mEntities;
}

bool Game::init(int w, int h) 
{
	mScreenRect.x = 0;
	mScreenRect.y = 0;
	mScreenRect.w = w;
	mScreenRect.h = h;

	if( SDL_Init( SDL_INIT_VIDEO ) == -1 ) 
	{
		std::cerr << "There was an error initializing SDL: "
			      << SDL_GetError() << std::endl;
		return false;
	}

	SDL_Surface* screen = SDL_SetVideoMode( w, h, 32, SDL_SWSURFACE );
	if( screen == NULL )
	{
		std::cerr << "There was an error creating our video context: " 
			      << SDL_GetError() << std::endl;
		return false;
	}

	this->mScreen = screen;

	SDL_ShowCursor( false );

	initBasicEntities();

	return true;
}

void Game::initBasicEntities()
{
	/* Setup mouse cursor entity. */
	int mouseX = 0;
	int mouseY = 0; 
	SDL_GetMouseState( &mouseX, &mouseY );
	mEntities.push_back( std::shared_ptr<ReticuleEntity>( new ReticuleEntity( this, mouseX, mouseY, 5, 5 ) ) );

	/* TODO: Eventually push these into a level loading mechanism. */
	/* Setup the player entity. */
	mPlayerEntity = std::shared_ptr<Entity>( new Entity( this, 20, 20, 10, 10 ) );
	mPlayerEntity->giveProperty( EntityProperty::PLAYERCONTROLLED );
	mPlayerEntity->giveProperty( EntityProperty::COLLIDABLE );
	mPlayerEntity->giveBehavior( new EBStats() );
	mPlayerEntity->setSpeedPerTick( 3 );
	mEntities.push_back( mPlayerEntity );
	

	/* Setup a test enemy. */
	mEntities.push_back( std::shared_ptr<EnemyEntity>( new EnemyEntity( this, 100, 100, 15, 15 ) ) );
	mEntities.push_back( std::shared_ptr<EnemyEntity>( new EnemyEntity( this, 400, 0, 15, 15 ) ) );
	mEntities.push_back( std::shared_ptr<EnemyEntity>( new EnemyEntity( this, 0, 400, 15, 15 ) ) );
	mEntities.push_back( std::shared_ptr<EnemyEntity>( new EnemyEntity( this, 400, 400, 15, 15 ) ) );
}

void Game::updateEntities()
{
		for( auto entity = mEntities.begin();
			 entity != mEntities.end();
			 ++entity )
		{
			(*entity)->update();
		}
}

void Game::updateUIElements()
{
		for( auto element = mUIElements.begin();
			 element != mUIElements.end();
			 ++element )
		{
			(*element)->update(this);
		}
}