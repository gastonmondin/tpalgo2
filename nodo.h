#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include "fuego.h"
#include "agua.h"
#include "tierra.h"
#include "aire.h"

typedef Personaje* Dato;

class Nodo {
private:
    // Atributos
    Dato dato;
    Nodo* siguiente;

public:
    // Metodos
    
    // Constructor
    // POS: Crea un nodo con dato = d y siguiente = 0.
    Nodo(Dato d);

    void cambiarDato(Dato d);

    void cambiarSiguiente(Nodo* s);

    Dato obtenerDato();

    Nodo* obtenerSiguiente();
};

#endif
