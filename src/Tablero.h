#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include "ETSIDI.h"
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
	//Atributos privados propios de la clase Tablero
private:
	//Instancias
	Casilla casilla[8][8];
	Casilla casillaSeleccionada;
	ColorRGB color;
	ColorRGB color2;
	ColorRGB color3;
	Pieza* pieza;
	//Variables
	bool inicializado, inicializado2, inicializado3;

	void hacerEnroque(Vector2D pos, Vector2D rey, Vector2D torre);
	void hacerCoronamiento(int, int);
	bool coronar(Pieza* pieza);
	bool hayPiezaEnMedio(Trayectoria trayectoria, Vector2D destino);
	Casilla getCasilla(Vector2D pos);

	////////////////////JAQUES////////////////////////////
	//bool hayJaque();
	//Casilla buscarRey(ColorPieza color);
	//bool buscarJaque(Vector2D pos);

	//Metodos públicos
public:
	//Constructor y destructor
	Tablero();
	virtual ~Tablero() {};

	//Instancias
	Vector2D pos;
	Vector2D aux;

	//Enumeracion para el turno del jugador
	enum Turno { turnoNEGRAS = 1, turnoBLANCAS };
	Turno t;

	/*enum Ajedrez { SM = 0, Clasico, c960, ETSIDI };
	Ajedrez ajedrez;*/

	enum FinPartida { GanaJ1, GanaJ2, NO };
	FinPartida f;

	char rojo(char);
	char verde(char);
	char azul(char);
	char rojo2(char);
	char verde2(char);
	char azul2(char);

	//Para Inicializar/Dibujar cada modo de juego
	void dibuja(); //chessClasico
	void dibuja2(); //chess960
	void dibuja3(); //chessETSIDI
	void Inicializa(); //chessClasico
	void Inicializa2(); //chess960
	void Inicializa3();//chessETSIDI
	bool estaInicializado();
	bool estaInicializado2();
	bool estaInicializado3();

	//Funcionalidades propias del juego
	bool hayPiezaDelMismoColor(Vector2D pos);
	void ilumina(Vector2D ilu);
	void desilumina(Vector2D desilu);
	void seleccionarCasilla(Vector2D pos);
	void hacerMovimiento(Vector2D aux);
	bool hayCasillaSeleccionada();
	Casilla getCasillaSeleccionada();
	bool posibleEnroque(Vector2D pos);
	void captura(char tipo, ColorPieza color);
};