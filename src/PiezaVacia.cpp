#include "PiezaVacia.h"
#include "ETSIDI.h"
#include "freeglut.h"
#define limite 0.5

PiezaVacia::PiezaVacia()
{
	color = ColorPieza::Indefinido;
	posicion = Vector2D(-1, -1);
}

PiezaVacia::PiezaVacia(ColorPieza _color, Vector2D v)
{
	color = _color;
	posicion = v;
}

bool PiezaVacia::movValido(int destX, int destY, ColorPieza c)
{
	return false;
}

void PiezaVacia::Dibuja()
{
	return;
}

void PiezaVacia::Dibuja2()
{
}

char PiezaVacia::tipoPieza()
{
	return 'V';
}

Trayectoria PiezaVacia::getTrayectoria(Vector2D origen, Vector2D destino)
{
	Trayectoria t;

	return t;
}

