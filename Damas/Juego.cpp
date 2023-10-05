#include "stdafx.h"
#include "Juego.h"
#undef max

Juego::Juego(): partida(new Partida()){
	partida  = nullptr;
}

void Juego::bienvenida() {
	//resizeConsole();
	stringstream s, sub;
	s	<< "\n .----------------.  .----------------.  .----------------.  .----------------.  .----------------. "
		<< "\n| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |"
		<< "\n| |  ________    | || |      __      | || | ____    ____ | || |      __      | || |    _______   | |"
		<< "\n| | |_   ___ `.  | || |     /  \\     | || ||_   \\  /   _|| || |     /  \\     | || |   /  ___  |  | |"
		<< "\n| |   | |   `. \\ | || |    / /\\ \\    | || |  |   \\/   |  | || |    / /\\ \\    | || |  |  (__ \\_|  | |"
		<< "\n| |   | |    | | | || |   / ____ \\   | || |  | |\\  /| |  | || |   / ____ \\   | || |   '.___`-.   | |"
		<< "\n| |  _| |___.' / | || | _/ /    \\ \\_ | || | _| |_\\/_| |_ | || | _/ /    \\ \\_ | || |  |`\\____) |  | |"
		<< "\n| | |________.'  | || ||____|  |____|| || ||_____||_____|| || ||____|  |____|| || |  |_______.'  | |"
		<< "\n| |              | || |              | || |              | || |              | || |              | |"
		<< "\n| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |"
		<< "\n '----------------'  '----------------'  '----------------'  '----------------'  '----------------' ";
	sub << "\n"
		<< "\n\t\t_____  ______   ______   _        ______  ______   ______   ______  "
		<< "\n\t\t | |  | |  \\ \\ | | ____ | |      | |     / |      | |  | | / |      "
		<< "\n\t\t | |  | |  | | | |  | | | |   _  | |---- '------. | |__| | '------. "
		<< "\n\t\t_|_|_ |_|  |_| |_|__|_| |_|__|_| |_|____  ____|_/ |_|  |_|  ____|_/";
	Casilla::colorText(14);
	cout << s.str() << sub.str();
	Casilla::colorText(7);
	cout << "\n\n\n\n\t\t\t\tPRESIONE Enter \x10 PARA EMPEZAR";
	cin.get();
	
	menuPrincipal();
}

void Juego::menuPrincipal() {
	stringstream s, sub;
	system("cls");
	s << "\n\t\t\t .-. .-. .  . .-. .-. "
		<< "\n\t\t\t |  )|-| |\\/| |-| `-. "
		<< "\n\t\t\t `-' ` ' '  ` ` ' `-' ";
	sub	<< "\n\n\t  __  __                ___     _         _            _"
		<< "\n\t |  \\/  |___ _ _ _  _  | _ \\_ _(_)_ _  __(_)_ __  __ _| |"
		<< "\n\t | |\\/| / -_) ' \\ || | |  _/ '_| | ' \\/ _| | '_ \\/ _` | |"
		<< "\n\t |_|  |_\\___|_||_\\_,_| |_| |_| |_|_||_\\__|_| .__/\\__,_|_|"
		<< "\n\t                                           |_|           "
		<< "\n";
	
	cout << s.str();
	Casilla::colorText(10);
	cout << sub.str();
	Casilla::colorText(7);
	cout << "\n\n\t\t\t 1. Jugar\n\n\t\t\t 2. Informaci\xA2n   \n\n\t\t\t 3. Salir ";
	int option;
	while (true) {
		cout << "\n\n\n\t\tSeleccione una opci\xA2n.... ";
		cin >> option;
		if ((option >= 1) && (option <= 3)) 
			break;
		cout << "Error, intente de nuevo.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	switch (option) {
		case(1):iniciarPartida(); break;
		case(2): showInfo(); break;
		case(3):salir(); break;
	}
}

