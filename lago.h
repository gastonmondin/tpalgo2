#ifndef LAGO_H
#define LAGO_H

#include "casillero.h"

class Lago : public Casillero {
	public:
		Lago();
		int obtenerCosto(string);
};

#endif
