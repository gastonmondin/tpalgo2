#include "personaje.h"

Personaje::Personaje(string n, int e, int v, int en) {
	nombre = n;
	escudo = e;
	vida = v;
	energia = en;
	seleccionado = false;
	posX = 0;
	posY = 0;
	atacado = false;
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

void Personaje::asignarVida(int v) {
	if (v > 100)
		v = 100;
	else if (v < 0)
		v = 0;
	vida = v;
}

void Personaje::asignarEnergia(int en){
	if (en > 20)
		en = 20;
	energia = en;
}

int Personaje::obtenerPosX() {
	return posX;
}

int Personaje::obtenerPosY() {
	return posY;
}

void Personaje::asignarPos(int x, int y) {
	posX = x;
	posY = y;
}

bool Personaje::obtenerSeleccionado(){
	return seleccionado;
}

void Personaje::asignarSeleccionado(){
	seleccionado = true;
}

char Personaje::obtenerSimbolo() {
	return simbolo;
}

void Personaje::asignarSimbolo(char s) {
	simbolo = s;
}

bool Personaje::obtenerAtacado() {
	return atacado;
}

void Personaje::asignarAtacado(bool a) {
	atacado = a;
}
