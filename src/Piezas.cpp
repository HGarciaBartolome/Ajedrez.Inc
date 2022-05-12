#include "Piezas.h"

Pieza::Pieza(bool _color, int _x, int _y)
{
	color = _color;
	posicion.x = _x;
	posicion.y = _y;

}

int Pieza::getPosicionX()
{
	return posicion.x;
}

int Pieza::getPosicionY()
{
	return posicion.y;
}

void Pieza::setPosicion(float _x, float _y)
{
	posicion.x = _x;
	posicion.y = _y;
}

char Pieza::tipoPieza()
{
	return 0;
}

void Pieza::Dibuja()
{
}

bool Pieza::movValido(int destX, int destY)
{
	return false;
}
