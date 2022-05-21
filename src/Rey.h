#pragma once
#include "Piezas.h"

class Rey :public Pieza {
private:
	
public:
	//constructor y destructor
	Rey(ColorPieza _color, Vector2D v);
	~Rey() {};

	//Metodos publicos
	void Dibuja();
	void Dibuja2();
	void Dibuja3();
	bool movValido(int destX, int destY, ColorPieza c);
	virtual char tipoPieza();
	Trayectoria getTrayectoria(Vector2D origen, Vector2D destino);
};
