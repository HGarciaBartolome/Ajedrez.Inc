#pragma once
#include "Piezas.h"
#include "ETSIDI.h"
#include "freeglut.h"
#include "Vector2D.h"
class Torre :public Pieza {

public:
	Torre(ColorPieza _color, int _x, int _y);
	Torre() {};
	~Torre() {};

	bool movValido(int destX, int destY, ColorPieza c);
	void Dibuja();
	Vector2D* getTrayectoria(Vector2D origen, Vector2D destino);
};