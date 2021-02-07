#include "agua.h"

Agua::Agua(string nombre, int escudo, int vida, int energia) : Personaje(nombre, escudo, vida, energia) {
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
