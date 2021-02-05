/*
 * ABB_raiz.cpp
 *
 *  Created on: 31 ene. 2021
 *      Author: esteban
 */

#include "ABB_raiz.h"

Abb_raiz::Abb_raiz(){
	raiz = 0;
}

void Abb_raiz::nuevo_hijo(Abb_hoja* &h, string c, Personaje* d){
	if(!h){
		Abb_hoja* nuevo = new Abb_hoja(c, d);
		h = nuevo;
	}else if(c < h->obtener_clave()){
		nuevo_hijo((h->obtener_hoja_izq()), c, d);
	}else if(c > h->obtener_clave()){
		nuevo_hijo(h->obtener_hoja_der(), c, d);
	}else
		cout << "Valor existente." << endl << endl;
}

void Abb_raiz::alta(string c, Personaje* d){
	if(!raiz){
		Abb_hoja* nuevo = new Abb_hoja(c, d);
		raiz = nuevo;
	}else{
		if(c < raiz->obtener_clave())
			nuevo_hijo(raiz->obtener_hoja_izq(), c, d);
		else if(c > raiz->obtener_clave())
			nuevo_hijo(raiz->obtener_hoja_der(), c, d);
		else
			cout << "Valor existente." << endl << endl;
	}
}

void Abb_raiz::mostrar_valor(Abb_hoja* h){
	cout << h->obtener_clave() << endl;
}

void Abb_raiz::mostrar_rama(Abb_hoja* h){
	if(!h)
		return;
	mostrar_rama(h->obtener_hoja_izq());
	mostrar_valor(h);
	mostrar_rama(h->obtener_hoja_der());
}

void Abb_raiz::mostrar_datos(){
	if(!raiz)
		return;
	mostrar_rama(raiz->obtener_hoja_izq());
	mostrar_valor(raiz);
	mostrar_rama(raiz->obtener_hoja_der());
}

Personaje* Abb_raiz::buscar_hoja(Abb_hoja* h, string c){
	if(!h){
		cout << "No existe." << endl;
		return 0;
	}
	else if(c == h->obtener_clave())
		return h->obtener_valor();
	else if(c < h->obtener_clave())
		return buscar_hoja(h->obtener_hoja_izq(), c);
	else
		return buscar_hoja(h->obtener_hoja_der(), c);
}

Personaje* Abb_raiz::buscar(string c){
	if(c == raiz->obtener_clave())
		return raiz->obtener_valor();
	else if(c < raiz->obtener_clave())
		return buscar_hoja(raiz->obtener_hoja_izq(), c);
	else
		return buscar_hoja(raiz->obtener_hoja_der(), c);
}

void Abb_raiz::borrar_hoja(Abb_hoja* h){
	if(!h)
		return;
	borrar_hoja(h->obtener_hoja_izq());
	borrar_hoja(h->obtener_hoja_der());
	h->cambiar_valor(0);
	delete h;
}

Abb_raiz::~Abb_raiz(){
	if(raiz){
		borrar_hoja(raiz->obtener_hoja_izq());
		borrar_hoja(raiz->obtener_hoja_der());
		delete raiz;
	}
}
