#include "menu.h"
#include <fstream>

Menu::Menu() {
}

void Menu::verificar_equipo(int &equipo){
	while(equipo != 1 && equipo != 2){
		cout << "Error. Reingrese: ";
		cin >> equipo; cout << endl;
	}
}

void Menu::crearPersonaje(string elemento, string nombre, int escudo, int vida) {
	if (elemento == "Fuego") {
		Personaje* nuevoPersonaje = new Fuego(nombre, escudo, vida, rand() % 20);
		listaPersonajes.alta(nuevoPersonaje, listaPersonajes.obtenerCantidad()+1);
		arbol.alta(nombre, nuevoPersonaje);
	}else if (elemento == "Agua") {
		Personaje* nuevoPersonaje = new Agua(nombre, escudo, vida, rand() % 20);
		listaPersonajes.alta(nuevoPersonaje, listaPersonajes.obtenerCantidad()+1);
		arbol.alta(nombre, nuevoPersonaje);
	}else if (elemento == "Tierra") {
		Personaje* nuevoPersonaje = new Tierra(nombre, escudo, vida, rand() % 20);
		listaPersonajes.alta(nuevoPersonaje, listaPersonajes.obtenerCantidad()+1);
		arbol.alta(nombre, nuevoPersonaje);
	}else if (elemento == "Aire") {
		Personaje* nuevoPersonaje = new Aire(nombre, escudo, vida, rand() % 20);
		listaPersonajes.alta(nuevoPersonaje, listaPersonajes.obtenerCantidad()+1);
		arbol.alta(nombre, nuevoPersonaje);
	}else
		cout << "El elemento " << elemento << " no existe, el personaje no se creo." << endl;
}

void Menu::procesarLinea(string linea) {
	string nombre = "", elemento = "";
	int cont = 0, escudo = 0, vida = 0;
	for (int i = 0; i < linea.size(); i++) {
		if (linea[i] == ',')
			cont++;
		else {
			switch(cont) {
				case 0: elemento += linea[i];
					break;
				case 1: nombre += linea[i];
					break;
				case 2: escudo= escudo * 10 + (linea[i] - 48);
					break;
				case 3: vida = vida * 10 + (linea[i] - 48);
			}
		}
	}
	crearPersonaje(elemento, nombre, escudo, vida);
}

void Menu::procesarArchivo() {
	ifstream personajes;
	string linea, elemento, cant, datos[4];
	personajes.open("personajes.csv");
	getline(personajes,cant);
	for(int i = 0; i < stoi(cant); i++) {
		getline(personajes, linea);
		procesarLinea(linea);
	}
	personajes.close();
}

Personaje* Menu::buscarPersonaje(string nombre) {
	return arbol.buscar(nombre);

	/*int pos = listaPersonajes.obtenerPosicion(nombre);
	if (pos != 0)
		return listaPersonajes.consulta(pos);
	else
		cout << "No se encontro el personaje." << endl;
		return 0;*/
}

string Menu::ingresarNombre() {
	string nombre;
	cout << "Ingrese nombre del personaje: ";
	cin >> nombre;
	nombre = capitalizar(nombre);
	return nombre;
}

string Menu::ingresarElemento() {
	string elemento;
	cout << "Ingrese elemento del personaje: ";
	cin >> elemento;
	elemento = capitalizar(elemento);
	return elemento;
}

string Menu::capitalizar(string cadena) {
	for (int i = 0; i < cadena.size(); i++) {
		if ((i == 0) && (cadena[i] >= 'a') && (cadena[i] <= 'z'))
			cadena[i] -= 32;
		else if ((i != 0) && (cadena[i] >= 'A') && ((cadena[i]) <= 'Z'))
			cadena[i] += 32;
	}
	return cadena;
}

void Menu::nuevoPersonaje() {
	string elemento, nombre;
	int escudo, vida;
	elemento = ingresarElemento();
	nombre = ingresarNombre();
	escudo = rand() % 3;
	vida = rand() % 90 + 10;
	crearPersonaje(elemento, nombre, escudo, vida);
}

void Menu::eliminarPersonaje(Personaje* personaje) {
	int pos;
	cout << personaje->obtenerNombre() << " fue eliminado con exito." << endl;
	pos = listaPersonajes.obtenerPosicion(personaje->obtenerNombre());
	listaPersonajes.baja(pos);
}

