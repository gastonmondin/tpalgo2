#ifndef AGUA_H
#define AGUA_H

#include "personaje.h"

class Agua : public Personaje {
	private:
		string elemento;
		string alimento;
		int vecesAlimentado;
	public:
		Agua(string, int, int);
		Agua(Personaje *p);
		string obtenerElemento();
		string obtenerAlimento();
		bool alimentar();
};

#endif
