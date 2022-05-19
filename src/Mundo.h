#pragma once
#include "Tablero.h"
#include "ETSIDI.h"
#include "freeglut.h"
#include <math.h>

class Mundo {

private:
	//atributos privados que definen la perspectiva
	float x_ojo;
	float y_ojo;
	float z_ojo;

public:
	//contructor y destructor
	Mundo();
	virtual ~Mundo() {};

	//Instancias
	Tablero tablero;
	Vector2D v;

	//Enumeraciones para Modo de juego y Final de partida
	enum Modo { COMIENZO, chessClasico, chess960, chessETSIDI, AYUDA };
	Modo m;
	enum Final { J1, J2, NO };
	Final f;

	//Funciones de manejo con la GLUT
	void dibuja();
	void tecla(unsigned char key);
	void inicializa();
	void Mouse(int button, int state, int x, int y);
	Vector2D getVectorDesdeCoordenadas(int x, int y);
};