#pragma once
#include "Piezas.h"

class Alfil :public Pieza {

private:

public:
	Alfil(bool _color, int _x, int _y);
	~Alfil() {};

	void Dibuja();
	
	void mueve(Vector2D);
	bool puedeMover(int ix, int iy, Pieza* p);

};
