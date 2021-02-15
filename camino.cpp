#include "camino.h"

Camino::Camino() : Casillero(){
	simbolo = 'C';
	tipo = "Camino";
}

int Camino::obtenerCosto(string elemento) {
	return 1;
}
