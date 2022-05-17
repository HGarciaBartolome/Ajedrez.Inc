#pragma once
#include "Piezas.h"

class Peon :public Pieza {

public:
	Peon(ColorPieza _color, int _x, int _y);
	Peon() {};
	~Peon() {};

	void Dibuja();
	bool movValido(int destX, int destY, ColorPieza c);
	Vector2D* getTrayectoria(Vector2D origen, Vector2D destino);

};
