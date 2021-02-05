#ifndef AIRE_H
#define AIRE_H

#include "personaje.h"

class Aire : public Personaje {
	private:
		string elemento;
	public:
		Aire(string, int, int);
		Aire(Personaje *p);
		string obtenerElemento();
		bool alimentar();
};

#endif
