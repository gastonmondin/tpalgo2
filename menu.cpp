#include "menu.h"
#include <fstream>
#include <string>

Menu::Menu() {
}

void Menu::delay(float segs){
	for(int i=0; i<(segs * 1000); i++){
		for(int j=0; j<(segs * 1000); j++)
			for(int k=0; k<100; k++);
	}
}

void Menu::limpiar_tablero(){
	tablero = Tablero();
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
	for(int i = 0; i < stoi(cant) ; i++) {
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

void Menu::elegir_acciones(Dato personaje, int equipo){
	int accion;
	cout << "Personaje: " << personaje->obtenerNombre() << "\t\tEquipo: " << equipo << endl;
	cout << "Primera accion: \n 1. Alimentarse\n 2. Moverse\n 3. Pasar turno\n";
	cout << "Selecione: "; cin >> accion; cout << endl;

	if(accion == 1) personaje->cambiar_accion_1("alimentar");
	else if(accion == 2) personaje->cambiar_accion_1("mover");
	else personaje->cambiar_accion_1("pasar");

	cout << "Segunda accion: \n 1. Defenderse\n 2. Atacar\n 3. Pasar turno\n";
	cout << "Selecione: "; cin >> accion; cout << endl;

	if(accion == 1) personaje->cambiar_accion_2("defender");
	else if(accion == 2) personaje->cambiar_accion_2("atacar");
	else personaje->cambiar_accion_2("pasar");
}

void Menu::autoposicionar(){
	int grupo = 0;

	while(grupo < 2){
		for(int i=1; i<=equipos[grupo].obtenerCantidad(); i++){
			int x = equipos[grupo].consulta(i)->obtenerPosX();
			int y = equipos[grupo].consulta(i)->obtenerPosY();
			if(((grupo + 1) == 1))
				tablero.aparecerPersonaje(equipos[grupo].consulta(i), x, y);
			else
				tablero.aparecerPersonaje(equipos[grupo].consulta(i), x, y);
		}
		grupo++;
	}
}

void Menu::descripcion(Dato personaje){
	cout << "Personaje: " << personaje->obtenerNombre() << "\t\tElemento: " << personaje->obtenerElemento() << "\n";
	cout << "Vida: " << personaje->obtenerVida() << '\t' << "Energia: " << personaje->obtenerEnergia() << '\n';
	cout << "Escudo: Nivel " << personaje->obtenerEscudo() << endl;
}

void Menu::atacar_objetivo(Dato emisor, Dato receptor){
	if(emisor->obtenerElemento() == "Fuego"){
		int golpe = emisor->atacar(receptor->obtenerElemento());
		receptor->recibir_ataque(golpe);
	}else if(emisor->obtenerElemento() == "Agua"){

	}else if(emisor->obtenerElemento() == "Tierra"){
		int golpe = emisor->atacar(receptor->obtenerElemento());
		receptor->recibir_ataque(golpe);
	}else{

	}
}

void Menu::calcular_rango(int &ini, int &fin, int pos){
	if(pos == 0){
		ini = pos;
		fin = pos + 1;
	}else if(pos == 7){
		ini = pos - 1;
		fin = pos;
	}else{
		ini = pos - 1;
		fin = pos + 1;
	}
}

void Menu::radar_fuego(Dato personaje, int equipo){
	int y_ini, y_fin;
	int pos_y = personaje->obtenerPosY() - 1;
	calcular_rango(y_ini, y_fin, pos_y);
	for(int i=0; i<8; i++){
		for(int j=y_ini; j <= y_fin; j++){
			if(tablero.obtener_casillero(i, j)->obtenerSimbolo() == (char)equipo){
				atacar_objetivo(personaje, tablero.obtener_casillero(i, j)->obtenerPersonaje());
			}else if(tablero.obtener_casillero(i, j)->obtenerPersonaje() == 0){
				tablero.obtener_casillero(i, j)->asignarSimbolo('O');
			}
		}
		tablero.mostrar();
		descripcion(personaje);

		delay(2);
		limpiarPantalla();
	}
}

bool Menu::limites_tierra(int &x_ini, int &x_fin, int &y_ini, int &y_fin){
	if(x_ini == 0 && x_fin == 8 && y_ini == 0 && y_fin == 8)
		return true;

	if(x_ini > 0)	x_ini--;
	if(x_fin <= 7)	x_fin++;
	if(y_ini > 0)	y_ini--;
	if(y_fin <= 7)	y_fin++;

	return false;
}

void Menu::radar_tierra(Dato personaje, int equipo){
	int x_ini, x_fin, y_ini, y_fin;
	int pos_x = personaje->obtenerPosX() - 1;
	int pos_y = personaje->obtenerPosY() - 1;
	calcular_rango(x_ini, x_fin, pos_x);
	calcular_rango(y_ini, y_fin, pos_y);

	do{
		for(int i=y_ini; i<=y_fin; i++){
			for(int j=x_ini; j<=x_fin; j++){
				if(tablero.obtener_casillero(j, i)->obtenerSimbolo() == equipo){
					atacar_objetivo(personaje, tablero.obtener_casillero(j, i)->obtenerPersonaje());
				}else if(tablero.obtener_casillero(j, i)->obtenerPersonaje() == 0)
					tablero.obtener_casillero(j, i)->asignarSimbolo('O');
			}
		}
		tablero.mostrar();
		descripcion(personaje);

		delay(2);
		limpiarPantalla();

	}while(!limites_tierra(x_ini, x_fin, y_ini, y_fin));
}

void Menu::ataque_agua(Dato personaje, int equipo){
	int fil,col;
	cout << "Ingrese la Fila de su ataque "<<endl;
	cin>> fil ;
	cout << "Ingrese la Columna de  su ataque "<<endl;
	cin >> col;
	if (tablero.obtener_casillero(col, fil)->obtenerSimbolo() == equipo){
						atacar_objetivo(personaje, tablero.obtener_casillero(col, fil)->obtenerPersonaje());
					}else if(tablero.obtener_casillero(col, fil)->obtenerPersonaje() == 0){
						tablero.obtener_casillero(col, fil)->asignarSimbolo('O');
				}
	tablero.mostrar();
	descripcion(personaje);

	delay(3);
	limpiarPantalla();
}

void Menu::ataque_aire(Dato personaje, int equipo){
	for(int i = 1; i <= listaPersonajes.obtenerCantidad(); i++){
		if(listaPersonajes.consulta(i)->obtenerSimbolo() != equipo){
			atacar_objetivo(personaje,listaPersonajes.consulta(i));
				}
	tablero.mostrar();
	descripcion(personaje);

	delay(3);
	limpiarPantalla();
	}
}

void Menu::super_ataques(Dato personaje, string elemento, int energia, int equipo){
	if(elemento == "Fuego" && energia >= 5){
		radar_fuego(personaje, equipo);
	}else if(elemento == "Agua" && energia >= 5){
		ataque_agua(personaje,equipo);
	}else if(elemento == "Tierra" && energia >= 6){
		radar_tierra(personaje, equipo);
	}else if(elemento == "Aire" && energia >= 8){
		tablero.mostrar();
		descripcion(personaje);
		delay(3);
	}else{
		tablero.mostrar();
		descripcion(personaje);
		cout << "No pude atacar, me falta energia..." << endl;
		delay(4);
	}
	limpiarPantalla();
}

void Menu::defensas(Dato personaje, string elemento, int equipo){
	bool completado = personaje->defenderse();

	if(completado)
		cout << "Defenza realizada con exito\n";
	if(elemento == "Fuego" && completado){
		personaje->recuperar_vida();
	}else if(elemento == "Agua" && completado){
		for(int i=0; i<=equipos[equipo].obtenerCantidad(); i++){
			equipos[equipo].consulta(i)->recuperar_vida();
		}
	}else if(elemento == "Aire" && completado){

	}else
		cout << "Energia insuficiente" << endl;

	delay(4);
	limpiarPantalla();
	tablero.mostrar();
}

void Menu::ejecutar_acciones(){
	int grupo = 0;
	//modularizar!!!!!!!!!
	while(grupo < 2){
		for(int i=1; i<=equipos[grupo].obtenerCantidad(); i++){
			if(equipos[grupo].consulta(i)->obtener_accion_1() == ALIMENTAR)
				equipos[grupo].consulta(i)->alimentar();
			else if(equipos[grupo].consulta(i)->obtener_accion_1() == MOVER)
				;
			if(equipos[grupo].consulta(i)->obtener_accion_2() == ATACAR){
				if((grupo + 1) == 1)
					super_ataques(equipos[grupo].consulta(i), equipos[grupo].consulta(i)->obtenerElemento(), equipos[grupo].consulta(i)->obtenerEnergia(), 2);
				else
					super_ataques(equipos[grupo].consulta(i), equipos[grupo].consulta(i)->obtenerElemento(), equipos[grupo].consulta(i)->obtenerEnergia(), 1);
				limpiar_tablero();
				autoposicionar();
			}
		}
		grupo++;
	}
	tablero.mostrar();
}

void Menu::comenzar_juego(){
	int grupo = 0;
	/////////////////////////////////////////////
	//modularizar!!!!!!!!!
	while(grupo < 2){
		for(int i=1; i<=equipos[grupo].obtenerCantidad(); i++){
			if(equipos[grupo].consulta(i)->obtenerElemento() == "Tierra" && equipos[grupo].consulta(i)->obtener_accion_2() == DEFENDER){
				equipos[grupo].consulta(i)->cambiar_accion_2('\0');
				equipos[grupo].consulta(i)->cambiar_escudo();
			}
			elegir_acciones(equipos[grupo].consulta(i), grupo + 1);
			limpiarPantalla();
			tablero.mostrar();
			if(equipos[grupo].consulta(i)->obtener_accion_2() == DEFENDER)
				defensas(equipos[grupo].consulta(i), equipos[grupo].consulta(i)->obtenerElemento(), grupo + 1);
		}
		grupo++;
	}
	/////////////////////////////////////////////
	limpiarPantalla();
	ejecutar_acciones();

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

	comenzar_juego();
}
