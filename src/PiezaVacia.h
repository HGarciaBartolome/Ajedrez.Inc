#pragma once
#include "Piezas.h"

class PiezaVacia :public Pieza {
private:

public:
	PiezaVacia(ColorPieza _color, int _x, int _y);
	~PiezaVacia() {};

	bool movValido(int destX, int destY, ColorPieza c);
	void Dibuja();

};
