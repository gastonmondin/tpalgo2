#include "tablero.h"

Tablero::Tablero() {
	/*for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			dimensiones[i][j] = ' ';
		}
	}*/
	agregarLago();
	agregarVolcan();
	agregarPrecipicio();
	agregarMontana();
	agregarCamino();
	agregarVacio();
}

void Tablero::mostrar(){
	std::cout << " _____ _____ _____ _____ _____ _____ _____ _____\n";
	for (int i = 0; i < 8; i++){
		std::cout << "|     |     |     |     |     |     |     |     |\n";
		std::cout << "|  ";
		for (int j = 0; j < 8; j++){
			std::cout << dimensiones[i][j] << "  |  ";
		}
		std::cout << "\n";
		std::cout << "|_____|_____|_____|_____|_____|_____|_____|_____|\n";
	}
}

void Tablero::agregarLago(){
	dimensiones[0][0] = dimensiones[0][1] = 'L';
	dimensiones[1][0] = dimensiones[1][1] = 'L';
	dimensiones[3][4] = dimensiones[6][5] = 'L';
	dimensiones[6][6] = dimensiones[6][7] = 'L';
	dimensiones[7][5] = dimensiones[7][6] = 'L';
	dimensiones[7][7] = 'L';
}

void Tablero::agregarVolcan(){
	dimensiones[0][6] = dimensiones[0][7] = 'V';
	dimensiones[1][4] = dimensiones[1][5] = 'V';
	dimensiones[1][6] = dimensiones[1][7] = 'V';
	dimensiones[2][1] = dimensiones[2][2] = 'V';
	dimensiones[2][3] = dimensiones[2][4] = 'V';
	dimensiones[3][0] = 'V';
}

void Tablero::agregarPrecipicio(){
	dimensiones[0][2] = dimensiones[0][3] = 'P';
	dimensiones[0][4] = dimensiones[1][2] = 'P';
	dimensiones[2][0] = dimensiones[2][5] = 'P';
	dimensiones[2][6] = dimensiones[2][7] = 'P';
	dimensiones[4][7] = dimensiones[5][7] = 'P';
	dimensiones[6][0] = dimensiones[7][0] = 'P';
	dimensiones[7][1] = dimensiones[7][3] = 'P';
}

void Tablero::agregarMontana(){
	dimensiones[5][4] = dimensiones[5][5] = 'M';
	dimensiones[5][6] = dimensiones[6][1] = 'M';
	dimensiones[6][2] = dimensiones[6][3] = 'M';
	dimensiones[6][4] = dimensiones[7][2] = 'M';
}

void Tablero::agregarCamino(){
	dimensiones[3][1] = dimensiones[3][2] = 'C';
	dimensiones[3][3] = dimensiones[3][6] = 'C';
	dimensiones[3][7] = dimensiones[4][0] = 'C';
	dimensiones[4][1] = dimensiones[4][3] = 'C';
	dimensiones[4][4] = dimensiones[4][5] = 'C';
	dimensiones[4][6] = dimensiones[5][0] = 'C';
	dimensiones[5][1] = dimensiones[5][2] = 'C';
}

void Tablero::agregarVacio(){
	dimensiones[0][5] = dimensiones[1][3] = ' ';
	dimensiones[3][5] = dimensiones[4][2] = ' ';
	dimensiones[5][3] = dimensiones[1][3] = ' ';
	dimensiones[7][4] = ' ';
}

Tablero::~Tablero(){
	
}
