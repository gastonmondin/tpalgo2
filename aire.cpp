#include "aire.h"

Aire::Aire(string nombre, int escudo, int vida, int energia) : Personaje(nombre, escudo, vida, energia) {
	elemento = "Aire";
}

string Aire::obtenerElemento() {
	return elemento;
}

bool Aire::alimentar() {
	return false;
}

void Aire::atacar(Personaje* p){
	int ataque, golpe;
	if(p->obtenerElemento() == "Tierra")
		ataque = 20;
	else if (p->obtenerElemento() == "Fuego")
		ataque = 10;
	else
		ataque = 15;
	golpe = (100 - p->obtenerEscudo() * 10) * ataque / 100;
	p->asignarVida(p->obtenerVida() - golpe);
}
