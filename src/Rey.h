#pragma once
#include "Piezas.h"

class Rey :public Pieza {
private:
	
public:
	Rey(ColorPieza _color, int _x, int _y);
	~Rey() {};

	void Dibuja();
	bool movValido(int destX, int destY, ColorPieza c);
	Vector2D* getTrayectoria(Vector2D origen, Vector2D destino);

};
