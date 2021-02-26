/*
 * ABB_hoja.h
 *
 *  Created on: 31 ene. 2021
 *      Author: esteban
 */

#ifndef ABB_HOJA_H_
#define ABB_HOJA_H_

#include "personaje.h"

class Abb_hoja{
private:
	string clave;
	Personaje* valor;
	Abb_hoja* hoja_izq;
	Abb_hoja* hoja_der;
public:
	Abb_hoja(string c, Personaje* d);
	/*
	 POS: CAMBIARA EL VALOR DE LA HOJA POR EL RECIBIDO POR PARAMETRO.
	*/
	void cambiar_valor(Personaje* d);
	/*
	 POS: RETORNARA LA CLAVE DE LA HOJA.
	*/
	string obtener_clave();
	/*
	 POS: RETORNARA UN PUNTERO POR REFERENCIA DE LA HOJA IZQUIERDA.
	*/
	Abb_hoja* &obtener_hoja_izq();
	/*
	 POS: RETORNARA UN PUNTERO POR REFERENCIA DE LA HOJA DERECHA.
	*/
	Abb_hoja* &obtener_hoja_der();
	/*
	 POS: RETORNARA EL VALOR DE LA HOJA.
	*/
	Personaje* obtener_valor();

	void cambiar_hoja_izq(Abb_hoja* hoja);

	void cambiar_hoja_der(Abb_hoja* hoja);
};



#endif /* ABB_HOJA_H_ */
