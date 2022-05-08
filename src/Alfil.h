#pragma once
#include "Piezas.h"

class Alfil :private Pieza {

private:

public:
	void Dibuja();
	void mueve(Vector2D);

	Alfil(bool _color, int _x, int _y);

};
