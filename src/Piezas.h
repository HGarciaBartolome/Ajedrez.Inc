#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"

class Pieza {

protected:
	bool color;// True = Negras , False = Blancas
public:
	Pieza();
	virtual ~Pieza() {};
	ColorRGB colorGraph;
	Vector2D posicion;

	int getPosicionX();
	int getPosicionY();
	void setPosicion(float _x, float _y);
	void setColor(unsigned char r, unsigned char v, unsigned char a);




};

