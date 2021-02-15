#include "casillero.h"

Casillero::Casillero(){
	personaje = 0;
	aux = 0;
}

char Casillero::obtenerSimbolo() {
	if (personaje != 0)
		return personaje->obtenerSimbolo();
	else
		return simbolo;
}

void Casillero::asignarSimbolo(char s) {
	simbolo = s;
}

Personaje* Casillero::obtenerPersonaje() {
	return personaje;
}

void Casillero::asignarPersonaje(Personaje* p) {
	if (p != 0 && personaje != 0) {
			aux = personaje;
			personaje = p;		
	} else {
		if (aux != 0){
			personaje = aux;
			aux = 0;
		} else
			personaje = p;
	}
}

string Casillero::obtenerTipo(){
	return tipo;
}

int Casillero::obtenerCosto(string elemento){
}

Casillero::~Casillero(){
}
