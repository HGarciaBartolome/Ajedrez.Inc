#pragma once
#include "Tablero.h"
#include "ETSIDI.h"

class Mundo {
public:
	float x_ojo;
	float y_ojo;
	float z_ojo;
public:
	Mundo();
	virtual ~Mundo();

	Tablero tablero;

	enum Modo {COMIENZO, PVP, AYUDA};
	Modo m;

	enum Final {J1, J2, NO};
	Final f;

	void dibuja();
	void tecla(unsigned char key);
	void inicializa();
};