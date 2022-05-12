#pragma once
#include "Piezas.h"
#include "ETSIDI.h"
#include "freeglut.h"
#include "Vector2D.h"
class Torre :public Pieza {

private:
	bool _primerMov;
public:
	Torre() {};
	Torre(bool _color, int _x, int _y);
	~Torre() {};

	bool movValido(int destX, int destY);
	char tipoPieza();
	bool getPrimerMov() { return _primerMov; }
	void Dibuja();
};