#include "Jugador.h"

Jugador::Jugador() {
	
}

void Jugador::setNombre(string n) {
	nombre = n;
}

string Jugador::getNombre() {
	return nombre;
}

void Jugador::setFicha(Ficha f) {
	ficha = f;
}

Ficha Jugador::getFicha() {
	return ficha;
}
