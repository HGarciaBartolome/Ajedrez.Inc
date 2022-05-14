#include "PiezaVacia.h"
#include "ETSIDI.h"
#include "freeglut.h"
#define limite 0.5

PiezaVacia::PiezaVacia(ColorPieza _color, int _x, int _y)
{
	color = _color;
	posicion.x = _x;
	posicion.y = _y;
}


bool PiezaVacia::movValido(int destX, int destY)
{
	return false;
}

void PiezaVacia::Dibuja()
{
	return;
}