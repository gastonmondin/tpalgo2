#ifndef TABLERO_H
#define TABLERO_H

#include<iostream>
#include<cstdlib>
#include<unistd.h>

#include "lago.h"
#include "volcan.h"
#include "precipicio.h"
#include "montana.h"
#include "camino.h"
#include "vacio.h"

#define VERTICES 64
#define INFINITO 9999999

class Tablero {
	private:
		Casillero* casilleros[8][8];
		int distancia[64][64];
		int siguiente[64][64];
		void agregarPrimeraFila();
		void agregarSegundaFila();
		void agregarTerceraFila();
		void agregarCuartaFila();
		void agregarQuintaFila();
		void agregarSextaFila();
		void agregarSeptimaFila();
		void agregarOctavaFila();
		void inicializarMatrizDistancias(string);
		void completarDistancias();
		void realizarMovimiento(Personaje*, int, int);
		void limpiarPantalla();
		
	public:
		Tablero();
		virtual ~Tablero();
		void mostrar();
		void aparecerPersonaje(Personaje*, int, int);
		void moverPersonaje(Personaje*, int, int);
		bool casilleroDisponible(int, int);
		Casillero* obtener_casillero(int x, int y);
};

#endif
