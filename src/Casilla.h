#pragma once 
#include "ColorRGB.h"
#include "Vector2D.h"
#include "Piezas.h"

class Casilla {
private:
	Pieza* pieza;
	Vector2D pos;
	ColorRGB color;
public:
	Casilla();
	virtual ~Casilla(){};
	
	void dibuja();
	void setColor(unsigned char r, unsigned char g, unsigned char b);

	void setPos(Vector2D pos);
	Vector2D getPos();
	Pieza* getPieza();
	void setPieza(Pieza* pieza);
	void iluminaCasilla();
};