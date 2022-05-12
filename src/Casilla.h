#pragma once 
#include "ColorRGB.h"
#include "Vector2D.h"
#include "Piezas.h"
#include "Ficha.h"
class Casilla {

private:
	float x, y;
	ColorRGB color;
		
	Ficha ocup;

	//Pieza pieza;
public:
	Casilla();
	virtual ~Casilla(){};
	friend class Tablero;
	void dibuja();
	void setColor(unsigned char r, unsigned char g, unsigned char b);

	void setPos(int ix, int iy);
	Ficha getPieza();
	int getPosX();
	int getPosY();
	void setPieza(Ficha pieza);
	void iluminaCasilla();
};