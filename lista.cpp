#include "lista.h"

Lista::Lista() {
    primero = 0;
    cantidad = 0;
}

bool Lista::vacia() {
    return (cantidad == 0);
}

void Lista::alta(Dato d, int pos) {
    Nodo* nuevo = new Nodo(d);
    if (pos == 1) {
        nuevo->cambiarSiguiente(primero);
        primero = nuevo;
    }
    else {
        Nodo* anterior = obtenerNodo(pos - 1);
        Nodo* siguiente = anterior->obtenerSiguiente();
        nuevo->cambiarSiguiente(siguiente);
        anterior->cambiarSiguiente(nuevo);
    }
    cantidad++;
}

Nodo* Lista::obtenerNodo(int pos) {
    Nodo* aux = primero;
    for(int i = 1; i < pos; i++)
        aux = aux->obtenerSiguiente();
    return aux;
}

Dato Lista::consulta(int pos) {
    Nodo* aux = obtenerNodo(pos);
    return aux->obtenerDato();
}

void Lista::baja(int pos) {
    Nodo* borrar;
    if (pos == 1) {
        borrar = primero;
        primero = borrar->obtenerSiguiente();
    }
    else {
        Nodo* anterior = obtenerNodo(pos - 1);
        borrar = anterior->obtenerSiguiente();
        Nodo* siguiente = borrar->obtenerSiguiente();
        anterior->cambiarSiguiente(siguiente);
    }
    delete borrar->obtenerDato();
    delete borrar;
    cantidad--;
}

Lista::~Lista() {
    while (! vacia())
        baja(1);
}

int Lista::obtenerCantidad() {
    return cantidad;
}

int Lista::obtenerPosicion(string nombre) {
	Nodo* aux = primero;
	int pos = 1;
	while ((aux->obtenerDato()->obtenerNombre() != nombre) && (pos < obtenerCantidad())) {
		pos++;
		aux = aux->obtenerSiguiente();
	}
	if (aux->obtenerDato()->obtenerNombre() != nombre)
		pos = 0;
	return pos;
}


