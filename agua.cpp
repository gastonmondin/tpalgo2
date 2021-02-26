#include "agua.h"

Agua::Agua(string nombre, int escudo, int vida, int energia) : Personaje(nombre, escudo, vida, energia) {
	vecesAlimentado = 0;
	elemento = "Agua";
	alimento = "Plancton";
}

string Agua::obtenerElemento() {
	return elemento;
}

string Agua::obtenerAlimento() {
	return alimento;
}

bool Agua::alimentar() {
	if (vecesAlimentado < 3) {
		energia += 10;
		vecesAlimentado++;
		if (energia > 20)
			energia = 20;
		return true;
	} else{
		return false;
	}
}
void Agua::atacar(Personaje* p){
	int ataque, golpe;
	if(p->obtenerElemento() == "Fuego")
		ataque = 30;
	else if (p->obtenerElemento() == "Tierra")
		ataque = 10;
	else
		ataque = 20;
	golpe = (100 - p->obtenerEscudo() * 10) * ataque / 100;
	p->asignarVida(p->obtenerVida() - golpe);
}
