#ifndef TIERRA_H
#define TIERRA_H

#include "personaje.h"

class Tierra : public Personaje {
	private:
		string elemento;
		string alimento;
	public:
		Tierra(string, int, int);
		string obtenerElemento();
		string obtenerAlimento();
		bool alimentar();
};

#endif
