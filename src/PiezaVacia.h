#pragma once
#include "Piezas.h"

class PiezaVacia :public Pieza {
private:

public:
	//contructor y destructor
	PiezaVacia(ColorPieza _color, Vector2D v);
	PiezaVacia();
	~PiezaVacia() {};

	//Metodos publicos
	bool movValido(int destX, int destY, ColorPieza c);
	void Dibuja();
	void Dibuja2();
	virtual char tipoPieza();
	Trayectoria getTrayectoria(Vector2D origen, Vector2D destino);
};
