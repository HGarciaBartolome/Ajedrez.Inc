#pragma once
#include "Piezas.h"

class Rey :public Pieza {
private:
	bool primerMov;

public:
	Rey() {};
	Rey(bool _color, int _x, int _y);
	~Rey() {};

	void Dibuja();
	bool movValido(int destX, int destY);
	char tipoPieza();
	bool getPrimerMov() { return primerMov; }

};
