#include "Juego.h"
#include <conio2.h>

Juego::Juego() {
	
}

void Juego::play() {
	Ficha F1;
	F1.setTipo('X');
	Jugador J1;
	J1.setNombre("Jugador 1");
	J1.setFicha(F1);
	
	Ficha F2;
	F2.setTipo('O');
	Jugador J2;
	J2.setNombre("Jugador 2");
	J2.setFicha(F2);
	
	mostrarCabeceras(J1, J2);
	
	while(getJugando()) {
		Tablero T;
		setTurno(J1);
		
		while(getEnPartida()) {
			mostrarProximoTurno();
			T.mostrar();
			ejecutarTurno(T, getTurno());
			T.mostrar();
			checkTateti(T);
			checkTableroCompleto(T);
			
			if(getTateti() || getTableroCompleto()) {
				mostrarSeparador();
				imprimirResultadoFinal();
				mostrarSeparador();
				setEnPartida(false);
			} else {
				proximoTurno(J1, J2);
			}
		}
		
		nuevaPartida();
	}
	
	cout << endl << endl << "Gracias por jugar!" << endl;
}

void Juego::mostrarCabeceras(Jugador j1, Jugador j2) {
	mostrarSeparador();
	cout << "*** Ta-Te-Ti ***" << endl;
	cout << j1.getNombre() << " " << j1.getFicha().getTipo() << endl;
	cout << j2.getNombre() << " " << j2.getFicha().getTipo() << endl;
	mostrarSeparador();
}

void Juego::mostrarSeparador() {
	cout << "============================" << endl;
}

void Juego::mostrarProximoTurno() {
	cout << "Turno " << getTurno().getNombre() << " (" << getTurno().getFicha().getTipo() << ")" << endl << endl; 
}

void Juego::setJugando(bool j) {
	jugando = j;
}

bool Juego::getJugando() {
	return jugando;
}

void Juego::setEnPartida(bool e) {
	enPartida = e;
}

bool Juego::getEnPartida() {
	return enPartida;
}

void Juego::setTurno(Jugador j) {
	turno = j;
}

Jugador Juego::getTurno() {
	return turno;
}

void Juego::setTateti(bool e) {
	tateti= e;
}

bool Juego::getTateti() {
	return tateti;
}

void Juego::setTableroCompleto(bool e) {
	tableroCompleto = e;
}

bool Juego::getTableroCompleto() {
	return tableroCompleto;
}

void Juego::nuevaPartida() {
	cout << endl << "Desea jugar otra partida? (S = si - N = no)" << endl << endl;
	int accion;
	do {
		accion = getch();
	} while(accion != 'S' && accion != 's' && accion != 'N' && accion != 'n');
	
	if(accion == 'N' || accion == 'n') {
		// Terminamos partida
		setJugando(false);
	} else {
		// Reiniciamos las variables necesarias
		setEnPartida(true);
		setTateti(false);
		setTableroCompleto(false);
	}
}

void Juego::proximoTurno(Jugador j1, Jugador j2) {
	if(getTurno().getNombre() == j1.getNombre()) {
		setTurno(j2);
	} else {
		setTurno(j1);
	}
}

void Juego::ejecutarTurno(Tablero &t, Jugador jugador) {
	int k = 1;
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			if(!t.hayFicha(i, j)) {
				cout << t.posicionTablero[i][j] << " presiona " << k << endl;
			}
			k++;
		}
	}
	
	cout << endl << "Elige una opción: " << endl << endl;
	int accion;
	do {
		accion = getch();
		accion = keyToInt(accion);
	} while(!validarTecla(accion, t));
	
	t.setFichaIn(t.teclaCoordenada[accion-1][0], t.teclaCoordenada[accion-1][1], jugador.getFicha());
}

bool Juego::validarTecla(int tecla, Tablero t) {
	if(!tecla) {
		return false;
	}
	
	tecla = tecla - 1;
	if(t.hayFicha(t.teclaCoordenada[tecla][0], t.teclaCoordenada[tecla][1])) {
		return false;
	}
	
	return true;
}

int Juego::keyToInt(int tecla) {
	switch(tecla) {
		case '1':
			tecla = 1;
			break;
		case '2':
			tecla = 2;
			break;
		case '3':
			tecla = 3;
			break;
		case '4':
			tecla = 4;
			break;
		case '5':
			tecla = 5;
			break;
		case '6':
			tecla = 6;
			break;
		case '7':
			tecla = 7;
			break;
		case '8':
			tecla = 8;
			break;
		case '9':
			tecla = 9;
			break;
		default:
			tecla = 0;
			break;
	}
	
	return tecla;
}

void Juego::checkTateti(Tablero t) {
	char fichas[9];
	int k = 0;
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			fichas[k] = t.getFicha(i, j).getTipo();
			k++;
		}
	}
	
	if(fichas[0] == fichas[1] && fichas[1] == fichas[2] && fichas[0] != ' ') {
		setTateti(true);
	} else if(fichas[3] == fichas[4] && fichas[4] == fichas[5] && fichas[3] != ' ') {
		setTateti(true);
	} else if(fichas[6] == fichas[7] && fichas[7] == fichas[8] && fichas[6] != ' ') {
		setTateti(true);
	} else if(fichas[0] == fichas[3] && fichas[3] == fichas[6] && fichas[0] != ' ') {
		setTateti(true);
	} else if(fichas[1] == fichas[4] && fichas[4] == fichas[7] && fichas[1] != ' ') {
		setTateti(true);
	} else if(fichas[2] == fichas[5] && fichas[5] == fichas[8] && fichas[2] != ' ') {
		setTateti(true);
	} else if(fichas[0] == fichas[4] && fichas[4] == fichas[8] && fichas[0] != ' ') {
		setTateti(true);
	} else if(fichas[2] == fichas[4] && fichas[4] == fichas[6] && fichas[2] != ' ') {
		setTateti(true);
	}
}

void Juego::checkTableroCompleto(Tablero t) {
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			if(t.getFicha(i, j).getTipo() == ' ') {
				return;
			}
		}
	}
	
	setTableroCompleto(true);
}

void Juego::imprimirResultadoFinal() {
	if(getTateti()) {
		cout << "Ganador: " << getTurno().getNombre() << endl;
	} else {
		cout << "Empate!" << endl;
	}
}
