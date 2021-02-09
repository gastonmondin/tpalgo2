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

int Agua::atacar(string elemento){
	return 0;
}

bool Agua::defenderse(){
	if(energia > 12){
		cout << "Energia: " << energia << " --> ";
		energia -= 12;
		cout << energia << '\n';
		cout << nombre << " recupera 50 pts de vida. Sus aliados recuperan 10 pts de vida" << endl;
		vida += 40;
		return true;
	}
	return false;
}
