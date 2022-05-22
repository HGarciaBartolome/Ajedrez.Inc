#pragma once 
#include "freeglut.h"
#include "ETSIDI.h"
#include "ColorRGB.h"
#include "Vector2D.h"
#include "Piezas.h"

class Casilla {

	//Atributos privados
private:

	//Instancias
	Pieza* pieza;
	ColorRGB color;

	//Metodos publicos
public:

	//Constructor y destructor
	Casilla(){};
	virtual ~Casilla(){};
	//Dibujar
	void dibuja();
	void iluminaCasilla();
	//setters
	void setColor(unsigned char r, unsigned char g, unsigned char b);	
	void setPieza(Pieza* pieza);
	//getters
	Pieza* getPieza();

};