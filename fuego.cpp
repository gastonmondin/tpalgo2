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
	vida += 15;
	if (vida > 100)
		vida = 100;
	return true;
}

int Fuego::atacar(string elemento){
	if(elemento == "Agua")
		return 10;
	else if(elemento == "Aire")
		return 30;
	return 20;
}

bool Fuego::defenderse(){
	if(energia > 10){
		cout << "Energia: " << energia << " --> ";
		energia -= 10;
		cout << energia << '\n';
		cout << nombre << " recupera 10 pts de vida" << endl;
		return true;
	}
	return false;
}
