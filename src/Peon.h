#pragma once
#include "Piezas.h"

class Peon :public Pieza {

private:

public:
	Peon(bool _color, int _x, int _y);
	~Peon() {};

	void Dibuja();
	void mueve(Vector2D);

};
