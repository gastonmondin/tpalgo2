#ifndef TABLERO_H
#define TABLERO_H

#include<iostream>
#include<cstdlib>

class Tablero {
	private:
		char dimensiones[8][8];
		void agregarLago();
		void agregarVolcan();
		void agregarPrecipicio();
		void agregarMontana();
		void agregarCamino();
		void agregarVacio();
		
	public:
		Tablero();
		virtual ~Tablero();
		void mostrar();
};

#endif
