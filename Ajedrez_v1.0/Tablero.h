#pragma once
#include "Casilla.h"
#include "Ficha.h"
//#include "Vector2D.h"
//#include "glut.h"

class Tablero
{
private:
	float numCasillas;
	Casilla casilla[8][8];

public:
    Tablero();
    virtual ~Tablero() {}
    void Dibuja();
    int GetCasillas() { return numCasillas; };
    void SeleccionaCasilla(Vector2D v, unsigned char x);
    void DesSeleccionaCasilla(Vector2D v);
};

