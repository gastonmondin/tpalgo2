#include "tierra.h"
#include <cmath>

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

void Tierra::atacar(Personaje* p, int rango){
	int ataque, golpe;
	if (p->obtenerElemento() == "Aire")
		ataque = 10;
	else
		if (rango <= 2)
			ataque = 30;
		else if (rango <= 4)
			ataque = 20;
		else
			ataque = 10;
	if (p->obtenerElemento() == "Agua")
		ataque += 20;
	golpe = (100 - p->obtenerEscudo() * 10) * ataque / 100;
	p->asignarVida(p->obtenerVida() - golpe);
}

void Tierra::defender() {
	if (escudo > 0)
		escudoAdicional = 8 - escudo;
	else
		escudoAdicional = 2;
	escudo += escudoAdicional;	
	defenderse = true;
}

bool Tierra::obtenerDefenderse(){
	return defenderse;
}

void Tierra::terminarDefenderse(){
	escudo -= escudoAdicional;
	defenderse = false;
}
