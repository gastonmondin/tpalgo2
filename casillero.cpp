#include "casillero.h"

Casillero::Casillero(){
	personaje = 0;
}

char Casillero::obtenerSimbolo() {
	return simbolo;
}

void Casillero::asignarSimbolo(char s) {
	simbolo = s;
}

Personaje* Casillero::obtenerPersonaje() {
	return personaje;
}

void Casillero::asignarPersonaje(Personaje* p) {
	personaje = p;
}

string Casillero::obtenerTipo(){
	return tipo;
}

Casillero::~Casillero(){
}
