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

int Aire::atacar(string elemento){
	if(elemento == "Fuego")
		return 10;
	else if (elemento == "Tierra")
		return 20;
	else
		return 15;
}
bool Aire::defenderse(){
	if(energia > 15){
		cout << "Energia: " << energia << " --> ";
		energia -= 15;
		cout << energia << "\n" << nombre << " se puede desplazar sin consumir energia" << endl;

		return true;
	}
	return false;
}
