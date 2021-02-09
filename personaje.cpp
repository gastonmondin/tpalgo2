#include "personaje.h"

Personaje::Personaje(string n, int e, int v, int en) {
	nombre = n;
	escudo = e;
	vida = v;
	energia = en;
	seleccionado = false;
	posX = -1;
	posY = -1;
	accion_1 = '\0';
	accion_2 = '\0';
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

bool Personaje::obtener_seleccionado(){
	return seleccionado;
}

string Personaje::obtener_accion_1(){
	return accion_1;
}

string Personaje::obtener_accion_2(){
	return accion_2;
}

void Personaje::cambiar_accion_1(string otro){
	accion_1 = otro;
}

void Personaje::cambiar_accion_2(string otro){
	accion_2 = otro;
}

void Personaje::elegido(){
	seleccionado = true;
}

char Personaje::obtenerSimbolo() {
	return simbolo;
}

void Personaje::asignarSimbolo(char s) {
	simbolo = s;
}

void Personaje::recibir_ataque(int golpe){
	if(escudo == 1){
		golpe = golpe * 0.9;
	}else if(escudo == 2){
		golpe = golpe * 0.8;
	}else if(escudo > 2){
		golpe = golpe * 0.2;
	}
	vida -= golpe;
}

void Personaje::recuperar_vida(){
	if(vida < 100)
		vida += 10;
	else
		cout << "La vida se encuentra al 100%" << endl;

	if(vida > 100)
		vida = 100;
}

void Personaje::cambiar_escudo(){
	escudo -= 2;
}
