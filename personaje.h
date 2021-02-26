#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Personaje {
	// Atributos
	
	protected:
		string nombre;
		int escudo, posX, posY;
		bool seleccionado;
		int vida, energia;
		bool atacado;
	private:
		char simbolo;
	public:
	
	// Metodos

		// Constructor
		// POS: Crea un personaje y le asigna sus atributos.
		Personaje(string, int, int, int);
		
		//Personaje(Personaje* p);

		virtual string obtenerElemento(){};
		
		// POS: Alimenta al personaje o no, dependiendo de si
		// se dan las condiciones.
		virtual bool alimentar(){};

		virtual string obtenerAlimento(){};
		
		string obtenerNombre();
		
		int obtenerEscudo();
		
		int obtenerVida();
		
		int obtenerEnergia();
		
		int obtenerPosX();
		
		int obtenerPosY();
		
		void asignarVida(int);
		
		void asignarEnergia(int);
		
		void asignarPos(int, int);

		/*
		 POS: RETORNA EL ATRIBUTO SELECCIONADO.
		*/
		bool obtenerSeleccionado();

		/*
		 POS: CONVIERTE SELECCIONADO IGUAL A TRUE
		*/
		void asignarSeleccionado();

		char obtenerSimbolo();

		void asignarSimbolo(char s);
		
		bool obtenerAtacado();
		
		void asignarAtacado(bool);
		
		virtual void atacar(Personaje*){};
		
		virtual void atacar(Personaje*, int){};

		virtual bool defenderse(){};
		
		virtual void defender(){};
		
		virtual bool obtenerDefenderse(){};
		
		virtual void terminarDefenderse(){};

		virtual ~Personaje(){};
};

#endif
