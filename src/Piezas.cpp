#include "Piezas.h"

Pieza::Pieza()
{
	//se inicializa como primer movimiento de cualquier pieza y color indefinido
	primerMov = true;
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

Vector2D Pieza::getPosicion()
{
	return posicion;
}

void Pieza::setPosicion(Vector2D v)
{
	posicion = v;
}

ColorPieza Pieza::getColor() const
{
	return color;
}

void Pieza::setPrimerMov(bool pm)
{
	primerMov = pm;
}

void Pieza::Dibuja()
{
}

void Pieza::Dibuja2()
{
}

void Pieza::Dibuja3()
{
}
