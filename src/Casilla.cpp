#include "Casilla.h"
#include "freeglut.h"
#define limite 0.5

Casilla::Casilla() {
	x = y = 0;
	ocup = Ficha::VACIO;
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

Ficha Casilla::getPieza()
{
	return ocup;
}

int Casilla::getPosY()
{
	return y;
}



int Casilla::getPosX()
{
	return x;
}

void Casilla::setPieza(Ficha pieza)
{
	ocup = pieza;
}

void Casilla::iluminaCasilla()
{
	color.r = color.b = color.g= 255;
}

