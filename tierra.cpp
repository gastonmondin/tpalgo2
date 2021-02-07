#include "tierra.h"

Tierra::Tierra(string nombre, int escudo, int vida, int energia) : Personaje(nombre, escudo, vida, energia) {
	elemento = "Tierra";
	alimento = "Hierbas";
}

string Tierra::obtenerElemento() {
	return elemento;
}

string Tierra::obtenerAlimento() {
	return alimento;
}

bool Tierra::alimentar() {
	energia += 8;
	if (energia > 20)
		energia = 20;
	return true;
}
