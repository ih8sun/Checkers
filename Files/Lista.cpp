#include "stdafx.h"
#include "Lista.h"


Lista::Lista():pPio(NULL), pLista(NULL), sentido(NOSE){}

Lista::Lista(int dir) : pPio(NULL), pLista(NULL), sentido(dir) {}

Lista::~Lista(){}

void Lista::irAPrimero() {
	pLista = pPio;
}

void Lista::alSiguiente() {
	(sentido == NOSE && pLista) ? pLista = pLista->getVecino(SE) : pLista = pLista->getVecino(NE);
}

void Lista::irAUltimo() {
	if(sentido ==  NOSE)
		while (pLista->getVecino(SE))
			alSiguiente();
	else
		while (pLista->getVecino(NE))
			alSiguiente();
}

void Lista::InsertarFinal(Casilla *C){
	irAPrimero();
	if (ListaVacia())
		pPio = pLista = C;
	else {
		irAUltimo();
		if (sentido == NOSE) {
			pLista->setVecino(SE, C);
			C->setVecino(NO, pLista);
		} else {
			pLista->setVecino(NE, C);
			C->setVecino(SO, pLista);
		}
	}
}

void Lista::InsertarAntes(Casilla *C){
	irAPrimero();
	if (ListaVacia())
		pPio = pLista = C;
	else {
		if (sentido == NOSE) {
			C->setVecino(SE, pPio);
			pPio->setVecino(NO, C);			
		} else {
			C->setVecino(NE, pPio);
			pPio->setVecino(SO, C);
		}
		pPio = C;
	}
}

void Lista::Vaciar(Casilla *C){
	irAPrimero();
	while (pLista->getVecino(SE) || pLista->getVecino(NE)) {
		if (pLista->getPosX() == C->getPosX() && pLista->getPosY() == C->getPosY())
			pLista->setFicha(NULL);
		alSiguiente();
	}
}

bool Lista::ListaVacia(){
	return pLista == NULL;
}

void Lista::Mostrar(){
	irAPrimero();
	while (pLista) {
		if (pLista->getPosX() == pLista->getPosY())
			Casilla::colorText(12);
		cout << "{" << pLista->getPosX() << ", " << pLista->getPosY() << "}->";
		Casilla::colorText(7);
		alSiguiente();
	}
}

Casilla* Lista::buscarCasilla(int x, int y){
	irAPrimero();
	while (pLista) {
		if (pLista->getPosX() == x && pLista->getPosY() == y)
			return pLista;
		alSiguiente();
	}
	return NULL;
}

Casilla* Lista::getPPio() {
	return pPio;
}

Casilla* Lista::getPLista() {
	return pLista;
}

int Lista::getSentido() {
	return sentido;
}