#ifndef MENU_H
#define MENU_H

#include "lista.h"
#include "ABB_raiz.h"
#include "tablero.h"

using namespace std;

const string ATACAR		= "atacar";
const string DEFENDER	= "defender";
const string ALIMENTAR	= "alimentar";
const string MOVER		= "mover";
const string PASAR		= "pasar";

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

		// POS: MUESTRA UN NUEVO MENU UNA VEZ SELECCIONADO COMENZAR EL JUEGO.
		void mostrar_submenu();

		// POS: ELEGIRA LA OPCION INDICADA DEL SUBMENU.
		void elegir_subopcion(int opcion);

		// VERIFICARA SI EL PERSONAJE SE ENCUENTRA DISPONIBLE PARA SER ELEGIDO, DE ESTAR DISPONIBLE
		// SERA CARGADO A UN EQUIPO DESIGNADO, CASO CONTRARIO SE NOTIFICARA POR PANTALLA.
		void verificar_disponible(Personaje* p);

		// CARGARA EN UN EQUIPO EL PERSONAJE SELECCIONADO.
		void cargar_equipos(Personaje* p);

		// VERIFICA QUE SE INGRESE UN PERSONAJE EN EQUIPO 1 O EQUIPO 2.
		void verificar_equipo(int &equipo);
		
		void seleccionarPosicion();
		
		void autocompletarEquipo();

		/*
		 POS: MUESTRA UN MENU PARA CADA PERSONAJE Y SE ELIGIRA LA ACCION QUE REALIZARA CADA UNO.
		 */
		void elegir_acciones(Dato personaje, int equipo);

		/*
		 POS: DETERMINARA LOS LIMILITES EN LOS ATAQUES DE ALGUNOS PERSONAJES
		 */
		void calcular_rango(int &ini, int &fin, int pos);

		/*
		 RETARDO
		*/
		void delay(float segs);

		/*
		 POS: DENTRO DE UN LIMITES ESTABLECIDOS ATACARA A TODOS LOS ENEMIGOS
		*/

		void ataque_agua(Dato personaje, int equipo);
	 	/*
		POS:REALIZA EL ATAQUE DEL PERSONAJE A LAS COORDENADAS INGRESADAS
		/*

		void ataque_aire(Dato personaje, int equipo);
	 	*/
		//POS:REALIZA EL ATAQUE A TODOS LOS ENEMIGOS DEL TABLERO

		/*



		void radar_fuego(Dato personaje, int equipo);

		/*
		 POS: DETERMINARA EN RADIO DE IMPACTO DE SU ATAQUE
		 */
		bool limites_tierra(int &x_ini, int &x_fin, int &y_ini, int &y_fin);

		/*
		 POS: DENTRO DE UN LIMITES ESTABLECIDOS ATACARA A TODOS LOS ENEMIGOS
		 */
		void radar_tierra(Dato personaje, int equipo);

		/*
		 POS: SE EJECUTARAN LOS ATAQUES DE TODOS LOS PERSONAJES QUE TENGAN ESTA ACCION ACTIVA,
		 */
		void super_ataques(Dato personaje, string elemento, int energia, int equipo);

		/*
		 POS: VERIFICARA LAS ACCIONES DE CADA PERSONAJE Y LA EJECUTARA.
		 */
		void ejecutar_acciones();

		/*
		 POS: SE EJECUTARA EL JUEGO COMPLETO HASTA QUE TODOS LOS PERSONAJES DE UN EQUIPO QUEDEN
		 	 CON VIDA IGUAL A 0.
		 */
		void comenzar_juego();

		/*
		 POS: LIMPIA EL TABLERO DE BATALLA.
		 */
		void limpiar_tablero();

		/*
		 POS: MUESTRA INFORMACION DEL PERSONAJE.
		 */
		void descripcion(Dato personaje);

		/*
		 POS: CALCULARA EL IMPACTO DEPENDIENDO DEL TIPO DE ENEMIGO, LUEGO REALIZARA EL ATAQUE.
		 */
		void atacar_objetivo(Dato emisor, Dato receptor);

		/*
		 POS: REALIZARA LAS DEFENZA ESPECIAL DEL PERSONAJE.
		 */
		void defensas(Dato personaje, string elemento, int equipo);

		/*
		 POS: UBICARA A TODOS LOS PERSONAJES EN SUS POSICIONES ESTABLECIDAS.
		 */
		void autoposicionar();
		
	public:
		Menu();
		
		// POS: Abre el archivo, carga a todos los personajes en una lista
		// y lo cierra.
		void procesarArchivo();
		
		// POS: Muestra el menu de opciones y solicita una opcion al usuario.
		void mostrarMenu();
};

#endif
