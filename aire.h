#ifndef AIRE_H
#define AIRE_H

#include "personaje.h"

class Aire : public Personaje {
	private:
		string elemento;
	public:
		Aire(string, int, int, int);
		string obtenerElemento();
		bool alimentar();
		void atacar(Personaje*);
};

#endif
