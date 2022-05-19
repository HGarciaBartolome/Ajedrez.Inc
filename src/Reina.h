#pragma once
#include "Piezas.h"

class Reina :public Pieza {

private:

public:
	//contructor y destructor
	Reina(ColorPieza _color, Vector2D v);
	~Reina() {};

	//Metodos publicos
	void Dibuja();
	void Dibuja2();
	void Dibuja3();
	bool movValido(int destX, int destY, ColorPieza c);
	virtual char tipoPieza();
	Trayectoria getTrayectoria(Vector2D origen, Vector2D destino);
};
