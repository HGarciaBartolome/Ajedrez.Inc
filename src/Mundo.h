#pragma once
#include "Tablero.h"
#include "ETSIDI.h"
#include "ListaPiezas.h"
class Mundo {
public:
	float x_ojo;
	float y_ojo;
	float z_ojo;
	ListaPiezas piezas;
	int x, j;
public:
	Mundo();
	virtual ~Mundo();

	Tablero tablero;
	Vector2D v;
	Vector2D guarda;
	
	enum Modo {COMIENZO, PVP, AYUDA};
	Modo m;

	enum Final {J1, J2, NO};
	Final f;

	void dibuja();
	void tecla(unsigned char key);
	void inicializa();
	void Mouse(int button, int state, int x, int y);
	void Movimiento(Vector2D aux);
};