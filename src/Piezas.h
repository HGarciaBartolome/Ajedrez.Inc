#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"

class Pieza {

private:
	

public:

	void setPosicion(float _x, float _y);
	void setColor(unsigned char r, unsigned char v, unsigned char a);

protected:
	bool color;// True = Negras , False = Blancas
	Vector2D posicion;
	ColorRGB colorGraph;


};

