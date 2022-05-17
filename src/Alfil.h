#pragma once
#include "Piezas.h"

class Alfil :public Pieza {

private:

public:
	Alfil(ColorPieza _color, int _x, int _y);
	~Alfil() {};

	void Dibuja();
	bool movValido(int destX, int destY, ColorPieza c);
	Vector2D* getTrayectoria(Vector2D origen, Vector2D destino);

};
