#pragma once
#define _WIN32_WINNT 0x500

#include <Windows.h>
#include <iostream>
#include <sstream>
#include "Partida.h"
using namespace std;

class Juego {
private:
	Partida *partida;
public:
	Juego();
	void bienvenida();
	void menuPrincipal();
	void iniciarPartida();
	void retirarse(int);
	bool jugarTurnoDe(int);
	void showInfo();
	void salir();
	~Juego();
	static void resizeConsole();
};
