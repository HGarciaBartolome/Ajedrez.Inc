#pragma once 
#include "ColorRGB.h"
#include "Vector2D.h"
class Casilla {
private:
	ColorRGB color;
	Vector2D limite;
	float x, y;
	/*enum piezas {
		REYN, REYB,
		REINAN, REINAB,
		ALFILN, ALFILB,
		TORREN, TORREB,
		PEONN, PEONB,
		VACIO = -1
	}pieza;*/
public:
	Casilla();
	//virtual ~Casilla();
	void dibuja();
	void setPos(int ix, int iy);
	void setColor(unsigned char r, unsigned char g, unsigned char b);
	void setPieza(int p);
};