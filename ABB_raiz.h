/*
 * ABB_raiz.h
 *
 *  Created on: 31 ene. 2021
 *      Author: esteban
 */

#ifndef ABB_RAIZ_H_
#define ABB_RAIZ_H_

#include "ABB_hoja.h"

class Abb_raiz{
private:
	Abb_hoja* raiz;

public:
	Abb_raiz();

	/*
	 POS: CARGARA AL ARBOL UN NUEVO PERSONAJE, POSICIONADOLO EN UNA RAMA INDICADA.
	 */
	void alta(string c, Personaje* d);
	/*
	 POS: MOSTRARA LOS DATOS DE TODAS LAS HOJAS DEL ARBOL.
	*/
	void mostrar_datos();
	/*
	 POS: DEVOLVERA EL DATO CORRESPONDIENTE AL TEXTO INGRESADO, CASO CONTRARIO RETORNARA 0.
	*/
	Personaje* buscar(string c);

	void eliminar_hoja(string clave);

	~Abb_raiz();

private:
	/*
	 POS: MUESTRA EL DATO (VALOR) DE LA HOJA INDICADA.
	*/
	void mostrar_valor(Abb_hoja* h);
	/*
	 POS: INGRESARA A TODAS LAS RAMAS (DERECHA O IZQUIERDA) INDICADAS.
	*/
	void mostrar_rama(Abb_hoja* h);
	/*
	 POS: ELIMINARA UNA HOJA INDICADA.
	*/
	void borrar_ramas(Abb_hoja* h);
	/*
	 POS: BUSCARA POR CLAVE UNA HOJA ESPECIFICA.
	*/
	Personaje* buscar_hoja(Abb_hoja* h, string c);
	/*
	 POS: CREARA UNA NUEVA HOJA EN UNA RAMA ESPECIFICA.
	*/
	void nuevo_hijo(Abb_hoja* &h, string c, Personaje* d);

	/*
	 BUSCARA UNA HOJA PARA REEMPLAZAR Y MANTENER LA ESTRUCTURA DEL ARBOL
	 */
	Abb_hoja* busco_predecesor(Abb_hoja* hoja);

	/*
	 DEVOLVERA LA HOJA PADRE A LA QUE SE DESEA BORRAR.
	 */
	Abb_hoja* busco_padre(string clave);

	/*
	 ELIMINA LA HOJA SELECCIONADA
	 */
	void eliminar(Abb_hoja* hoja, Abb_hoja* padre);
	/*
	 BUSCARA LA CLAVE EN EL ARBOL, SI SE ENCUENTRA BORRARA LA HOJA.
	 */
	void borrar_hoja(Abb_hoja* hoja, Abb_hoja* padre, string clave);
};



#endif /* ABB_RAIZ_H_ */
