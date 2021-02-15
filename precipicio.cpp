#include "precipicio.h"

Precipicio::Precipicio() : Casillero(){
	simbolo = 'P';
	tipo = "Precipicio";
}

int Precipicio::obtenerCosto(string elemento) {
	if (elemento == "Aire")
		return 0;
	else if (elemento == "Tierra")
		return 2;
	else
		return 1;
}
