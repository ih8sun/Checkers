#include "stdafx.h"
#include "Partida.h"


Partida::Partida()
	:tabla(new Tablero()), JNegro(new Jugador(NEGRO)), JBlanco(new Jugador(BLANCO)) {
	preparaDisplay();
	colocacionInicialDeFichas();
}


Partida::~Partida()
{
}

Jugador * Partida::getJNegro()
{
	return JNegro;
}

Jugador * Partida::getJBlanco()
{
	return JBlanco;
}

bool Partida::colocarFichaEn(int x, int y, Ficha* ficha) {
	Casilla* setEn = tabla->buscaUnaCasilla(x, y);
	if (setEn == NULL)
		return false;
	else {
		setEn->setFicha(ficha);
		// Ajuste para mostrar en display.
		if (ficha) Display[2 * x + 1][2 * y + 1] = setEn->getFicha()->toString();
		else Display[2 * x + 1][2 * y + 1] = "   ";
	}
}

// Este m�todo es meramente est�tica, para el Display.
void Partida::preparaDisplay() {
	for (int i = 0; i < 17; i++) {
		for (int j = 0; j < 17; j++) {
			// ------- cruzados ----------------------------------
			if (i % 2 == 0 && j % 2 == 1) Display[i][j] = "\xCD\xCD\xCD";
			if (i % 2 == 0 && j % 2 == 0) Display[i][j] = "\xCE";
			if (i % 2 == 1 && j % 2 == 0) Display[i][j] = "\xBA";
			// ------- casillas blancas (que no jeugan) ----------
			if (i % 2 == 1 && j % 2 == 1 && tabla->buscaUnaCasilla(((i - 1) / 2), (j - 1) / 2)) Display[i][j] = "   ";
			if (i % 2 == 1 && j % 2 == 1 && tabla->buscaUnaCasilla(((i - 1) / 2), (j - 1) / 2) == nullptr) Display[i][j] = "\xB0\xB0\xB0";
			//--------------- laterales (izq, der) ---------------
			if (j == 0 && i % 2 == 0) Display[i][j] = "\xCC";
			if (j == 16 && i % 2 == 0) Display[i][j] = "\xB9";
			// -------------- laterales (sup, inf) ---------------
			if (i == 0 && j % 2 == 0) Display[i][j] = "\xCB";
			if (i == 16 && j % 2 == 0) Display[i][j] = "\xCA";
			//----------------- Esquinas -------------------------
			if (i == 0 && j == 0) Display[i][j] = "\xC9";
			if (i == 0 && j == 16) Display[i][j] = "\xBB";
			if (i == 16 && j == 0) Display[i][j] = "\xC8";
			if (i == 16 && j == 16) Display[i][j] = "\xBC";
			//---------------- Espacios vacios ------------------
		}
	}
}

Tablero * Partida::getTabla(){
	return this->tabla;
}

void Partida::mostrarDisplay() {
	system("cls");
	cout << "\n\n\t    0   1   2   3   4   5   6   7";
	for (int i = 0, cols = 0; i < 17; i++) {
		cout << "\n\t";
		if (i % 2 == 1) {
			cout << cols << " ";
			cols++;
		}
		else cout << "  ";
		for (int j = 0; j < 17; j++) {
			if (Display[i][j] == " \x01 " || Display[i][j] == " \x05 ") Casilla::colorText(10);
			if (Display[i][j] == " \x02 " || Display[i][j] == " \x06 ") Casilla::colorText(14);
			if (Display[i][j] == "\xB0\xB0\xB0") Casilla::colorText(7);
			cout << Display[i][j];
			Casilla::colorText(7);
		}
	}
}

void Partida::colocacionInicialDeFichas() {
	int index = 0; // index es para ir "vaciando" las fichas[12] de cada jugador
	// Inicia con las fichas del JNegro (Arriba)
	for (int i = 0; i < 3; i++) {
		if (i % 2 == 0) {
			colocarFichaEn(i, 0, JNegro->getFicha(index++));
			colocarFichaEn(i, 2, JNegro->getFicha(index++));
			colocarFichaEn(i, 4, JNegro->getFicha(index++));
			colocarFichaEn(i, 6, JNegro->getFicha(index++));
		}
		else {
			colocarFichaEn(i, 1, JNegro->getFicha(index++));
			colocarFichaEn(i, 3, JNegro->getFicha(index++));
			colocarFichaEn(i, 5, JNegro->getFicha(index++));
			colocarFichaEn(i, 7, JNegro->getFicha(index++));
		}
	}
	index = 0;
	for (int i = 5; i < 8; i++) {
		if (i % 2 == 0) {
			colocarFichaEn(i, 0, JBlanco->getFicha(index++));
			colocarFichaEn(i, 2, JBlanco->getFicha(index++));
			colocarFichaEn(i, 4, JBlanco->getFicha(index++));
			colocarFichaEn(i, 6, JBlanco->getFicha(index++));
		}
		else {
			colocarFichaEn(i, 1, JBlanco->getFicha(index++));
			colocarFichaEn(i, 3, JBlanco->getFicha(index++));
			colocarFichaEn(i, 5, JBlanco->getFicha(index++));
			colocarFichaEn(i, 7, JBlanco->getFicha(index++));
		}
	}
}

