#pragma once
#include "Piezas.h"
#include "ETSIDI.h"
#include "freeglut.h"
#include <vector>

class Alfil :public Pieza {

public:
	//Construcctor y destructor
	Alfil(ColorPieza _color, Vector2D v);
	~Alfil() {};

	//Metodos publicos
	void Dibuja();
	void Dibuja2();
	bool movValido(int destX, int destY, ColorPieza c);
	virtual char tipoPieza();
	Trayectoria getTrayectoria(Vector2D origen, Vector2D destino);
};
