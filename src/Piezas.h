#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"

enum ColorPieza {
	Indefinido,
	Negra,
	Blanca
};;// True = Negras , False = Blancas

class Pieza {

protected:
	ColorPieza color;
public:
	Pieza();
	virtual ~Pieza() {};
	ColorRGB colorGraph;
	Vector2D posicion;

	int getPosicionX();
	int getPosicionY();
	void setPosicion(float _x, float _y);
	void setColor(unsigned char r, unsigned char v, unsigned char a);
	ColorPieza getColor() const;
	virtual bool movValido(int destX, int destY) = 0;
	virtual void Dibuja() = 0;

};

