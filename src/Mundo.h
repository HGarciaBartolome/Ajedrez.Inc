#pragma once
#include "Tablero.h"

class Mundo {
public:
	float x_ojo;
	float y_ojo;
	float z_ojo;
public:
	Tablero tablero;
	void dibuja();
	void inicializa();
};