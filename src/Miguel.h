#pragma once
#include "Piezas.h"

class Miguel :public Pieza {

public:
	//constructor y destructor
	Miguel(ColorPieza _color, Vector2D v);
	~Miguel() {};

	//Metodos publicos
	void Dibuja3();
	bool movValido(int destX, int destY, ColorPieza c);
	virtual char tipoPieza();
	Trayectoria getTrayectoria(Vector2D origen, Vector2D destino);
};