/*
 * ABB_hoja.cpp
 *
 *  Created on: 31 ene. 2021
 *      Author: esteban
 */

#include "ABB_hoja.h"

Abb_hoja::Abb_hoja(string c, Personaje* d){
	clave = c;
	valor = d;
	hoja_izq = 0;
	hoja_der = 0;
}

void Abb_hoja::cambiar_valor(Personaje* d){
	valor = d;
}
string Abb_hoja::obtener_clave(){
	return clave;
}

Abb_hoja* &Abb_hoja::obtener_hoja_izq(){
	return hoja_izq;
}

Abb_hoja* &Abb_hoja::obtener_hoja_der(){
	return hoja_der;
}

Personaje* Abb_hoja::obtener_valor(){
	return valor;
}

void Abb_hoja::cambiar_hoja_izq(Abb_hoja* hoja){
	hoja_izq = hoja;
}

void Abb_hoja::cambiar_hoja_der(Abb_hoja* hoja){
	hoja_der = hoja;
}


