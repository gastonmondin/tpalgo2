#ifndef TIERRA_H
#define TIERRA_H

#include "personaje.h"

class Tierra : public Personaje {
	private:
		string elemento;
		string alimento;
	public:
		Tierra(string, int, int, int);
		string obtenerElemento();
		string obtenerAlimento();
		bool alimentar();
		int atacar(string elemento, int pos_x, int pos_y);
		bool defenderse();
};

#endif
