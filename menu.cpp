#include "menu.h"
#include <fstream>
#include <string>

Menu::Menu() {
	exit = false;
}

void Menu::verificarEquipo(int &equipo){
	while(equipo != 1 && equipo != 2){
		cout << "Error. Reingrese: " << endl;
		cin >> equipo;
	}
}

void Menu::crearPersonaje(string elemento, string nombre, int escudo, int vida) {
	if (elemento == "Fuego") {
		Personaje* nuevoPersonaje = new Fuego(nombre, escudo, vida, rand() % 21);
		listaPersonajes.alta(nuevoPersonaje, listaPersonajes.obtenerCantidad()+1);
		arbol.alta(nombre, nuevoPersonaje);
	}else if (elemento == "Agua") {
		Personaje* nuevoPersonaje = new Agua(nombre, escudo, vida, rand() % 21);
		listaPersonajes.alta(nuevoPersonaje, listaPersonajes.obtenerCantidad()+1);
		arbol.alta(nombre, nuevoPersonaje);
	}else if (elemento == "Tierra") {
		Personaje* nuevoPersonaje = new Tierra(nombre, escudo, vida, rand() % 21);
		listaPersonajes.alta(nuevoPersonaje, listaPersonajes.obtenerCantidad()+1);
		arbol.alta(nombre, nuevoPersonaje);
	}else if (elemento == "Aire") {
		Personaje* nuevoPersonaje = new Aire(nombre, escudo, vida, rand() % 21);
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
	for(int i = 0; i < stoi(cant) ; i++) {
		getline(personajes, linea);
		procesarLinea(linea);
	}
	personajes.close();
}

Personaje* Menu::buscarPersonaje(string nombre) {
	return arbol.buscar(nombre);
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

void Menu::mostrarPersonajes() {
	cout << "Lista de personajes:" << endl;
	arbol.mostrar_datos();
	cout << endl;
}

void Menu::mostrarDetalles(Personaje* personaje) {
	cout << "Elemento: " << personaje->obtenerElemento() << endl;
		cout << "Escudo: " << personaje->obtenerEscudo() << endl;
		cout << "Vida: " << personaje->obtenerVida() << endl;
		cout << "Energia: " << personaje->obtenerEnergia() << endl;	
}

void Menu::alimentarPersonaje(Personaje* p) {
	int energiaAnterior, vidaAnterior;
	energiaAnterior = p->obtenerEnergia();
	vidaAnterior = p->obtenerVida();
	if (p->alimentar()) {
		cout << p->obtenerNombre() << " fue alimentado con " << p->obtenerAlimento() << " y recupero ";
		cout << (p->obtenerEnergia() - energiaAnterior) << " de energia";
		if (p->obtenerElemento() == "Fuego")
			cout << " y " << (p->obtenerVida() - vidaAnterior) << " de vida";
		cout << "." << endl;
	} else {
		cout << p->obtenerNombre() << " no fue alimentado porque ";
		if (p->obtenerElemento() == "Aire")
			cout << "es un personaje de aire." << endl;
		else
			cout << "ya fue alimentado 3 veces." << endl;
	}
	sleep(3);
}

void Menu::verificarEscudo(Personaje* p) {
	if ((p->obtenerElemento() == "Tierra") && (p->obtenerDefenderse())){
		p->terminarDefenderse();
		cout << "El escudo extra de " << p->obtenerNombre();
		cout << " dejo de hacer efecto." << endl;
		sleep(3);
	}
}

void Menu::verificarEnergia(Personaje* p) {
	if ((p->obtenerElemento() == "Fuego") && (p->obtenerEnergia() == 0)){
		int vidaAnterior = p->obtenerVida();
		p->asignarVida(p->obtenerVida() - 5);
		cout << "La energia de " << p->obtenerNombre() << " es 0, por lo tanto pierde ";
		cout << (vidaAnterior - p->obtenerVida()) << " de vida." << endl;
		sleep(3);
		verificarEstado(p);
	}
}

void Menu::recuperarEnergia(Personaje* p) {
	if (p->obtenerElemento() == "Aire"){
		int energiaAnterior = p->obtenerEnergia();
		p->asignarEnergia(p->obtenerEnergia() + 5);
		cout << p->obtenerNombre() << " recupero ";
		cout << (p->obtenerEnergia() - energiaAnterior) << " de energia." << endl;
		sleep(3);
	}
}

Personaje* Menu::elegido(string elemento, string nombre, int escudo, int vida, int energia){
	if (elemento == "Fuego") {
		return new Fuego(nombre, escudo, vida, energia);
	}else if (elemento == "Agua") {
		return new Agua(nombre, escudo, vida, energia);
	}else if (elemento == "Tierra") {
		return new Tierra(nombre, escudo, vida, energia);
	}else
		return new Aire(nombre, escudo, vida, energia);
}

void Menu::cargarEquipos(Personaje* p){
	int equipo;
	cout << "Seleccione su equipo: ";
	cin >> equipo; cout << endl;
	verificarEquipo(equipo);

	if(equipo == 1 && equipos[0].obtenerCantidad() < 3){
		p->asignarSeleccionado();
		Dato nuevo = elegido(p->obtenerElemento(),p->obtenerNombre(), p->obtenerEscudo(), p->obtenerVida(), p->obtenerEnergia());
		equipos[0].alta(nuevo, equipos[0].obtenerCantidad() + 1);
	} else if (equipo == 2 && equipos[1].obtenerCantidad() < 3){
		Dato nuevo = elegido(p->obtenerElemento(),p->obtenerNombre(), p->obtenerEscudo(), p->obtenerVida(), p->obtenerEnergia());
		equipos[1].alta(nuevo, equipos[1].obtenerCantidad() + 1);
	} else
		cout << "Equipo completo." << endl;
}

void Menu::verificarDisponible(Personaje* p){
	if(!p->obtenerSeleccionado()){
		cargarEquipos(p);
	}else
		cout << "Personaje no disponible." << endl;
}

void Menu::elegirOpcionSubmenu(int opcion){
	Personaje* personaje;
	limpiarPantalla();
	switch (opcion) {
		case 1: personaje = buscarPersonaje(ingresarNombre());
			if (personaje !=0) mostrarDetalles(personaje);
			break;
		case 2: mostrarPersonajes();
			break;
		case 3:	personaje = buscarPersonaje(ingresarNombre());
			if (personaje !=0){
				verificarDisponible(personaje);
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
		cout << "Elija la posicion de " << seleccionado->obtenerNombre() << ": " << endl;
		y = elegirFila();
		x = elegirColumna();
		if (tablero.casilleroDisponible(x, y)){
			seleccionado->asignarSimbolo(turno + '0');
			tablero.aparecerPersonaje(seleccionado, x, y);
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

void Menu::mostrarSubmenu(){
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
			elegirOpcionSubmenu(opcion);
		}
	} while (opcion != 4 && !completo);
	

	if(completo){
		cout << "Empieza el juego!" << endl;
		sleep(3);
		seleccionarPosicion();
		comenzarJuego();
	}
}

void Menu::elegirOpcionMenu(int opcion) {
	Personaje* personaje;
	limpiarPantalla();
	switch (opcion) {
		case 1: nuevoPersonaje();
			break;
		case 2: arbol.eliminar_hoja(ingresarNombre());
			break;
		case 3: mostrarPersonajes();
			break;
		case 4: personaje = buscarPersonaje(ingresarNombre());
			if (personaje !=0) mostrarDetalles(personaje);
			break;
		case 5: mostrarSubmenu();
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

void Menu::mostrarDescripcion(Personaje* p){
	Casillero* c = tablero.obtenerCasillero(p->obtenerPosX(), p->obtenerPosY());
	cout << "Personaje: " << p->obtenerNombre() << "     Elemento: " << p->obtenerElemento() << endl;
	cout << "Terreno: " << c->obtenerTipo();
	cout << "     Posicion: (" << p->obtenerPosX() << "," << p->obtenerPosY() << ")" << endl;
	cout << "Vida: " << p->obtenerVida() << "     Energia: " << p->obtenerEnergia() << endl;
	cout << "Escudo: Nivel " << p->obtenerEscudo() << endl;
}

void Menu::guardar(ofstream &archivo, Dato personaje){
	string elemento = personaje->obtenerElemento();
	string nombre = personaje->obtenerNombre();
	int escudo = personaje->obtenerEscudo();
	int vida = personaje->obtenerVida();
	int energia = personaje->obtenerEnergia();
	int fila = personaje->obtenerPosY();
	int columna = personaje->obtenerPosX();

	archivo << elemento << "," << nombre << "," << escudo << "," << vida << "," << energia << "," << fila << "," << columna << "\n";
}

void Menu::guardarDatos(int grupo){
	ofstream archivo;

	cout << "Creando archivo..." << endl;
	sleep(3);
	archivo.open("partida.csv");
	if(!archivo){
		cout << "Imposible crear el archivo." << endl;
		sleep(3);
		return;
	}
	archivo << grupo << "\n";
	for (int i = 0; i <= 1; i++)
		for(int j = 1; j <= equipos[i].obtenerCantidad(); j++)
			guardar(archivo, equipos[i].consulta(j));
	cout << "Carga completa." << endl;
	sleep(3);
	archivo.close();
}

void Menu::retomarDatos(ifstream &archivo){
	int i=0, grupo = 0;
	string elemento, nombre, escudo, vida, energia, posY, posX;
	Personaje* nuevo;
	getline(archivo, elemento);
	while(getline(archivo, elemento, ',')){
		getline(archivo, nombre, ',');
		getline(archivo, escudo, ',');
		getline(archivo, vida, ',');
		getline(archivo, energia, ',');
		getline(archivo, posY, ',');
		getline(archivo, posX);
		nuevo = elegido(elemento, nombre, atoi(escudo.c_str()), atoi(vida.c_str()), atoi(energia.c_str()));
		equipos[grupo].alta(nuevo, equipos[grupo].obtenerCantidad() + 1);
		i++;
		equipos[grupo].consulta(i)->asignarSimbolo(grupo + 1 + '0');
		tablero.aparecerPersonaje(equipos[grupo].consulta(i), atoi(posX.c_str()), atoi(posY.c_str()));

		if(i == 3){
			grupo++;
			i = 0;
		}

	}
	cout << "Carga de datos completado." << endl;
	sleep(3);
}

bool Menu::reanudarPartida(){
	limpiarPantalla();
	ifstream archivo;
	archivo.open("partida.csv");
	if(!archivo){
		return false;
	}
	char resp;
	cout << "Existe una partida guardada.\n\nDesea reanudar la partida (S/N)? : ";
	cin >> resp;
	if(resp == 'S' || resp == 's'){
		retomarDatos(archivo);
		archivo.close();
		remove("partida.csv");
		return true;
	}
	archivo.close();
	remove("partida.csv");
	return false;
}

void Menu::verificarEstado(Personaje* p) {
	if (p->obtenerVida() == 0){
		int equipo;
		Casillero* c = tablero.obtenerCasillero(p->obtenerPosX(), p->obtenerPosY());
		c->asignarPersonaje(0);
		p->asignarPos(0, 0);
		cout << p->obtenerNombre() << " se ha debilitado." << endl;
		if (p->obtenerSimbolo() == '1')
			equipo = 0;
		else
			equipo = 1;
		for (int i = 1; i <= equipos[equipo].obtenerCantidad(); i++)
			if (p == equipos[equipo].consulta(i))
				equipos[equipo].baja(i);
		sleep(3);
	}
}

void Menu::realizarAtaque(Personaje* emisor, Personaje* receptor, int rango){
	int vidaAnterior = receptor->obtenerVida();
	if (emisor->obtenerElemento() == "Tierra"){
		emisor->atacar(receptor, rango);
		receptor->asignarAtacado(true);
	}	
	else
		emisor->atacar(receptor);
	cout << emisor->obtenerNombre() << " le quito " << vidaAnterior - receptor->obtenerVida();
	cout << " de vida a " << receptor->obtenerNombre() << "." << endl;
	sleep(3);
	verificarEstado(receptor);
}

void Menu::ataqueAgua(Personaje* emisor){
	Casillero* c = tablero.obtenerCasillero(elegirColumna(), elegirFila());
	if (c->obtenerPersonaje()){
		Personaje* receptor = c->obtenerPersonaje();
		if (emisor->obtenerSimbolo() != receptor->obtenerSimbolo())
			realizarAtaque(emisor, receptor, 0);	
		else{
			cout << "No se puede atacar a un personaje del mismo equipo." << endl;
			sleep(3);
		}	
	} else{
		cout << "No hay ningun personaje en esa posicion." << endl;
		sleep(3);
	}	
}

void Menu::ataqueAire(Personaje* emisor){
	int rival, equipo
	;
	if (emisor->obtenerSimbolo() == '1')
		equipo = 1;
	else
		equipo = 0;
	for (int i = 1; i <= equipos[equipo].obtenerCantidad(); i++){
		Personaje* receptor = equipos[equipo].consulta(i);
		realizarAtaque(emisor, receptor, 0);
	}
}

void Menu::ataqueFuego(Personaje* emisor){
	int y = emisor->obtenerPosY();
	for (int i = 1; i <= 8; i++){
		animacionFuego(i, y);
		for (int j = limiteSuperior(y - 1); j <= limiteInferior(y + 1); j++){
			Personaje* receptor = tablero.obtenerCasillero(i, j)->obtenerPersonaje();
			if (receptor && receptor->obtenerSimbolo() != emisor->obtenerSimbolo())
				realizarAtaque(emisor, receptor, 0);
		}
	}
	refrescarTablero();
}

void Menu::animacionFuego(int i, int y){
	for (int j = limiteSuperior(y - 1); j <= limiteInferior(y + 1); j++)
		tablero.obtenerCasillero(i, j)->asignarAtaqueFuego(true);
	limpiarPantalla();
	tablero.mostrar();
	usleep(250000);
}

int Menu::limiteSuperior(int limite) {
	if (limite < 1)
		return limite + 1;
	else
		return limite;
}

int Menu::limiteInferior(int limite) {
	if (limite > 8)
		return limite - 1;
	else
		return limite;
}

void Menu::ataqueTierra(Personaje* emisor){
	int x = emisor->obtenerPosX();
	int y = emisor->obtenerPosY();
	for (int k = 1; k <= 7; k++){
		animacionTierra(k, x, y);
		for (int i = x - k; i <= x + k; i++){
			for (int j = y - k; j <= y + k; j++)
				if ((i >= 1 && i <= 8) && (j >= 1 && j <= 8)){
					Personaje* receptor = tablero.obtenerCasillero(i, j)->obtenerPersonaje();
					if (receptor && (receptor->obtenerSimbolo() != emisor->obtenerSimbolo()) && !receptor->obtenerAtacado())
						realizarAtaque(emisor, receptor, k);
				}
		}
	}
	refrescarTablero();
}

void Menu::animacionTierra(int k, int x, int y){
	for (int i = x - k; i <= x + k; i++){
		for (int j = y - k; j <= y + k; j++)
			if ((i >= 1 && i <= 8) && (j >= 1 && j <= 8) && (i != x || j != x))
				tablero.obtenerCasillero(i, j)->asignarAtaqueTierra(true);
	}
	limpiarPantalla();
	tablero.mostrar();
	usleep(250000);
}

void Menu::refrescarTablero(){
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++){
			tablero.obtenerCasillero(i, j)->asignarAtaqueTierra(false);
			tablero.obtenerCasillero(i, j)->asignarAtaqueFuego(false);
			Personaje* p = tablero.obtenerCasillero(i, j)->obtenerPersonaje();
			if (p && p->obtenerAtacado())
				p->asignarAtacado(false);
		}
}

void Menu::ataquePersonaje(Personaje* p){
	if ((p->obtenerElemento() == "Agua") && (p->obtenerEnergia() >= 5)) {
		ataqueAgua(p);
		p->asignarEnergia(p->obtenerEnergia() - 5);
		cout << p->obtenerNombre() << " gasto 5 de energia para realizar su ataque." << endl;
	} else if ((p->obtenerElemento() == "Aire") && (p->obtenerEnergia() >= 8)) {
		ataqueAire(p);
		p->asignarEnergia(p->obtenerEnergia() - 8);
		cout << p->obtenerNombre() << " gasto 8 de energia para realizar su ataque." << endl;
	} else if ((p->obtenerElemento() == "Fuego") && (p->obtenerEnergia() >= 8)) {
		ataqueFuego(p);
		p->asignarEnergia(p->obtenerEnergia() - 8);
		cout << p->obtenerNombre() << " gasto 8 de energia para realizar su ataque." << endl;
	} else if ((p->obtenerElemento() == "Tierra") && (p->obtenerEnergia() >= 6)){
		ataqueTierra(p);
		p->asignarEnergia(p->obtenerEnergia() - 6);
		cout << p->obtenerNombre() << " gasto 6 de energia para realizar su ataque." << endl;
	} else
		cout << p->obtenerNombre() << " no tiene suficiente energia para realizar el ataque." << endl;
	sleep(3);
}

void Menu::defensaAgua(Personaje* emisor) {
	int equipo;
	if (emisor->obtenerSimbolo() == '1')
		equipo = 0;
	else
		equipo = 1;
	for (int i = 1; i <= equipos[equipo].obtenerCantidad(); i++){
		Personaje* receptor = equipos[equipo].consulta(i);
		int vidaAnterior = receptor->obtenerVida();
		if (emisor == receptor){
			receptor->asignarVida(receptor->obtenerVida() + 50);
			cout << emisor->obtenerNombre() << " se curo ";
			cout << receptor->obtenerVida() - vidaAnterior << " de vida." << endl;
		}	
		else{
			receptor->asignarVida(receptor->obtenerVida() + 10);
			cout << emisor->obtenerNombre() << " le curo ";
			cout << receptor->obtenerVida() - vidaAnterior;
			cout << " de vida a " << receptor->obtenerNombre() << "." << endl;
		}
		sleep(3);		
	}
}

void Menu::defensaAire(Personaje* p) {
	Casillero* c = tablero.obtenerCasillero(p->obtenerPosX(), p->obtenerPosY());
	tablero.aparecerPersonaje(p, elegirColumna(), elegirFila());
	c->asignarPersonaje(0);
	cout << p->obtenerNombre() << " se teletransporto a (";
	cout << p->obtenerPosX() << "," << p->obtenerPosY() << ")." << endl;
}

void Menu::defensaFuego(Personaje* p) {
	int vidaAnterior = p->obtenerVida();
	p->asignarVida(p->obtenerVida() + 10);
	cout << p->obtenerNombre() << " se curo ";
	cout << p->obtenerVida() - vidaAnterior << " de vida." << endl;
}

void Menu::defensaTierra(Personaje* p) {
	int escudoAnterior = p->obtenerEscudo();
	p->defender();
	cout << p->obtenerNombre() << " tiene un escudo de ";
	cout << p->obtenerEscudo() << " puntos durante un turno." << endl;
}

void Menu::defensaPersonaje(Personaje* p){
	if ((p->obtenerElemento() == "Agua") && (p->obtenerEnergia() >= 12)) {
		defensaAgua(p);
		p->asignarEnergia(p->obtenerEnergia() - 12);
		cout << p->obtenerNombre() << " gasto 12 de energia para defenderse." << endl;
	} else if ((p->obtenerElemento() == "Aire") && (p->obtenerEnergia() >= 15)) {
		defensaAire(p);
		p->asignarEnergia(p->obtenerEnergia() - 15);
		cout << p->obtenerNombre() << " gasto 15 de energia para defenderse." << endl;
	} else if ((p->obtenerElemento() == "Fuego") && (p->obtenerEnergia() >= 10)) {
		defensaFuego(p);
		p->asignarEnergia(p->obtenerEnergia() - 10);
		cout << p->obtenerNombre() << " gasto 10 de energia para defenderse." << endl;
	} else if ((p->obtenerElemento() == "Tierra") && (p->obtenerEnergia() >= 6)){
		defensaTierra(p);
		p->asignarEnergia(p->obtenerEnergia() - 6);
		cout << p->obtenerNombre() << " gasto 6 de energia para defenderse." << endl;
	} else
		cout << p->obtenerNombre() << " no tiene suficiente energia para defenderse." << endl;	
	sleep(3);
}

int Menu::elegirOpcion(Personaje* p, int o) {
	int opcion;
	limpiarPantalla();
	tablero.mostrar();
	cout << "Turno del jugador " << p->obtenerSimbolo() << "." << endl;
	mostrarDescripcion(p);
	if (o == 1)
		cout << "1. Alimentarse." << endl << "2. Moverse." << endl;
	else
		cout << "1. Atacar." << endl << "2. Defenderse." << endl;	
	cout << "3. Pasar opcion." << endl << "4. Salir del juego." << endl;
	do {
		if (opcion < 1 && opcion > 4)
			cout << "Opcion invalida, ingrese de nuevo: ";
		else
			cout << "Ingrese una opcion: ";
		cin >> opcion;
	} while (opcion < 1 && opcion > 4);
	if(opcion == 4)
		exit = true;
	return opcion;
}

int Menu::elegirFila(){
	int fila;
	cout << "Ingrese fila: ";
	cin >> fila;
	return fila;
}

int Menu::elegirColumna(){
	int columna;
	cout << "Ingrese columna: ";
	cin >> columna;
	return columna;
}

bool Menu::ejecutarPrimeraOpcion(int opcion, Personaje* p){
	bool ejecutar;
	switch (opcion) {
		case 1:
			alimentarPersonaje(p);
			ejecutar = true;
			break;
		case 2:
			if (!tablero.moverPersonaje(p, elegirColumna(), elegirFila())) {
				cout << "El movimiento no se realizo, elija otra opcion u otro lugar para moverse." << endl;
				sleep(3);
				ejecutar = false;
			} else
				ejecutar = true;
			break;	
		case 3:
			ejecutar = true;
			break;
		case 4:
			guardarDatos(p->obtenerSimbolo() - '0');
			ejecutar = false;
	}
	return ejecutar;
}

bool Menu::ejecutarSegundaOpcion(int opcion, Personaje* p){
	bool ejecutar;
	switch (opcion) {
		case 1:
			ataquePersonaje(p);
			ejecutar = true;
			break;
		case 2:
			defensaPersonaje(p);
			ejecutar = true;
			break;
		case 3:
			ejecutar = true;
			break;
		case 4:
			guardarDatos(p->obtenerSimbolo() - '0');
			ejecutar = false;
	}
	return ejecutar;
}

bool Menu::gameOver() {
	if (equipos[0].obtenerCantidad() == 0) {
		cout << "Juego terminado, el ganador es el jugador 2." << endl;
		sleep(3);
		return true;
	} else if (equipos[1].obtenerCantidad() == 0) {
		cout << "Juego terminado, el ganador es el jugador 1." << endl;
		sleep(3);
		return true;
	} else
		return false;
}

bool Menu::partidaGuardada() {
	ifstream archivo;
	archivo.open("partida.csv");
	if(!archivo){
		return false;
	}

	archivo.close();
	return true;
}

void Menu::comenzarJuego(){
	int cont1 = 1, cont2 = 1, turno = rand() % 2 + 1;
	Personaje* seleccionado;
	do {
		if (turno == 1){
			if (cont1 > equipos[turno-1].obtenerCantidad())
				cont1 = 1;
			seleccionado = equipos[turno-1].consulta(cont1);
		} else {
			if (cont2 > equipos[turno-1].obtenerCantidad())
				cont2 = 1;
			seleccionado = equipos[turno-1].consulta(cont2);
		}
		verificarEscudo(seleccionado);
		if(ejecutarPrimeraOpcion(elegirOpcion(seleccionado, 1), seleccionado) && ejecutarSegundaOpcion(elegirOpcion(seleccionado, 2), seleccionado)){
			if (turno == 1){
				turno++;
				cont1++;
			} else {
				turno--;
				cont2++;
			}
			verificarEnergia(seleccionado);
			recuperarEnergia(seleccionado);
		}
	} while(!gameOver() && !partidaGuardada());
}

bool Menu::juego_cortado(){
	return exit;
}

void Menu::mostrarMenu() {

	if(!reanudarPartida()){
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
			elegirOpcionMenu(opcion);

		} while (opcion != 6 && !juego_cortado());
	} else
		comenzarJuego();
	cout << "Fin del juego." << endl;
}
