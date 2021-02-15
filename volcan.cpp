#include "volcan.h"

Volcan::Volcan() : Casillero(){
	simbolo = 'V';
	tipo = "Volcan";
}

int Volcan::obtenerCosto(string elemento) {
	if (elemento == "Fuego")
		return 0;
	else if (elemento == "Agua")
		return 2;
	else
		return 1;
}
