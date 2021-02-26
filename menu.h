#ifndef MENU_H
#define MENU_H

#include "lista.h"
#include "ABB_raiz.h"
#include "tablero.h"

using namespace std;

class Menu {
	// Atributos
	
	private:
		Lista listaPersonajes = Lista();
		Abb_raiz arbol = Abb_raiz();
		Lista equipos[2];
		Tablero tablero = Tablero();

	// Metodos

		// POS: Separa una linea del archivo en datos y los manda a crear personaje.
		void procesarLinea(string);

		// POS: Recibe los datos del personaje y lo crea y agrega a la lista.
		void crearPersonaje(string, string, int, int);
		
		// POS: Ejecuta la opcion del menu ingresada por el usuario.
		void elegirOpcionMenu(int);
		
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
		
		void verificarEscudo(Personaje*);
		
		void recuperarEnergia(Personaje*);
		
		void verificarEnergia(Personaje*);
		
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

		// POS: MUESTRA UN NUEVO MENU UNA VEZ SELECCIONADO COMENZAR EL JUEGO.
		void mostrarSubmenu();

		// POS: ELEGIRA LA OPCION INDICADA DEL SUBMENU.
		void elegirOpcionSubmenu(int opcion);

		/*
		 *VERIFICARA SI EL PERSONAJE SE ENCUENTRA DISPONIBLE PARA SER ELEGIDO, DE ESTAR DISPONIBLE
		 SERA CARGADO A UN EQUIPO DESIGNADO, CASO CONTRARIO SE NOTIFICARA POR PANTALLA.
		*/
		void verificarDisponible(Personaje* p);

		Personaje* elegido(string elemento, string nombre, int escudo, int vida, int energia);

		// CARGARA EN UN EQUIPO EL PERSONAJE SELECCIONADO.
		void cargarEquipos(Personaje* p);

		// VERIFICA QUE SE INGRESE UN PERSONAJE EN EQUIPO 1 O EQUIPO 2.
		void verificarEquipo(int &equipo);
		
		void seleccionarPosicion();

		/*
		 POS: MUESTRA INFORMACION DEL PERSONAJE.
		 */
		void mostrarDescripcion(Personaje*);
		
		void guardar(ofstream &archivo, Dato personaje);

		void guardarDatos(int grupo);

		bool reanudarPartida();

		void retomarDatos(ifstream &archivo);
		
		void comenzarJuego();
		
		int elegirFila();
		
		int elegirColumna();
		
		int elegirOpcion(Personaje*, int);
		
		bool ejecutarPrimeraOpcion(int, Personaje*);

		bool ejecutarSegundaOpcion(int, Personaje*);
		
		void ataquePersonaje(Personaje*);
		
		void realizarAtaque(Personaje*, Personaje*, int);
		
		void verificarEstado(Personaje*);
		
		void ataqueAgua(Personaje*);
		
		void ataqueAire(Personaje*);
		
		void ataqueFuego(Personaje*);
		
		void animacionFuego(int, int);
		
		int limiteSuperior(int);
		
		int limiteInferior(int);
		
		void ataqueTierra(Personaje*);
		
		void animacionTierra(int, int, int);
		
		void refrescarTablero();
		
		void defensaPersonaje(Personaje*);
		
		void defensaAgua(Personaje*);
		
		void defensaAire(Personaje*);
		
		void defensaFuego(Personaje*);
		
		void defensaTierra(Personaje*);
		
		bool gameOver();
		
		bool partidaGuardada();
	public:
		Menu();
		
		// POS: Abre el archivo, carga a todos los personajes en una lista
		// y lo cierra.
		void procesarArchivo();
		
		// POS: Muestra el menu de opciones y solicita una opcion al usuario.
		void mostrarMenu();
};

#endif
