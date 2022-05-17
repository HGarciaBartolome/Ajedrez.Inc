#pragma once
#include "Piezas.h"

class Miguel :public Pieza {

public:
	Miguel(ColorPieza _color, int _x, int _y);
	~Miguel() {};

	void Dibuja();
	bool movValido(int destX, int destY, ColorPieza c);
};