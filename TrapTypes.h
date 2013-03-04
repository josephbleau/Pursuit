#ifndef TRAPTYPE_H
#define TRAPTYPE_H

enum TrapType {
	STICKY,		// This trap apples SLOWED_HALF property to any entity that touches it.
	EXPLOSIVE,	// This trap deals damage to any entity that touches it.
};

#endif