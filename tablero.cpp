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

void Tablero::mostrar(){
	std::cout << "      ";
	for (int i = 1; i <= 8; i++)
		std::cout << i << "     ";
	std::cout << endl << "    _____ _____ _____ _____ _____ _____ _____ _____" << endl;
	for (int i = 0; i < 8; i++){
		std::cout << "   |     |     |     |     |     |     |     |     |" << endl;
		std::cout << " " << i+1 << " |  ";
		for (int j = 0; j < 8; j++){
			std::cout << casilleros[i][j].obtenerSimbolo() << "  |  ";
		}
		std::cout << endl << "   |_____|_____|_____|_____|_____|_____|_____|_____|" << endl;
	}
}

void Tablero::agregarPrimeraFila() {
	casilleros[0][0] = Lago();
	casilleros[0][1] = Lago();
	casilleros[0][2] = Precipicio();
	casilleros[0][3] = Precipicio();
	casilleros[0][4] = Precipicio();
	casilleros[0][5] = Vacio();
	casilleros[0][6] = Volcan();
	casilleros[0][7] = Volcan();
}

void Tablero::agregarSegundaFila() {
	casilleros[1][0] = Lago();
	casilleros[1][1] = Lago();
	casilleros[1][2] = Precipicio();
	casilleros[1][3] = Vacio();
	casilleros[1][4] = Volcan();
	casilleros[1][5] = Volcan();
	casilleros[1][6] = Volcan();
	casilleros[1][7] = Volcan();
}

void Tablero::agregarTerceraFila() {
	casilleros[2][0] = Precipicio();
	casilleros[2][1] = Volcan();
	casilleros[2][2] = Volcan();
	casilleros[2][3] = Volcan();
	casilleros[2][4] = Volcan();
	casilleros[2][5] = Precipicio();
	casilleros[2][6] = Precipicio();
	casilleros[2][7] = Precipicio();
}

void Tablero::agregarCuartaFila() {
	casilleros[3][0] = Volcan();
	casilleros[3][1] = Camino();
	casilleros[3][2] = Camino();
	casilleros[3][3] = Camino();
	casilleros[3][4] = Lago();
	casilleros[3][5] = Vacio();
	casilleros[3][6] = Camino();
	casilleros[3][7] = Camino();
}

void Tablero::agregarQuintaFila() {
	casilleros[4][0] = Camino();
	casilleros[4][1] = Camino();
	casilleros[4][2] = Vacio();
	casilleros[4][3] = Camino();
	casilleros[4][4] = Camino();
	casilleros[4][5] = Camino();
	casilleros[4][6] = Camino();
	casilleros[4][7] = Precipicio();
}

void Tablero::agregarSextaFila() {
	casilleros[5][0] = Camino();
	casilleros[5][1] = Camino();
	casilleros[5][2] = Camino();
	casilleros[5][3] = Vacio();
	casilleros[5][4] = Montana();
	casilleros[5][5] = Montana();
	casilleros[5][6] = Montana();
	casilleros[5][7] = Precipicio();
}

void Tablero::agregarSeptimaFila() {
	casilleros[6][0] = Precipicio();
	casilleros[6][1] = Montana();
	casilleros[6][2] = Montana();
	casilleros[6][3] = Montana();
	casilleros[6][4] = Montana();
	casilleros[6][5] = Lago();
	casilleros[6][6] = Lago();
	casilleros[6][7] = Lago();
}

void Tablero::agregarOctavaFila() {
	casilleros[7][0] = Precipicio();
	casilleros[7][1] = Precipicio();
	casilleros[7][2] = Montana();
	casilleros[7][3] = Precipicio();
	casilleros[7][4] = Vacio();
	casilleros[7][5] = Lago();
	casilleros[7][6] = Lago();
	casilleros[7][7] = Lago();
}

void Tablero::aparecerPersonaje(Personaje* p, int x, int y){
	p->asignarPos(x, y);
	casilleros[y-1][x-1].asignarPersonaje(p);
}

bool Tablero::casilleroDisponible(int x, int y){
	if (casilleros[y-1][x-1].obtenerPersonaje() == 0 && casilleros[y-1][x-1].obtenerTipo() != "Vacio")
		return true;
	else
		return false;
}

Tablero::~Tablero(){
	
}
