#ifndef DESTROYABLE_H
#define DESTROYABLE_H

class Destroyable 
{
private:
	bool mDestroy;

public:
	Destroyable() : mDestroy( false ) {}
	virtual ~Destroyable() = 0 {};
	
	inline virtual bool destroy() { if(!mDestroy) mDestroy = true; return mDestroy; };
	inline virtual bool toDestroy() { return mDestroy; }
};

#endif