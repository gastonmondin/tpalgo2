#ifndef TABLERO_H
#define TABLERO_H

#include<iostream>
#include<cstdlib>

#include "lago.h"
#include "volcan.h"
#include "precipicio.h"
#include "montana.h"
#include "camino.h"
#include "vacio.h"

class Tablero {
	private:
		Casillero casilleros[8][8];
		void agregarPrimeraFila();
		void agregarSegundaFila();
		void agregarTerceraFila();
		void agregarCuartaFila();
		void agregarQuintaFila();
		void agregarSextaFila();
		void agregarSeptimaFila();
		void agregarOctavaFila();
		
	public:
		Tablero();
		virtual ~Tablero();
		void mostrar();
		void aparecerPersonaje(Personaje*, int, int);
		bool casilleroDisponible(int, int);
};

#endif
