#ifndef CASILLERO_H
#define CASILLERO_H

#include <string>

#include "personaje.h"

using namespace std;

class Casillero {
	protected:
		char simbolo;
		string tipo;
		Personaje* personaje;
		Personaje* aux;
		bool ataqueFuego;
		bool ataqueTierra;
	public:
		Casillero();
		char obtenerSimbolo();
		void asignarSimbolo(char);
		Personaje* obtenerPersonaje();
		void asignarPersonaje(Personaje*);
		string obtenerTipo();
		virtual int obtenerCosto(string);
		void asignarAtaqueFuego(bool);
		void asignarAtaqueTierra(bool);
		virtual ~Casillero();
};

#endif
