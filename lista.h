#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"

class Lista {
private:
    // Atributos
    Nodo* primero;
    int cantidad;

	// Metodos

public:
    // Constructor
    // POS: crea una cola vacia
    Lista();

    // PRE: 0 < pos <= cantidad + 1.
    // POS: Inserta el dato d en la posicion pos, la 1 es la primera,
    // ademas incrementa cantidad en 1.
    void alta(Dato d, int pos);

    // PRE: 0 < pos <= cantidad.
    // POS: Saca el elemento que esta en pos.
    void baja(int pos);

    // PRE: 0 < pos <= cantidad
    // POS: Devuelve el elemento que esta en pos.
    Dato consulta(int pos);

    bool vacia();

    // POS: Libera la memoria.
    virtual ~Lista();

    int obtenerCantidad();
	
	// POS: Devuelve la posicion del elemento si encuentra el nombre,
	// si no devuelve 0.
	int obtenerPosicion(string);

private:
    Nodo* obtenerNodo(int pos);
};

#endif
