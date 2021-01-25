#include "fuego.h"

Fuego::Fuego(string nombre, int escudo, int vida) : Personaje(nombre, escudo, vida) {
	elemento = "Fuego";
	alimento = "Madera";
}

string Fuego::obtenerElemento() {
	return elemento;
}

string Fuego::obtenerAlimento() {
	return alimento;
}

bool Fuego::alimentar() {
	vida += 15;
	if (vida > 100)
		vida = 100;
	return true;
}
