#pragma once
#include "Piezas.h"

class Reina :private Pieza {

private:

public:
	void Dibuja();
	void mueve(Vector2D);
	Reina(bool _color, float _x, float _y);
};