void Juego::showInfo() {
	system("cls");
	Casilla::colorText(11);
	cout << "\n\t\t\t_ _  _ ____ ____ ____ _  _ ____ ____ _ ____ _  _ ";
	cout << "\n\t\t\t| |\\ | |___ |  | |__/ |\\/| |__| |    | |  | |\\ |";
	cout << "\n\t\t\t| | \\| |    |__| |  \\ |  | |  | |___ | |__| | \\|";
	Casilla::colorText(7);
	cout << "\n\n\t\t Estructuras de Datos - Alex Santiago";
	cout << "\n\n\tSobre el juego:";
	cout << "\n\n\t\t Es es un juego de Damas Inglesas en CLI para 2 jugadores. El usuario ";
	cout << "\n\t es capaz de realizar todos los movimientos normales de un juego de damas,";
	cout << "\n\t  y el desplazamiento sobre el tablero utlizando la matriz de display.";
	cout << "\n\t\t La estructura subyacente para la implementaci\xA2n de este juego es una matriz";
	cout << "\n\t de casillas elaborada utilizando listas cuadruplemente enlazadas.";
	/*cout << "\n\n\n\tAutores:";
	cout << "\n\t\t ";*/
	cout << "\n\n\t";
	system("Pause");
	menuPrincipal();
}

void Juego::salir() {
	exit(0);
}

Juego::~Juego()
{
}

void Juego::resizeConsole() {
	// Get a handle to the current console screen buffer
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX cfi = { sizeof(cfi) };
	// Populate cfi with the screen buffer's current font info
	GetCurrentConsoleFontEx(hConsole, FALSE, &cfi);
	// Modify the font size in cfi
	cfi.dwFontSize.X *= 2;
	cfi.dwFontSize.Y *= 2;
	// Use cfi to set the screen buffer's new font
	SetCurrentConsoleFontEx(hConsole, FALSE, &cfi);
}

void Juego::iniciarPartida() {
	system("cls");
	partida = new Partida();
	while (!partida->seTermino()) {
		while (!jugarTurnoDe(BLANCO));
		while (!jugarTurnoDe(NEGRO));
	}
	cout << "\n\n\tJUEGO TERMINADO!!!\n";
	system("pause");
	menuPrincipal();
}

void Juego::retirarse(int jugador){
	Casilla::colorText(15);
	cout << "\n\tEL JUGADOR  ";
	if (jugador == NEGRO) {
		Casilla::colorText(14);
		cout << "NEGRO";
	} else {
		Casilla::colorText(10);
		cout << "BLANCO";
	}
	Casilla::colorText(15);
	cout << "  DECIDI\xE0 RETIRARSE! \n\n";
	Casilla::colorText(7);
	system("pause");
	menuPrincipal();
}

bool Juego::jugarTurnoDe(int jugador) {
	partida->mostrarDisplay();
	cout << endl;
	partida->getJBlanco()->mostrarFichas();
	partida->getJNegro()->mostrarFichas();
	int posx = -1, posy = -1, dir = -1;
	while (true) {
		cout << "\n\xC4 \xC4 \xC4 \xC4 \xC4 \xC4 \xC4 \xC4 \xC4 \xC4 \xC4 \xC4 \xC4 \xC4 ";
		Casilla::colorText(6);
		cout << "\n** Para retirarse, ingrese un (-1) en \"Fila\" **\n";
		Casilla::colorText(7);
		cout << "\n\tTurno de ";
		if (jugador == BLANCO) {
			Casilla::colorText(10);
			cout << " BLANCO";
		}
		else {
			Casilla::colorText(14);
			cout << " NEGRO";
		}
		Casilla::colorText(7);
		cout << "\n\nMover ficha en:\n    Fila:    ";
		cin >> posx;
		if (posx < 0) retirarse(jugador);
		cout << "    Columna: ";
		cin >> posy;
		cout << "    En direccion? (NE=1, NO=2, SO=3, SE=4)  ";
		cin >> dir;
		if (posx <= 7 && posx >= 0 && posy <= 7 && posy >= 0 && dir <= 4 && dir >= 1) {
			if (partida->hacerMovimiento(posx, posy, dir, jugador))
				return true;
			else {
				Casilla::colorText(12);
				cout << "\tMovimiento inv\xA0lido!!!\n\n";
				Casilla::colorText(7);
				system("pause");
				return false;
			}
		}
		else {
			Casilla::colorText(12);
			cout << "\n\tError, intente de nuevo.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			Casilla::colorText(7);
		}
	}
}

