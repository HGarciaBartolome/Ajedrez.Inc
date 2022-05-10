#pragma once
#include "Piezas.h"

class Rey :public Pieza {
private:

public:
	Rey(bool _color, int _x, int _y);
	~Rey() {};

	void Dibuja();
	void mueve(Vector2D);


};
