#pragma once
#include "Piezas.h"
#include "freeglut.h"
#include "ETSIDI.h"

class Caballo :public Pieza {

private:

public:
	Caballo(ColorPieza _color, int _x, int _y);
	~Caballo() {};

	void Dibuja();
	bool movValido(int destX, int destY, ColorPieza c);
	Vector2D* getTrayectoria(Vector2D origen, Vector2D destino);
};