#include "vacio.h"

Vacio::Vacio() : Casillero(){
	simbolo = ' ';
	tipo = "Vacio";
}

int Vacio::obtenerCosto(string elemento) {
	return 15;
}
