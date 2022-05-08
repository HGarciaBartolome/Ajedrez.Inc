#pragma once
#include "Piezas.h"
#include "ETSIDI.h"
#include "freeglut.h"
#include "Vector2D.h"
class Torre :public Pieza {

protected:
	
	//ETSIDI::Sprite ficha("imagenes/Cb.png", posicion.x, posicion.y, 1.0, 1.0);
public:

	Torre(bool _color, int _x, int _y);
	void Dibuja();
	void mueve(Vector2D _pos);


};