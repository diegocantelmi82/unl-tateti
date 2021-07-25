#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
#include "Ficha.h"

using namespace std;

class Tablero {
	private:
		Ficha tablero[3][3];
	public:
		// Para nombrar las posiciones del tablero en las indicaciones
		string posicionTablero[3][3] = {{"A1", "B1", "C1"}, {"A2", "B2", "C2"}, {"A3", "B3", "C3"}};
		
		// Se usa para hacer el match entre la teclada presionada por el usuario y las coordenadas del tablero
		int teclaCoordenada[9][2] = {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}};
		
		// Constructor
		Tablero();
		
		// Imprime el tablero
		void mostrar();
		
		// Coloca una ficha en las coordenadas indicadas
		void setFichaIn(int x, int y, Ficha f);
		
		// Nos indica si hay una ficha en esa posicion
		bool hayFicha(int x, int y);
		
		// Trae la ficha de la posicion dada
		Ficha getFicha(int x, int y);
};

#endif

