#pragma once
#include "Casilla.h"
#include "ColorRGB.h"
#include "Torre.h"
#include "Alfil.h"
#include "Reina.h"
#include "Rey.h"
#include "Peon.h"
#include "Caballo.h"
#include "PiezaVacia.h"


class Tablero {
private:
	Casilla casilla[8][8];
	Casilla casillaSeleccionada;
	ColorRGB color;
	bool inicializado, inicializado2;
	Pieza* pieza;
public:
	Tablero();
	virtual ~Tablero(){};

	Vector2D pos;
	Vector2D aux;

	void dibuja();
	void dibuja2();
	void Inicializa();
	void Inicializa2();

	bool estaInicializado();
	bool estaInicializado2();
	bool hayPiezaDelMismoColor(Vector2D pos);
	void ilumina(Vector2D ilu);
	void desilumina(Vector2D desilu);
	void seleccionarCasilla(Vector2D pos);
	void hacerMovimiento(Vector2D aux);
	Casilla getCasilla(Vector2D pos);
	bool hayCasillaSeleccionada();
	bool esLaCasillaSeleccionada(Vector2D pos);
	Casilla getCasillaSeleccionada();
	//void random();
};