#pragma once
#include "Piezas.h"

class Rey :public Pieza {
private:
	bool primerMov;
public:
	Rey(ColorPieza _color, int _x, int _y);
	~Rey() {};

	void Dibuja();
	bool movValido(int destX, int destY);
	bool getPrimerMov() { return primerMov; }

};
