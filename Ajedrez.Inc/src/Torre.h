#pragma once
#include "Piezas.h"
#include "ETSIDI.h"
#include "freeglut.h"
#include "Vector2D.h"
class Torre :public Pieza {
private:
	bool _primerMov;
public:
	Torre(ColorPieza _color, int _x, int _y);
	~Torre() {};

	bool movValido(int destX, int destY);
	void Dibuja();
	bool getPrimerMov() { return _primerMov; }
};