void Menu::mostrarPersonajes() {
	/*cout << "Lista de personajes:" << endl;

	arbol.mostrar_datos();
	cout << endl << endl;*/
	cout << "Lista de personajes:" << endl;

	for (int i = 1; i <= listaPersonajes.obtenerCantidad(); i++){
		cout << listaPersonajes.consulta(i)->obtenerNombre() << "\t";

		if(!listaPersonajes.consulta(i)->obtener_seleccionado()){
			cout << "(Disponible)"<< endl;
		}else
			cout << "(No Disponible)"<< endl;
	}
}

void Menu::mostrarDetalles(Personaje* personaje) {
	cout << "Elemento: " << personaje->obtenerElemento() << endl;
		cout << "Escudo: " << personaje->obtenerEscudo() << endl;
		cout << "Vida: " << personaje->obtenerVida() << endl;
		cout << "Energia: " << personaje->obtenerEnergia() << endl;	
}

void Menu::alimentarPersonaje(Personaje* personaje) {
	int energiaAnterior, vidaAnterior;
	energiaAnterior = personaje->obtenerEnergia();
	vidaAnterior = personaje->obtenerVida();
	if (personaje->alimentar()) {
		cout << personaje->obtenerNombre() << " fue alimentado con " << personaje->obtenerAlimento() << " y recupero ";
		if (personaje->obtenerElemento() == "Fuego")
			cout << (personaje->obtenerVida() - vidaAnterior) << " de vida." << endl;
		else
			cout << (personaje->obtenerEnergia() - energiaAnterior) << " de energia." << endl;
	} else {
		cout << personaje->obtenerNombre() << " no fue alimentado porque ";
		if (personaje->obtenerElemento() == "Aire")
			cout << "es un personaje de aire." << endl;
		else
			cout << "ya fue alimentado 3 veces." << endl;
	}
}

void Menu::cargar_equipos(Personaje* p){
	Personaje* nuevo;
	if (p->obtenerElemento() == "Fuego") {
		nuevo = new Fuego(p->obtenerNombre(), p->obtenerEscudo(), p->obtenerVida(), p->obtenerEnergia());
	}else if (p->obtenerElemento() == "Agua") {
		nuevo = new Agua(p->obtenerNombre(), p->obtenerEscudo(), p->obtenerVida(), p->obtenerEnergia());
	}else if (p->obtenerElemento() == "Tierra") {
		nuevo = new Tierra(p->obtenerNombre(), p->obtenerEscudo(), p->obtenerVida(), p->obtenerEnergia());
	}else if (p->obtenerElemento() == "Aire")
		nuevo = new Aire(p->obtenerNombre(), p->obtenerEscudo(), p->obtenerVida(), p->obtenerEnergia());

	int equipo;

	cout << "Seleccione su equipo: ";
	cin >> equipo; cout << endl;
	verificar_equipo(equipo);

	if(equipo == 1 && equipos[0].obtenerCantidad() < 3)
		equipos[0].alta(nuevo, equipos[0].obtenerCantidad() + 1);
	else if(equipo == 2 && equipos[1].obtenerCantidad() < 3)
		equipos[1].alta(nuevo, equipos[1].obtenerCantidad() + 1);
	else
		cout << "Equipo completo." << endl;
}

void Menu::verificar_disponible(Personaje* p){
	if(!p->obtener_seleccionado()){
		p->elegido();
		cargar_equipos(p);
	}else
		cout << "Personaje no disponible." << "\n\n";
}

void Menu::elegir_subopcion(int opcion){
	Personaje* personaje;
	switch (opcion) {
		case 1: personaje = buscarPersonaje(ingresarNombre());
			if (personaje !=0) mostrarDetalles(personaje);
			break;
		case 2: mostrarPersonajes();
			break;
		case 3:	personaje = buscarPersonaje(ingresarNombre());
			if (personaje !=0){
				verificar_disponible(personaje);
			}
			break;
		case 4: break;

		default: cout << "Debe elegir un valor entre 1 y 4, intente de nuevo." << endl;
	}
}

