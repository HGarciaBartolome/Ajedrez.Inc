#pragma once 
#include "ColorRGB.h"
#include "Vector2D.h"
#include "Piezas.h"

class Casilla {
private:
	float x, y;
	ColorRGB color;
	Pieza pieza;
public:
	Casilla();
	virtual ~Casilla(){};
	
	void dibuja();
	void setColor(unsigned char r, unsigned char g, unsigned char b);

	void setPos(int ix, int iy);
	Pieza getPieza();
	void setPieza(Pieza pieza);
	void iluminaCasilla();
};