#pragma once

#include "Juego.h"
#include "ETSIDI.H"

class Mundo
{
public:
	Mundo();
	virtual ~Mundo() {}
	void tecla(unsigned char key);
	void dibuja();
	void Raton(int, int, int, int);
	void RotarOjo();
	void Mueve();

protected:
	Juego Juego;
	enum Estado { INICIO, JUGVSMAQ, JUGVSJUG, REGLAS };
	Estado estado;
	enum Victoria { FINJ1, FINJ2, NO };
	Victoria victoria;
	int contador;


};

