#include "stdafx.h"
#include "Ficha.h"


Ficha::Ficha(){
	color = NEGRO;
	corona = false;
}

Ficha::Ficha(int c):color(c), corona(false) {}

Ficha::Ficha(int col, bool cor) {
	color = col;
	corona = cor;
}

void Ficha::setColor(int col) {
	color = col;
}

void Ficha::setCorona(bool cor) {
	corona = cor;
}

int Ficha::getColor() {
	return color;
}

bool Ficha::getCorona() {
	return corona;
}

string Ficha::toString() {
	if (corona && color == BLANCO) return " \x05 ";
	if (corona && color == NEGRO) return " \x06 ";
	if (color == BLANCO) return " \x01 ";
	if (color == NEGRO) return " \x02 ";
	// NEGRO 02, 06 BLANCO 01, 05
}

Ficha::~Ficha()
{
}
