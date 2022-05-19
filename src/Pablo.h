#pragma once
#include "Piezas.h"

class Pablo :public Pieza {

public:
	//constructor y destructor
	Pablo(ColorPieza _color, Vector2D v);
	~Pablo() {};

	//Metodos publicos
	void Dibuja3();
	bool movValido(int destX, int destY, ColorPieza c);
	virtual char tipoPieza();
	Trayectoria getTrayectoria(Vector2D origen, Vector2D destino);
};
