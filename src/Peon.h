#pragma once
#include "Piezas.h"

class Peon :public Pieza {

public:
	//contructores y destructor
	Peon(ColorPieza _color, Vector2D v);
	Peon() {};
	~Peon() {};

	//Metodos publicos
	void Dibuja();
	void Dibuja2();
	void Dibuja3();
	bool movValido(int destX, int destY, ColorPieza c);
	virtual char tipoPieza();
	Trayectoria getTrayectoria(Vector2D origen, Vector2D destino);
};
