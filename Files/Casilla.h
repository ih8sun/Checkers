#pragma once
#include "Ficha.h"
#include <string>
#include <windows.h>
using namespace std;

# define NE 1
# define NO 2
# define SO 3
# define SE 4
/*
	Cada casilla (correspondiente a un nodo).
	Vecinos:NE = 1, NO = 2, SO = 3, SE = 4;
*/

class Casilla {
private:
	Ficha *ficha;
	Casilla *vec_NE;
	Casilla *vec_NO;
	Casilla *vec_SO;
	Casilla *vec_SE;
	int posX, posY;
	
public:
	Casilla();
	Casilla(int, int);
	Casilla(Ficha *, Casilla *, Casilla *, Casilla *, Casilla *);
	Casilla(int, int, Ficha *, Casilla *, Casilla *, Casilla *, Casilla *);
	void setFicha(Ficha *);
	void setVecino(int, Casilla*);
	void setPos(int, int);
	Ficha * getFicha();
	Casilla * getVecino(int);
	string toString();
	int getPosX();
	int getPosY();
	int esMiVecino(Casilla*);
	~Casilla();
	static void colorText(int);
};

