#include "Casilla.h"
#include <iostream>
using namespace std;
/*
	Las listas se unen mediante un doble enlace con cada uno de sus vecinos [NO, NE, SO, SE].

	pPio: Puntero que se fija al principio de la lista.
	pLista: Puntero movible que se desplaza a lo largo de la lista.
	sentido: Sentido del desplazamiento en la lista.

	Convención:
	Sea #1 ir en sentido NO->SE. 
	Sea #2 ir en sentido SO->NE.
*/
# define NOSE 1
# define SONE 2

class Lista {
private:
	Casilla* pLista;
	Casilla* pPio;
	int sentido;
public:
	Lista();
	Lista(int);
	~Lista();
	void irAPrimero();
	void alSiguiente();
	void irAUltimo();
	void InsertarFinal(Casilla*);//Final
	void InsertarAntes(Casilla*);//Antes
	void Vaciar(Casilla*);
	bool ListaVacia();
	void Mostrar();
	Casilla* buscarCasilla(int, int);
	Casilla* getPLista();
	Casilla* getPPio();
	int getSentido();
};

