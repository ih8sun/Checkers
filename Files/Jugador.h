#pragma once
#include <iostream>
#include "Ficha.h"
#include "Casilla.h"
using namespace std;

class Jugador {
private:
	int color, cantActivas;
	Ficha *fichas[12];
public:
	Jugador();
	Jugador(int);
	int getColor();
	Ficha * getFicha(int);
	int getCantActivas();
	bool perderFicha();
	bool yaPerdio();
	void mostrarFichas();
	~Jugador();
};

