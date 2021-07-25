#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include "Ficha.h"

using namespace std;

class Jugador {
	private:
		string nombre;
		Ficha ficha;
	public:
		// Constructor
		Jugador();
		
		// Setters y Getters
		void setNombre(string n);
		string getNombre();
		void setFicha(Ficha f);
		Ficha getFicha();
};

#endif

