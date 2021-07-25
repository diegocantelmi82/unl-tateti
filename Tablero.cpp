#include "Tablero.h"

Tablero::Tablero() {
	
}

void Tablero::mostrar() {
	cout << "    " << " A  " << " B  " << " C " << endl;
	cout << "   " << "=============" << endl;
	
	for(int i=0; i<3; i++) {
		cout << " " << i+1 << " | ";
		
		for(int j=0; j<3; j++) {
			cout << tablero[i][j].getTipo() << " | ";
		}
		
		cout << endl << "   -------------" << endl;
	}
	
	cout << endl;
}

void Tablero::setFichaIn(int x, int y, Ficha f) {
	if(!hayFicha(x, y)) {
		tablero[x][y] = f;
	}
}

bool Tablero::hayFicha(int x, int y) {
	if(tablero[x][y].getTipo() == ' ') {
		return false;
	}
	return true;
}

Ficha Tablero::getFicha(int x, int y) {
	return tablero[x][y];
}
