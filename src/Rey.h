#pragma once
#include "Piezas.h"

class Rey :private Pieza {
private:

public:

	void Dibuja();
	void mueve(Vector2D);

	Rey(bool _color, int _x, int _y);

};
