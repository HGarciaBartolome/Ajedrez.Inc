#include "Casilla.h"
#include "freeglut.h"
#define limite 0.5

Casilla::Casilla() {
	x = y = 0;
}

void Casilla::dibuja() {
	glDisable(GL_LIGHTING);
	glColor3ub(color.r, color.g, color.b);
	glBegin(GL_POLYGON);
	glVertex2f(x + limite, y + limite);
	glVertex2f(x + limite, y - limite);
	glVertex2f(x - limite, y - limite);
	glVertex2f(x - limite, y + limite);
	glEnd();
	glEnable(GL_LIGHTING);
}

void Casilla::setPos(int ix, int iy)
{
	x = ix;
	y = iy;
}


void Casilla::setColor(unsigned char r, unsigned char g, unsigned char b) {
	color.r = r;
	color.g = g;
	color.b = b;
}

Pieza Casilla::getPieza()
{
	return pieza;
}

void Casilla::setPieza(Pieza pieza)
{
	this->pieza = pieza;
}

void Casilla::iluminaCasilla()
{

	color.r = 255;
	color.b = color.g= 0;


}

