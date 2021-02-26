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
	vida += 5;
	if (vida > 100)
		vida = 100;
	energia += 10;
	if (energia > 20)
		energia = 20;
	return true;
}

void Fuego::atacar(Personaje* p){
	int ataque, golpe;
	if(p->obtenerElemento() == "Aire")
		ataque = 30;
	else if (p->obtenerElemento() == "Agua")
		ataque = 10;
	else
		ataque = 20;
	golpe = (100 - p->obtenerEscudo() * 10) * ataque / 100;
	p->asignarVida(p->obtenerVida() - golpe);
}
