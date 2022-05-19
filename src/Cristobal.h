#pragma once
#include "Piezas.h"

class Cristobal :public Pieza {

public:
	//constructor y destructor
	Cristobal(ColorPieza _color, Vector2D v);
	~Cristobal() {};

	//Metodos publicos
	void Dibuja3();
	bool movValido(int destX, int destY, ColorPieza c);
	virtual char tipoPieza();
	Trayectoria getTrayectoria(Vector2D origen, Vector2D destino);
};
