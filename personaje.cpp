#include "personaje.h"

Personaje::Personaje(string n, int e, int v) {
	nombre = n;
	escudo = e;
	vida = v;
	energia = rand() % 20;
}

string Personaje::obtenerElemento() {
}

string Personaje::obtenerAlimento() {
}

string Personaje::obtenerNombre() {
	return nombre;
}

int Personaje::obtenerEscudo() {
	return escudo;
}

int Personaje::obtenerVida() {
	return vida;
}

int Personaje::obtenerEnergia() {
	return energia;
}

bool Personaje::alimentar() {
}
