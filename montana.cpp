#include "montana.h"

Montana::Montana() : Casillero(){
	simbolo = 'M';
	tipo = "Montana";
}

int Montana::obtenerCosto(string elemento) {
	if (elemento == "Tierra")
		return 0;
	else if (elemento == "Aire")
		return 2;
	else
		return 1;
}
