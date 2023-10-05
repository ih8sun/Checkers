#include "stdafx.h"
#include "Casilla.h"


Casilla::Casilla() {
	ficha	= NULL;
	vec_NE	= NULL;
	vec_NO	= NULL;
	vec_SO	= NULL;
	vec_SE	= NULL;
	posX = 0;
	posY = 0;
}

Casilla::Casilla(int x, int y) {
	ficha = NULL;
	vec_NE = NULL;
	vec_NO = NULL;
	vec_SO = NULL;
	vec_SE = NULL;
	posX = x;
	posY = y;
}

Casilla::Casilla(Ficha *f, Casilla* vNE, Casilla *vNO, Casilla *vSO, Casilla* vSE) {
	ficha = f;
	vec_NE = vNE;
	vec_NO = vNO;
	vec_SO = vSE;
	vec_SE = vSO;
	posX = 0;
	posY = 0;
}

Casilla::Casilla(int x, int y, Ficha *f, Casilla* vNE, Casilla *vNO, Casilla *vSO, Casilla* vSE) {
	ficha = f;
	vec_NE = vNE;
	vec_NO = vNO;
	vec_SO = vSE;
	vec_SE = vSO;
	posX = x;
	posY = y;
}

void Casilla::setFicha(Ficha *f) {
	ficha = f;
}

void Casilla::setVecino(int cual, Casilla *vec) {
	switch (cual) {
		case(NE): vec_NE = vec;
			break;
		case(NO): vec_NO = vec;
			break;
		case(SO): vec_SO = vec;
			break;
		case(SE): vec_SE = vec;
			break;
	}
}

void Casilla::setPos(int x, int y) {
	posX = x;
	posY = y;
}

Ficha * Casilla::getFicha() {
	return ficha;
}

Casilla * Casilla::getVecino(int cual) {
	switch (cual) {
		case(NE):  return vec_NE;
		case(NO):  return vec_NO;
		case(SO):  return vec_SO;
		case(SE):  return vec_SE;
	}
}

string Casilla::toString() {
	// Si la casilla esta vacia su ficha sera NULL
	return (ficha) ? ficha->toString(): "   ";
}

int Casilla::getPosX() {
	return posX;
}

int Casilla::getPosY() {
	return posY;
}

int Casilla::esMiVecino(Casilla *queSoy){
	if (queSoy == vec_NO) return NO;
	if (queSoy == vec_NE) return NE;
	if (queSoy == vec_SO) return SO;
	if (queSoy == vec_SE) return SE;
	else return -1;
}

void Casilla::colorText(int combo) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, combo);
}

Casilla::~Casilla()
{
}
