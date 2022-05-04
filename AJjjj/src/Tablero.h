#pragma once
#include "Casilla.h"
#include "ColorRGB.h"

class Tablero {
private:
	Casilla casilla[8][8];
	ColorRGB color;
public:
	Tablero();
	//virtual ~Tablero();
	void dibuja();
};