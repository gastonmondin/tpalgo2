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

void Abb_raiz::borrar_ramas(Abb_hoja* h){
	if(!h)
		return;
	borrar_ramas(h->obtener_hoja_izq());
	borrar_ramas(h->obtener_hoja_der());
	h->cambiar_valor(0);
	delete h;
}

Abb_hoja* Abb_raiz::busco_padre(string clave){
	Abb_hoja* padre = raiz;
	Abb_hoja* hoja = raiz;
	bool encontrado = false;
	while(!encontrado){
		if(clave == hoja->obtener_clave())
			encontrado = true;
		else if(clave < hoja->obtener_clave()){
			padre = hoja;
			hoja = hoja->obtener_hoja_izq();
		}else{
			padre = hoja;
			hoja = hoja->obtener_hoja_der();
		}
	}
	return padre;
}

Abb_hoja* Abb_raiz::busco_predecesor(Abb_hoja* hoja){
	Abb_hoja* predecesor = hoja->obtener_hoja_izq();
	while(predecesor->obtener_hoja_der() != 0 && predecesor != 0){
		predecesor = predecesor->obtener_hoja_der();
	}
	if(predecesor != 0)
		return predecesor;
	return 0;
}

void Abb_raiz::eliminar(Abb_hoja* hoja, Abb_hoja* padre, string clave){

	//SIN HIJOS
	if(hoja->obtener_hoja_izq() == 0 && hoja->obtener_hoja_der() == 0){
		if(padre->obtener_hoja_izq() == hoja){
			padre->cambiar_hoja_izq(0);
		}else{
			padre->cambiar_hoja_der(0);
		}
		delete hoja;
	}
	// SOLO HIJO IZQUIERDO
	else if(hoja->obtener_hoja_izq() != 0 && hoja->obtener_hoja_der() == 0){
		Abb_hoja* predecesor = busco_predecesor(hoja);
		Abb_hoja* padre_predecesor = busco_padre(predecesor->obtener_clave());

		if(padre->obtener_hoja_izq() == hoja){
			padre->cambiar_hoja_izq(predecesor);
		}else{
			padre->cambiar_hoja_der(predecesor);
		}
		if(predecesor->obtener_hoja_izq() == 0){
			padre_predecesor->cambiar_hoja_der(0);
		}
		if(predecesor == hoja->obtener_hoja_izq())
			predecesor->cambiar_hoja_izq(0);
		else
			predecesor->cambiar_hoja_izq(hoja->obtener_hoja_izq());

		delete hoja;
	}
	// SOLO HIJO DERECHO
	else if(hoja->obtener_hoja_izq() == 0 && hoja->obtener_hoja_der() != 0){
		if(padre->obtener_hoja_izq() == hoja){
			padre->cambiar_hoja_izq(hoja->obtener_hoja_der());
		}else{
			padre->cambiar_hoja_der(hoja->obtener_hoja_der());
		}
		delete hoja;
	}
	// CON HIJOS IZQUIERDOS Y DERECHOS
	else{
		Abb_hoja* predecesor = busco_predecesor(hoja);
		Abb_hoja* padre_predecesor = busco_padre(predecesor->obtener_clave());
		if(raiz == hoja){
			raiz = predecesor;
		}else{
			if(padre->obtener_hoja_izq() == hoja){
				padre->cambiar_hoja_izq(predecesor);
			}else{
				padre->cambiar_hoja_der(predecesor);
			}
		}

		if(hoja->obtener_hoja_izq() == predecesor)
			padre_predecesor->cambiar_hoja_izq(0);
		if(hoja->obtener_hoja_der() == predecesor)
			padre_predecesor->cambiar_hoja_der(0);

		if(predecesor->obtener_hoja_izq() != 0){
			padre_predecesor->cambiar_hoja_der(predecesor->obtener_hoja_izq());
		}
		predecesor->cambiar_hoja_der(hoja->obtener_hoja_der());

		if(predecesor->obtener_hoja_izq() == 0)
			padre_predecesor->cambiar_hoja_der(0);
		predecesor->cambiar_hoja_izq(hoja->obtener_hoja_izq());

		delete hoja;
	}
}

void Abb_raiz::borrar_hoja(Abb_hoja* hoja, Abb_hoja* padre, string clave){
	if(!hoja){
		cout << "El personaje no se encuentra." << endl;
	}else if(clave == hoja->obtener_clave()){
		eliminar(hoja, padre, clave);
	}else if(clave < hoja->obtener_clave()){
		borrar_hoja(hoja->obtener_hoja_izq(), hoja, clave);
	}else{
		borrar_hoja(hoja->obtener_hoja_der(), hoja, clave);
	}
}

void Abb_raiz::eliminar_hoja(string clave){
	//Personaje* borrar = buscar(nombre);
	if(!raiz){
		cout << "El arbol esta vacio" << endl;
	}else if(clave == raiz->obtener_clave()){
		eliminar(raiz, raiz, clave);
	}else if(clave < raiz->obtener_clave()){
		borrar_hoja(raiz->obtener_hoja_izq(), raiz,clave);
	}else{
		borrar_hoja(raiz->obtener_hoja_der(), raiz,clave);
	}
}

Abb_raiz::~Abb_raiz(){
	if(raiz){
		borrar_ramas(raiz->obtener_hoja_izq());
		borrar_ramas(raiz->obtener_hoja_der());
		delete raiz;
	}
}
