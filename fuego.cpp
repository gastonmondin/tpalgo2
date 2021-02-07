#include "fuego.h"

Fuego::Fuego(string nombre, int escudo, int vida, int energia) : Personaje(nombre, escudo, vida, energia) {
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
