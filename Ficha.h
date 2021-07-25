#ifndef FICHA_H
#define FICHA_H

class Ficha {
	private:
		char tipo = ' ';
	public:
		// Constructor
		Ficha();
		
		// Setters y Getters
		void setTipo(char c);
		char getTipo();
};

#endif

