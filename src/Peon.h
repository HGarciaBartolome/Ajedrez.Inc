#pragma once
#include "Piezas.h"

class Peon :private Pieza {

private:

public:
	void Dibuja();
	void mueve(Vector2D);
	Peon(bool _color, float _x, float _y);
};
