#ifndef MENU_H
#define MENU_H

#include "lista.h"

using namespace std;

class Menu {
	// Atributos
	
	private:
		Lista listaPersonajes = Lista();

	// Metodos

		// POS: Separa una linea del archivo en datos y los manda a crear personaje.
		void procesarLinea(string);

		// POS: Recibe los datos del personaje y lo crea y agrega a la lista.
		void crearPersonaje(string, string, int, int);
		
		// POS: Ejecuta la opcion del menu ingresada por el usuario.
		void elegirOpcion(int);
		
		// POS: Pide los datos del personaje y luego llama a crear personaje.
		void nuevoPersonaje();
		
		// POS: Elimina al personaje si existe.
		void eliminarPersonaje(Personaje*);
		
		// POS: Muestra la lista con todos los nombres de los personajes.
		void mostrarPersonajes();
		
		// POS: Muestra todos los detalles del personaje si existe.
		void mostrarDetalles(Personaje*);
		
		// POS: Alimenta al personaje si existe y cumple las condiciones,
		// y si no puede muestra por pantalla por que.
		void alimentarPersonaje(Personaje*);
		
		// PRE: El nombre del personaje existe.
		// POS: Devuelve el objeto del personaje si lo encuentra,
		// si no informa por pantalla.
		Personaje* buscarPersonaje(string);
		
		string ingresarElemento();
		
		string ingresarNombre();
		
		// POS: Devuelve una cadena de caracteres con la primer letra en
		// mayuscula y todas las demas en minuscula.
		string capitalizar(string);
		
		void limpiarPantalla();

	public:
		Menu();
		
		// POS: Abre el archivo, carga a todos los personajes en una lista
		// y lo cierra.
		void procesarArchivo();
		
		// POS: Muestra el menu de opciones y solicita una opcion al usuario.
		void mostrarMenu();		
};

#endif