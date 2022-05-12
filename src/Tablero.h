#pragma once
#include "Casilla.h"
#include "ColorRGB.h"
#include "Torre.h"
#include "Alfil.h"
#include "Reina.h"
#include "Rey.h"
#include "Peon.h"
#include "Ficha.h"


class Tablero {
private:
	Casilla casilla[8][8];
	Casilla casillaSeleccionada;
	ColorRGB color;
public:
	Tablero();
	virtual ~Tablero(){};

	Vector2D pos;
	Vector2D aux;

	void dibuja();
	void Inicializa();
	Casilla getcasillaSelecionada();
	void ilumina(Vector2D ilu);
	void desilumina(Vector2D desilu);
	void seleccionarCasilla(Vector2D pos);
	bool hacerMovimiento(Vector2D aux);
	Casilla getCasilla(Vector2D pos);
};