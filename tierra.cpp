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

int Tierra::atacar(string elemento, int pos_x, int pos_y){
	int dist_x = abs(posX - pos_x);
	int dist_y = abs(posY - pos_y);
	int golpe;

	if(elemento == "Aire")
		return 10;

	if(dist_x <= 2 && dist_y <= 2)
		golpe = 30;
	else if(dist_x <= 4 && dist_y <= 4)
		golpe = 20;
	else
		golpe = 10;

	if(elemento == "Agua")
		return (golpe + 20);

	return golpe;
}

bool Tierra::defenderse(){
	if(energia > 5){
		cout << "Energia: " << energia << " --> ";
		energia -= 5;
		cout << energia << '\n';
		escudo += 2;
		cout << nombre << " gana +2pts de escudo por un turno" << endl;
		return true;
	}
	return false;
}
