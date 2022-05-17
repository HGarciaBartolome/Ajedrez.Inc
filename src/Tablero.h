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
#include "Pablo.h"
#include "Miguel.h"
#include "Cristobal.h"

class Tablero {
private:
	Casilla casilla[8][8];
	Casilla casillaSeleccionada;
	ColorRGB color;
	bool inicializado, inicializado2, inicializado3;
	Pieza* pieza;
	int auxiliar;
public:
	Tablero();
	virtual ~Tablero() {};

	Vector2D pos;
	Vector2D aux;

	enum Turno { turnoNEGRAS=1, turnoBLANCAS};
	Turno t;

	void dibuja(); //chessClasico
	void dibuja2(); //chess960
	void dibuja3(); //chessETSIDI
	void Inicializa(); //chessClasico
	void Inicializa2(); //chess960
	void Inicializa3();//chessETSIDI

	bool estaInicializado();
	bool estaInicializado2();
	bool estaInicializado3();
	bool hayPiezaDelMismoColor(Vector2D pos);
	void ilumina(Vector2D ilu);
	void desilumina(Vector2D desilu);
	void seleccionarCasilla(Vector2D pos);
	void hacerMovimiento(Vector2D aux);
	Casilla getCasilla(Vector2D pos);
	bool hayCasillaSeleccionada();
	bool esLaCasillaSeleccionada(Vector2D pos);
	Casilla getCasillaSeleccionada();
	bool posibleEnroque(Vector2D pos);
	bool hayPiezaEnMedio(Vector2D* trayectoria, Vector2D destino);
	//bool hayPiezaDelantePeon(Vector2D destino);
};