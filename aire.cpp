#include "aire.h"

Aire::Aire(string nombre, int escudo, int vida, int energia) : Personaje(nombre, escudo, vida, energia) {
	elemento = "Aire";
}

string Aire::obtenerElemento() {
	return elemento;
}

bool Aire::alimentar() {
	return false;
}
