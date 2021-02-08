#include "personaje.h"

Personaje::Personaje(string n, int e, int v, int en) {
	nombre = n;
	escudo = e;
	vida = v;
	energia = en;
	seleccionado = false;
}

/*Personaje::Personaje(Personaje* p){
	nombre = p->nombre;
	escudo = p->escudo;
	vida = p->vida;
	energia = p->energia;
	seleccionado = p->seleccionado;
}*/

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

char Personaje::obtenerSimbolo() {
	return simbolo;
}

void Personaje::asignarSimbolo(char s) {
	simbolo = s;
}

bool Personaje::obtener_seleccionado(){
	return seleccionado;
}

void Personaje::elegido(){
	seleccionado = true;
}

Personaje::~Personaje(){
	
}
