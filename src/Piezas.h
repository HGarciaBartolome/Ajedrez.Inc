#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"

class Pieza {

protected:
	bool color;// True = Negras , False = Blancas
public:
	Pieza() {};
	Pieza(bool _color, int _x, int _y);
	virtual ~Pieza() {};
	Vector2D posicion;

	//Vector2D getPosicion();
	int getPosicionX();
	int getPosicionY();
	void setPosicion(float _x, float _y);

	virtual char tipoPieza();
	virtual void Dibuja();
	virtual bool movValido(int destX, int destY);


};

