#pragma once
#include "Piezas.h"
#include "ETSIDI.h"
#include "freeglut.h"
#include "Vector2D.h"
class Torre :public Pieza {

public:
	//contructores y destructores
	Torre(ColorPieza _color, Vector2D v);
	Torre() {};
	~Torre() {};

	//Metodos publicos
	bool movValido(int destX, int destY, ColorPieza c);
	void Dibuja();
	void Dibuja2();
	virtual char tipoPieza();
	Trayectoria getTrayectoria(Vector2D origen, Vector2D destino);
};