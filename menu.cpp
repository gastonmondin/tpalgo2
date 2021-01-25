#include "menu.h"
#include <fstream>

Menu::Menu() {
}

void Menu::crearPersonaje(string elemento, string nombre, int escudo, int vida) {
	if (elemento == "Fuego") {
		Personaje* nuevoPersonaje = new Fuego(nombre, escudo, vida);
		listaPersonajes.alta(nuevoPersonaje, listaPersonajes.obtenerCantidad()+1);		
	}else if (elemento == "Agua") {
		Personaje* nuevoPersonaje = new Agua(nombre, escudo, vida);
		listaPersonajes.alta(nuevoPersonaje, listaPersonajes.obtenerCantidad()+1);	
	}else if (elemento == "Tierra") {
		Personaje* nuevoPersonaje = new Tierra(nombre, escudo, vida);
		listaPersonajes.alta(nuevoPersonaje, listaPersonajes.obtenerCantidad()+1);
	}else if (elemento == "Aire") {
		Personaje* nuevoPersonaje = new Aire(nombre, escudo, vida);
		listaPersonajes.alta(nuevoPersonaje, listaPersonajes.obtenerCantidad()+1);
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
	int pos = listaPersonajes.obtenerPosicion(nombre);
	if (pos != 0)
		return listaPersonajes.consulta(pos);
	else
		cout << "No se encontro el personaje." << endl;
		return 0;
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
	cout << "Lista de personajes:" << endl;
	for (int i = 1; i <= listaPersonajes.obtenerCantidad(); i++)
		cout << listaPersonajes.consulta(i)->obtenerNombre() << endl;	
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
		case 5: personaje = buscarPersonaje(ingresarNombre());
			if (personaje !=0) alimentarPersonaje(personaje);
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

void Menu::mostrarMenu() {
	int opcion;
	do {
		cout << "----MENU DE OPCIONES----" << endl;
		cout << "1. Agregar un nuevo personaje." << endl;
		cout << "2. Eliminar un personaje." << endl;
		cout << "3. Mostrar todos los nombres de los personajes." << endl;
		cout << "4. Buscar por nombre los detalles de un personaje en particular." << endl;
		cout << "5. Alimentar un personaje." << endl;
		cout << "6. Salir." << endl;
		cout << "Elija una opcion: ";
		cin >> opcion;
		elegirOpcion(opcion);
	} while (opcion != 6);
}
