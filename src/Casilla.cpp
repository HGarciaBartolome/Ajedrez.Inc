#include "Casilla.h"
#define limite 0.5

void Casilla::dibuja() {
	
	glDisable(GL_LIGHTING);
	glColor3ub(color.r, color.g, color.b);
	glBegin(GL_POLYGON);
	glVertex2f(pieza->getPosicionX() + limite, pieza->getPosicionY() + limite);
	glVertex2f(pieza->getPosicionX() + limite, pieza->getPosicionY() - limite);
	glVertex2f(pieza->getPosicionX() - limite, pieza->getPosicionY() - limite);
	glVertex2f(pieza->getPosicionX() - limite, pieza->getPosicionY() + limite);
	glEnd();
	glEnable(GL_LIGHTING);
}

void Casilla::setColor(unsigned char r, unsigned char g, unsigned char b) { //pone el color
	color.r = r;
	color.g = g;
	color.b = b;
}

Pieza* Casilla::getPieza()	//retorna la pieza
{
	return pieza;
}

void Casilla::setPieza(Pieza* pieza)	//pone la pieza
{
	this->pieza = pieza;
}

void Casilla::iluminaCasilla()	//colorea la casilla seleccionada de blanco
{
	color.r = 255;
	color.b = 0;
	color.g = 0;
}


