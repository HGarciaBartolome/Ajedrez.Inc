#pragma once
#include "Piezas.h"

class Reina :public Pieza {

private:

public:
	Reina(bool _color, int _x, int _y);
	~Reina() {};

	void Dibuja();
	void mueve(Vector2D);
	
};
