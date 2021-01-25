#include "aire.h"

Aire::Aire(string nombre, int escudo, int vida) : Personaje(nombre, escudo, vida) {
	elemento = "Aire";
}

string Aire::obtenerElemento() {
	return elemento;
}

bool Aire::alimentar() {
	return false;
}
