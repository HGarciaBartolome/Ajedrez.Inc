#pragma once 
#include "ColorRGB.h"
#include "Vector2D.h"
#include "Piezas.h"

class Casilla {
private:
	Vector2D pos;
	ColorRGB color;
	Pieza* pieza;
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