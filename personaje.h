#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Personaje {
	// Atributos
	
	private:
		string nombre;
		int escudo, posX, posY;
		bool seleccionado;
		char simbolo;
	protected:
		int vida, energia;
	public:
	
	// Metodos
	
	
		
		// Constructor
		// POS: Crea un personaje y le asigna sus atributos.
		Personaje(string, int, int, int);
		
		//Personaje(Personaje* p);

		virtual string obtenerElemento();
		
		// POS: Alimenta al personaje o no, dependiendo de si
		// se dan las condiciones.
		virtual bool alimentar();

		virtual string obtenerAlimento();
		
		string obtenerNombre();
		
		int obtenerEscudo();
		
		int obtenerVida();
		
		int obtenerEnergia();
		
		int obtenerPosX();
		
		int obtenerPosY();
		
		void asignarPos(int, int);
		
		char obtenerSimbolo();
		
		void asignarSimbolo(char);

		/*
		 POS: RETORNA EL ATRIBUTO SELECCIONADO.
		*/
		bool obtener_seleccionado();

		/*
		 POS: CONVIERTE SELECCIONADO IGUAL A TRUE
		*/
		void elegido();

		virtual ~Personaje();
};

#endif
