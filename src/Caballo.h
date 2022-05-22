#pragma once
#include "Piezas.h"
#include "freeglut.h"
#include "ETSIDI.h"

class Caballo :public Pieza {

public:
	//constructor y destructor
	Caballo(ColorPieza _color, Vector2D v);
	~Caballo() {};

	//Metodos publicos
	void Dibuja();
	void Dibuja2();
	bool movValido(int destX, int destY, ColorPieza c);
	virtual char tipoPieza();
	Trayectoria getTrayectoria(Vector2D origen, Vector2D destino);
};