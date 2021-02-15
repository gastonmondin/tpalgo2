#ifndef MONTANA_H
#define MONTANA_H

#include "casillero.h"

class Montana : public Casillero {
	public:
		Montana();
		int obtenerCosto(string);
};

#endif
