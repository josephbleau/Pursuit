#ifndef DESTROYABLE_H
#define DESTROYABLE_H

class Destroyable 
{
private:
	bool mDestroy;

public:
	Destroyable() : mDestroy( false ) {}
	virtual ~Destroyable() = 0 {};
	
	bool destroy() { if(!mDestroy) mDestroy = true; return mDestroy; };
	bool toDestroy() { return mDestroy; }
};

#endif