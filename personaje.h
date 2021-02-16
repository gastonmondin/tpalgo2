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
		string accion_1;
		string accion_2;
		int vida, energia;
	private:
		char simbolo;
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

		/*
		 POS: RETORNA EL ATRIBUTO SELECCIONADO.
		*/
		bool obtener_seleccionado();

		/*
		 POS: CONVIERTE SELECCIONADO IGUAL A TRUE
		*/
		void elegido();

		char obtenerSimbolo();

		void asignarSimbolo(char s);

		string obtener_accion_1();

		string obtener_accion_2();

		void cambiar_accion_1(string otro);

		void cambiar_accion_2(string otro);

		virtual int atacar(string elemento){};

		virtual int atacar(string elemento, int pos_x, int pos_y){};

		virtual bool defenderse(){};

		void cambiar_escudo(int cambio);

		void consumo_energia(int consumo);

		void recuperar_vida();

		void recibir_ataque(int golpe);

		virtual ~Personaje(){};
};

#endif
