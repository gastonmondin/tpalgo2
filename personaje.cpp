#include "personaje.h"

Personaje::Personaje(string n, int e, int v) {
	nombre = n;
	escudo = e;
	vida = v;
	energia = rand() % 20;
	seleccionado = false;
}

Personaje::Personaje(Personaje* p){
	nombre = p->nombre;
	escudo = p->escudo;
	vida = p->vida;
	energia = p->energia;
	seleccionado = p->seleccionado;
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

bool Personaje::obtener_seleccionado(){
	return seleccionado;
}

void Personaje::elegido(){
	seleccionado = true;
}
