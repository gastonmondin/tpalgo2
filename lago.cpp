#include "lago.h"

Lago::Lago() : Casillero(){
	simbolo = 'L';
	tipo = "Lago";
}

int Lago::obtenerCosto(string elemento){
	if (elemento == "Agua")
		return 0;
	else if (elemento == "Fuego")
		return 2;
	else
		return 1;
}
