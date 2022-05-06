#include "Piezas.h"

Pieza::Pieza()
{
	limite.x = limite.y = 0.5;
}

void Pieza::setPosicion(float _x, float _y)
{
	posicion.x = _x;
	posicion.y = _y;
}

void Pieza::setColor(unsigned char r, unsigned char v, unsigned char a)
{

}