bool Partida::hacerMovimiento(int x_orig, int y_orig, int direccion, int jugador) {
	if ((x_orig + y_orig) % 2 == 1)
		return false; // Si la suma de las coordenadas es impar, la casilla es invalida.
	Casilla *cOrigen = tabla->buscaUnaCasilla(x_orig, y_orig);
	if (cOrigen->getFicha()->getColor() != jugador) // Ficha a mover no le pertenece al jugador. 
		return false;
	if (cOrigen && cOrigen->getFicha()) {
		Casilla *cDestino = cOrigen->getVecino(direccion);
		Ficha *fOrigen = cOrigen->getFicha();
		Ficha *fDestino = cDestino->getFicha();
		if (fDestino == nullptr) { // Casilla destino esta vacia
			if (fOrigen->getColor() == BLANCO) {
				if (!fOrigen->getCorona() && (direccion == NO || direccion == NE) || fOrigen->getCorona()) {
					colocarFichaEn(cDestino->getPosX(), cDestino->getPosY(), fOrigen);
					colocarFichaEn(cOrigen->getPosX(), cOrigen->getPosY(), nullptr);
					esReina(cDestino);
					return true;
				}
			}
			if (fOrigen->getColor() == NEGRO) {
				if (!fOrigen->getCorona() && (direccion == SO || direccion == SE) || fOrigen->getCorona()) {
					colocarFichaEn(cDestino->getPosX(), cDestino->getPosY(), fOrigen);
					colocarFichaEn(cOrigen->getPosX(), cOrigen->getPosY(), nullptr);
					esReina(cDestino);
					return true;
				}
			}
		}
		else { // Si la casilla destino tiene alguna ficha
			if ((fOrigen->getColor() != fDestino->getColor()) && cDestino->getVecino(direccion) && cDestino->getVecino(direccion)->getFicha() == nullptr) { // Se lo puede comer.
				if (fOrigen->getColor() == BLANCO) {
					if (!fOrigen->getCorona() && (direccion == NO || direccion == NE) || fOrigen->getCorona()) {
						// Se lo moncha
						colocarFichaEn(cDestino->getVecino(direccion)->getPosX(), cDestino->getVecino(direccion)->getPosY(), fOrigen);
						colocarFichaEn(cOrigen->getPosX(), cOrigen->getPosY(), nullptr);
						colocarFichaEn(cDestino->getPosX(), cDestino->getPosY(), nullptr);
						JNegro->perderFicha();
						cOrigen = cDestino->getVecino(direccion);
						cDestino = cOrigen->getVecino(direccion);
						while (cDestino && cDestino->getVecino(direccion) && cDestino->getFicha() && cDestino->getVecino(direccion)->getFicha() == nullptr) {
							//si el siguiente tiene ficha y el que le sigue al siguiente no tiene ficha
						//coma

							colocarFichaEn(cDestino->getVecino(direccion)->getPosX(), cDestino->getVecino(direccion)->getPosY(), cOrigen->getFicha());
							colocarFichaEn(cOrigen->getPosX(), cOrigen->getPosY(), nullptr);
							colocarFichaEn(cDestino->getPosX(), cDestino->getPosY(), nullptr);
							cOrigen = cDestino->getVecino(direccion);
							cDestino = cOrigen->getVecino(direccion);
							JNegro->perderFicha();

							if (cDestino == nullptr)break;

						}
						esReina(cOrigen);
						return true;
					}
				}
				if (fOrigen->getColor() == NEGRO) {
					if (!fOrigen->getCorona() && (direccion == SO || direccion == SE) || fOrigen->getCorona()) {
						colocarFichaEn(cDestino->getVecino(direccion)->getPosX(), cDestino->getVecino(direccion)->getPosY(), fOrigen);
						colocarFichaEn(cOrigen->getPosX(), cOrigen->getPosY(), nullptr);
						colocarFichaEn(cDestino->getPosX(), cDestino->getPosY(), nullptr);
						JBlanco->perderFicha();
						cOrigen = cDestino->getVecino(direccion);
						cDestino = cOrigen->getVecino(direccion);

						while (cDestino && cDestino->getFicha() && cDestino->getVecino(direccion) && cDestino->getVecino(direccion)->getFicha() == nullptr) {
							//si el siguiente tiene ficha y el que le sigue al siguiente no tiene ficha//coma

							colocarFichaEn(cDestino->getVecino(direccion)->getPosX(), cDestino->getVecino(direccion)->getPosY(), cOrigen->getFicha());
							colocarFichaEn(cOrigen->getPosX(), cOrigen->getPosY(), nullptr);
							colocarFichaEn(cDestino->getPosX(), cDestino->getPosY(), nullptr);
							cOrigen = cDestino->getVecino(direccion);
							cDestino = cOrigen->getVecino(direccion);
							JBlanco->perderFicha();

							if (cDestino == nullptr)break;
						}
						esReina(cOrigen);
						return true;
					}
				}
			}
			else return false; //Ficha de origen y destino son del mismo color || casilla despues de cDestino esta ocupada
		}
	}
	else return false; // Casilla de origen vacia
}

bool Partida::seTermino() {
	return JBlanco->yaPerdio() || JNegro->yaPerdio();
}

bool Partida::esReina(Casilla* ficha){
	if (ficha->getFicha()->getColor() == BLANCO && ficha->getPosX() == 0)
		ficha->getFicha()->setCorona(true);
	if (ficha->getFicha()->getColor() == NEGRO && ficha->getPosX() == 7)
		ficha->getFicha()->setCorona(true);
	colocarFichaEn(ficha->getPosX(), ficha->getPosY(), ficha->getFicha());
	return true;
}
