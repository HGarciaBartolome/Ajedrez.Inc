#pragma once
#include "Piezas.h"

class Reina :public Pieza {

private:

public:
	Reina(ColorPieza _color, int _x, int _y);
	~Reina() {};

	void Dibuja();
	bool movValido(int destX, int destY, ColorPieza c);
	Vector2D* getTrayectoria(Vector2D origen, Vector2D destino);
};
