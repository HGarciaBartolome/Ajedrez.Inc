#pragma once
#include "Piezas.h"

class Pablo :public Pieza {

public:
	Pablo(ColorPieza _color, int _x, int _y);
	~Pablo() {};

	void Dibuja();
	bool movValido(int destX, int destY, ColorPieza c);
};
