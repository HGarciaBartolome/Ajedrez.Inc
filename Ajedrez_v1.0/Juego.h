#pragma once
#include "Tablero.h"
#include "Casilla.h"
//#include "Vector2D.h"
//#include "ETSIDI.H"
//#include "Reina.h"
#include <math.h>
#include <stdio.h>
//#include "glut.h"
#include <iostream>

class Juego
{
	//Posicion del juego
	float x_ojo;
	float y_ojo;
	float z_ojo;

	int tipo; //tipo de juego (1/2)

	Tablero tablero;
	/*Ficha fichaJ1[8][8];
	Ficha fichaJ2[8][8];
	Reina reinaJ1[8][8];
	Reina reinaJ2[8][8];*/

	/*
	//Vectores que se usan para seleccionar casillas
	Vector2D vector;
	Vector2D aux;
	Vector2D aux2;
	Vector2D v;
	*/

	enum Turnos { TurnoUno, TurnoDos, TurnoPC, TurnoTres };
	Turnos turno;

	//Paso 1: seleccionar casilla, Paso 2: hacia donde va
	enum Pasos { PrimPaso, SegPaso, SegPasoReina };
	Pasos paso;

	//Movimientos de la maquina
	enum Movimientos { NADA, AD, AI, DD, DI };
	Movimientos movimiento;

	//int ContComidaObligatoriaJ1;
	//int ContComidaObligatoriaJ2;
	bool ComidaVariasJ1;
	bool ComidaVariasJ2;

	//Contadores de fichas de cada jugador
	int contadorJ1;
	int contadorJ2;

public:
	//INICIALIZACION
	void Inicializa(int t);
	virtual ~Juego() {}

	/*
	//METODOS DE CONTROL
	void Jugadas(); //va controlando los turnos
	void MuestraPosibilidades();
	void CrearReina();

	//METODOS DE MOVIMIENTO
	void MovimientoJ1();
	void MovimientoJ2();
	void MovimientoR1(Vector2D m);
	void MovimientoR2(Vector2D m);
	void MovimientoPC();


	//METODOS AUXILIARES DE MOVIMIENTO
	void ComidaObligatoriaJ1();
	void ComidaObligatoriaJ2();
	bool ComidaDobleReinaPC();
	bool ComidaDobleReina();

	//METODOS DE CONTADOR
	int contador(Ficha jugad[8][8], Reina jugad_[8][8]);

	//METODOS DE COMPROBACION
	bool Ocupada(Ficha fichas[8][8], Vector2D v); //comprueba si esta ocupada lleva bool
	bool Ocupada(Vector2D v);
	bool Ocupada(Reina reina[8][8], Vector2D v);
	bool FichaCorrecta(Ficha f[8][8], Vector2D v);
	bool FichaNextCorrecta(Ficha f[8][8], Vector2D v);
	bool Existe(Vector2D v);

	//funciones se usan para resetear los datos al cambiar de turno
	void DesactivaPosibilidadesJ2();
	void DesactivaPosibilidadesJ1();
	*/

	//METODOS GET
	int GetContadorJ1() { return contadorJ1; };
	int GetContadorJ2() { return contadorJ2; };

	//Funciones para la glut
	void Tecla(unsigned char key);
	void Raton(int button, int state, int x, int y);
	void RotarOjo(); //Rota el ojo durante un tiempo y se para con la función indicada a continuacion
	void Para(); //Deja de girar y comienza el juego
	void Dibuja();


};

