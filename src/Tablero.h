#pragma once
#include "Casilla.h"
#include "ColorRGB.h"

class Tablero {
private:
	Casilla casilla[8][8];
	ColorRGB color;
public:
	enum piezas {
		REYN, REYB,
		REINAN, REINAB,
		ALFILN, ALFILB,
		TORREN, TORREB,
		PEONN, PEONB,
		VACIO = -1
	};
	Tablero();
	virtual ~Tablero(){};
	void dibuja();
	void Inicializa();
};