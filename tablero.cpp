#include "tablero.h"

Tablero::Tablero() {
	agregarPrimeraFila();
	agregarSegundaFila();
	agregarTerceraFila();
	agregarCuartaFila();
	agregarQuintaFila();
	agregarSextaFila();
	agregarSeptimaFila();
	agregarOctavaFila();
}

void Tablero::limpiarPantalla() {
	#ifdef _WIN32
		system("cls");
	#else
		system ("clear");
	#endif
}

void Tablero::mostrar(){
	std::cout << "      ";
	for (int i = 1; i <= 8; i++)
		std::cout << i << "     ";
	std::cout << endl << "    _____ _____ _____ _____ _____ _____ _____ _____" << endl;
	for (int i = 0; i < 8; i++){
		std::cout << "   |     |     |     |     |     |     |     |     |" << endl;
		std::cout << " " << i+1 << " |  ";
		for (int j = 0; j < 8; j++){
			std::cout << casilleros[i][j]->obtenerSimbolo() << "  |  ";
		}
		std::cout << endl << "   |_____|_____|_____|_____|_____|_____|_____|_____|" << endl;
	}
}

void Tablero::agregarPrimeraFila() {
	casilleros[0][0] = new Lago();
	casilleros[0][1] = new Lago();
	casilleros[0][2] = new Precipicio();
	casilleros[0][3] = new Precipicio();
	casilleros[0][4] = new Precipicio();
	casilleros[0][5] = new Vacio();
	casilleros[0][6] = new Volcan();
	casilleros[0][7] = new Volcan();
}

void Tablero::agregarSegundaFila() {
	casilleros[1][0] = new Lago();
	casilleros[1][1] = new Lago();
	casilleros[1][2] = new Precipicio();
	casilleros[1][3] = new Vacio();
	casilleros[1][4] = new Volcan();
	casilleros[1][5] = new Volcan();
	casilleros[1][6] = new Volcan();
	casilleros[1][7] = new Volcan();
}

void Tablero::agregarTerceraFila() {
	casilleros[2][0] = new Precipicio();
	casilleros[2][1] = new Volcan();
	casilleros[2][2] = new Volcan();
	casilleros[2][3] = new Volcan();
	casilleros[2][4] = new Volcan();
	casilleros[2][5] = new Precipicio();
	casilleros[2][6] = new Precipicio();
	casilleros[2][7] = new Precipicio();
}

void Tablero::agregarCuartaFila() {
	casilleros[3][0] = new Volcan();
	casilleros[3][1] = new Camino();
	casilleros[3][2] = new Camino();
	casilleros[3][3] = new Camino();
	casilleros[3][4] = new Lago();
	casilleros[3][5] = new Vacio();
	casilleros[3][6] = new Camino();
	casilleros[3][7] = new Camino();
}

void Tablero::agregarQuintaFila() {
	casilleros[4][0] = new Camino();
	casilleros[4][1] = new Camino();
	casilleros[4][2] = new Vacio();
	casilleros[4][3] = new Camino();
	casilleros[4][4] = new Camino();
	casilleros[4][5] = new Camino();
	casilleros[4][6] = new Camino();
	casilleros[4][7] = new Precipicio();
}

void Tablero::agregarSextaFila() {
	casilleros[5][0] = new Camino();
	casilleros[5][1] = new Camino();
	casilleros[5][2] = new Camino();
	casilleros[5][3] = new Vacio();
	casilleros[5][4] = new Montana();
	casilleros[5][5] = new Montana();
	casilleros[5][6] = new Montana();
	casilleros[5][7] = new Precipicio();
}

void Tablero::agregarSeptimaFila() {
	casilleros[6][0] = new Precipicio();
	casilleros[6][1] = new Montana();
	casilleros[6][2] = new Montana();
	casilleros[6][3] = new Montana();
	casilleros[6][4] = new Montana();
	casilleros[6][5] = new Lago();
	casilleros[6][6] = new Lago();
	casilleros[6][7] = new Lago();
}

void Tablero::agregarOctavaFila() {
	casilleros[7][0] = new Precipicio();
	casilleros[7][1] = new Precipicio();
	casilleros[7][2] = new Montana();
	casilleros[7][3] = new Precipicio();
	casilleros[7][4] = new Vacio();
	casilleros[7][5] = new Lago();
	casilleros[7][6] = new Lago();
	casilleros[7][7] = new Lago();
}

void Tablero::aparecerPersonaje(Personaje* p, int x, int y){
	p->asignarPos(x, y);
	casilleros[y-1][x-1]->asignarPersonaje(p);
}

bool Tablero::casilleroDisponible(int x, int y){
	if (casilleros[y-1][x-1]->obtenerPersonaje() == 0)
		return true;
	else
		return false;
}

Casillero* Tablero::obtenerCasillero(int x, int y){
	return casilleros[y-1][x-1];
}

void Tablero::inicializarMatrizDistancias(string elemento){
	for (int i = 0; i < VERTICES; i++){
		for (int j = 0; j < VERTICES; j++) {
			if (i == j)
				distancia [i][j] = 0;
			else if ((i - 1 == j && j % 8 != 7) || (i + 1 == j && j % 8 != 0) || (i - 8 == j) || (i + 8 == j)){
				distancia[i][j] = casilleros[j/8][j%8]->obtenerCosto(elemento);
				siguiente[i][j] = j;
			}
			else{
				distancia[i][j] = INFINITO;
				siguiente[i][j] = -1;
			}	
		}
	}
}

void Tablero::completarDistancias() {
	for(int k = 0; k < VERTICES; k++){  // Floyd-Warshall
		for(int i = 0; i < VERTICES; i++)
            for(int j = 0; j < VERTICES; j++){
                if(distancia[i][j] > distancia[i][k] + distancia[k][j]){
                	distancia[i][j] = distancia[i][k] + distancia[k][j];
                    siguiente[i][j] = siguiente[i][k];
				}  
    		}
	}
}

void Tablero::realizarMovimiento(Personaje* p, int i, int j){
	while (i != j){
		limpiarPantalla();
		casilleros[i/8][i%8]->asignarPersonaje(0);
		i = siguiente[i][j];
		casilleros[i/8][i%8]->asignarPersonaje(p);
		mostrar();
		usleep(250000);
	}
}

bool Tablero::moverPersonaje(Personaje* p, int x, int y) {
	bool mover;
	inicializarMatrizDistancias(p->obtenerElemento());
	completarDistancias();
	int fuente = (p->obtenerPosY() - 1) * 8 + p->obtenerPosX() - 1;
	int destino = (y - 1) * 8 + x - 1;
	if (p->obtenerEnergia() < distancia[fuente][destino]) {
		cout << "Energia insuficiente." << endl;
		sleep(1);
		mover = false;	
	} else if (casilleros[y-1][x-1]->obtenerPersonaje() != 0) {
		cout << "Ya hay un personaje en esa posicion." << endl;
		sleep(2);
		mover = false;
	} else {
		realizarMovimiento(p, fuente, destino);
    	p->asignarPos(x, y);
    	p->asignarEnergia(p->obtenerEnergia() - distancia[fuente][destino]);
    	cout << p->obtenerNombre() << " gasto " << distancia[fuente][destino] << " de energia." << endl;
    	mover = true;
    	sleep(3);
	}
    return mover;
}

Tablero::~Tablero(){
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++)
			delete casilleros[i][j];
	}
}
