#pragma once
#include "Piezas.h"

class Cristobal :public Pieza {

public:
	Cristobal(ColorPieza _color, int _x, int _y);
	~Cristobal() {};

	void Dibuja();
	bool movValido(int destX, int destY, ColorPieza c);
};
