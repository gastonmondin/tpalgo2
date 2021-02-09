#ifndef FUEGO_H
#define FUEGO_H

#include "personaje.h"

class Fuego : public Personaje {
	private:
		string elemento;
		string alimento;
	public:
		Fuego(string, int, int, int);
		string obtenerElemento();
		string obtenerAlimento();
		bool alimentar();
		int atacar(string elemento);
		bool defenderse();
};

#endif
