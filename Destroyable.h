#ifndef DESTROYABLE_H
#define DESTROYABLE_H

class Destroyable 
{
private:
	bool mDestroy;

public:
	Destroyable() : mDestroy( false ) {}
	virtual ~Destroyable() = 0 {};
	
	virtual bool destroy() { if(!mDestroy) mDestroy = true; return mDestroy; };
	virtual bool toDestroy() { return mDestroy; }
};

#endif