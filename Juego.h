#ifndef JUEGO_H
#define JUEGO_H

#include <iostream>
#include "Tablero.h"
#include "Jugador.h"

using namespace std;

class Juego {
	private:
		// Flags que setean si estamos en partida actual y/o dentro del juego
		bool jugando = true;
		bool enPartida = true;
		
		// Jugador al que pertenece el turno actual
		Jugador turno;
		
		// Flag para indicar si un jugador gano la partida
		bool tateti = false;
		
		// Flag que indica si se termino de completar el tablero
		bool tableroCompleto = false;
		
		// Imprime textos del juego
		void mostrarCabeceras(Jugador j1, Jugador j2);
		void mostrarSeparador();
		void mostrarProximoTurno();
		
		// Reinicia partida o termina juego
		void nuevaPartida();
		
		// Setea a quien pertenece el proximo turno
		void proximoTurno(Jugador j1, Jugador j2);
		
		// Ejecuta el turno del jugador
		void ejecutarTurno(Tablero &t, Jugador jugador);
		
		// Valida que la tecla presionada por el usuario sea valida
		bool validarTecla(int tecla, Tablero t);
		
		// Convierte el char de la tecla del usuario al entero que representa en el tablero
		int keyToInt(int tecla);
		
		// Chequea si se logro hacer tateti
		void checkTateti(Tablero t);
		
		// Chequea si se completo el tablero con fichas
		void checkTableroCompleto(Tablero t);
		
		// Imprime el resultado final de la partida
		void imprimirResultadoFinal();
	public:
		// Constructor
		Juego();
		
		// Metodo que gestiona el juego
		void play();
		
		// Setters y Getters
		void setJugando(bool j);
		bool getJugando();
		void setEnPartida(bool e);
		bool getEnPartida();
		void setTurno(Jugador j);
		Jugador getTurno();
		void setTateti(bool e);
		bool getTateti();
		void setTableroCompleto(bool e);
		bool getTableroCompleto();
};

#endif