void Menu::seleccionarPosicion(){
	int x, y, cont = 2;
	int turno = rand() % 2 + 1;
	Personaje* seleccionado;
	limpiarPantalla();
	tablero.mostrar();
	do {
		seleccionado = equipos[turno-1].consulta(cont/2);
		cout << "Turno del jugador " << turno <<  "." << endl;
		cout << "Elija la posicion en X de " << seleccionado->obtenerNombre() << ": ";
		cin >> x;
		cout << "Elija la posicion en Y de " << seleccionado->obtenerNombre() << ": ";
		cin >> y;
		if (tablero.casilleroDisponible(x, y)){
			seleccionado->asignarPos(x, y);
			tablero.aparecerPersonaje(seleccionado, turno + '0', seleccionado->obtenerPosX(), seleccionado->obtenerPosY());
			if (turno == 1) turno++; else turno--;	
			cont++;
			limpiarPantalla();
			tablero.mostrar();
		} else{
			limpiarPantalla();
			tablero.mostrar();
			cout << "El casillero elegido no esta disponible." << endl;
		}		
	} while (cont < 8);
}

void Menu::mostrar_submenu(){
	int opcion;
	bool completo = false;
	do {
		if(equipos[0].obtenerCantidad() == 3 && equipos[1].obtenerCantidad() == 3){
			completo = true;
			cout << "Equipos completos. Comenzando la partida." << endl;
		}else{
			cout << "----ELEGIR PERSONAJES----" << endl;
			cout << "1. Buscar por nombre los detalles de un personaje en particular." << endl;
			cout << "2. Mostrar todos los nombres de los personajes." << endl;
			cout << "3. Seleccionar personaje." << endl;
			cout << "4. Salir." << endl;
			cout << "Elija una opcion: ";
			cin >> opcion;
			elegir_subopcion(opcion);
		}
	} while (opcion != 4 && !completo);
	

	if(completo){

		//aca se empieza a jugar

		/*imprimo lista de equipos para corroborar*/
		cout << "equipo 1:" << endl;
		for (int i = 1; i <= equipos[0].obtenerCantidad(); i++)
			cout << equipos[0].consulta(i)->obtenerNombre() << endl;
		cout << "equipo 2:" << endl;
		for (int i = 1; i <= equipos[1].obtenerCantidad(); i++)
			cout << equipos[1].consulta(i)->obtenerNombre() << endl;
	}
}

void Menu::elegirOpcion(int opcion) {
	Personaje* personaje;
	limpiarPantalla();
	switch (opcion) {
		case 1: nuevoPersonaje();
			break;
		case 2: personaje = buscarPersonaje(ingresarNombre());
			if (personaje !=0) eliminarPersonaje(personaje);
			break;
		case 3: mostrarPersonajes();
			break;
		case 4: personaje = buscarPersonaje(ingresarNombre());
			if (personaje !=0) mostrarDetalles(personaje);
			break;
		case 5: mostrar_submenu();
			break;
		case 6: break;
		default: cout << "Debe elegir un valor entre 1 y 6, intente de nuevo." << endl;
	}
}

void Menu::limpiarPantalla() {
	#ifdef _WIN32
		system("cls");
	#else
		system ("clear");
	#endif
}

void Menu::autocompletarEquipo(){
	Personaje* p;
	Personaje* nuevo;
	for (int i = 0; i < 6; i++){
		p = listaPersonajes.consulta(i+1);
		if (p->obtenerElemento() == "Fuego") {
			nuevo = new Fuego(p->obtenerNombre(), p->obtenerEscudo(), p->obtenerVida(), p->obtenerEnergia());
		}else if (p->obtenerElemento() == "Agua") {
			nuevo = new Agua(p->obtenerNombre(), p->obtenerEscudo(), p->obtenerVida(), p->obtenerEnergia());
		}else if (p->obtenerElemento() == "Tierra") {
			nuevo = new Tierra(p->obtenerNombre(), p->obtenerEscudo(), p->obtenerVida(), p->obtenerEnergia());
		}else if (p->obtenerElemento() == "Aire")
			nuevo = new Aire(p->obtenerNombre(), p->obtenerEscudo(), p->obtenerVida(), p->obtenerEnergia());
		equipos[i/3].alta(nuevo, equipos[i/3].obtenerCantidad() + 1);
	}
}

void Menu::mostrarMenu() {
	int opcion;
	do {
		cout << "----MENU DE OPCIONES----" << endl;
		cout << "1. Agregar un nuevo personaje." << endl;
		cout << "2. Eliminar un personaje." << endl;
		cout << "3. Mostrar todos los nombres de los personajes." << endl;
		cout << "4. Buscar por nombre los detalles de un personaje en particular." << endl;
		cout << "5. Comenzar juego." << endl;
		cout << "6. Salir." << endl;
		cout << "Elija una opcion: ";
		cin >> opcion;
		elegirOpcion(opcion);
	} while (opcion != 6);
	//autocompletarEquipo();
	seleccionarPosicion();
}
