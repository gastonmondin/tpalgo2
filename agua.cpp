#include "agua.h"

Agua::Agua(string nombre, int escudo, int vida) : Personaje(nombre, escudo, vida) {
	vecesAlimentado = 0;
	elemento = "Agua";
	alimento = "Plancton";
}

string Agua::obtenerElemento() {
	return elemento;
}

string Agua::obtenerAlimento() {
	return alimento;
}

bool Agua::alimentar() {
	if (vecesAlimentado < 3) {
		energia += 10;
		vecesAlimentado++;
		if (energia > 20)
			energia = 20;
		return true;
	} else{
		return false;
	}
}
