#include "Piezas.h"

Pieza::Pieza()
{
	color = ColorPieza::Indefinido;
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

void Pieza::setColor(unsigned char r, unsigned char v, unsigned char a)
{

}

ColorPieza Pieza::getColor() const
{
	return color;
}