#pragma once
#include "Piezas.h"

class Peon :public Pieza {

private:
	bool primerMov;
public:
	Peon(ColorPieza _color, int _x, int _y);
	~Peon() {};

	void Dibuja();
	bool movValido(int destX, int destY);
	bool getPrimerMov() { return primerMov; }
};
