#include "Casilla.h"
#include "freeglut.h"
#define limite 0.5

Casilla::Casilla() {
	pos.x = 0;
	pos.y = 0;
}

void Casilla::dibuja() {
	glDisable(GL_LIGHTING);
	glColor3ub(color.r, color.g, color.b);
	glBegin(GL_POLYGON);
	glVertex2f(pos.x + limite, pos.y + limite);
	glVertex2f(pos.x + limite, pos.y - limite);
	glVertex2f(pos.x - limite, pos.y - limite);
	glVertex2f(pos.x - limite, pos.y + limite);
	glEnd();
	glEnable(GL_LIGHTING);
}

void Casilla::setPos(Vector2D pos)
{
	this->pos = pos;
}

Vector2D Casilla::getPos()
{
	return pos;
}


void Casilla::setColor(unsigned char r, unsigned char g, unsigned char b) {
	color.r = r;
	color.g = g;
	color.b = b;
}

Pieza* Casilla::getPieza()
{
	return pieza;
}

void Casilla::setPieza(Pieza* pieza)
{
	this->pieza = pieza;
}

void Casilla::iluminaCasilla()
{
	color.r = color.b = color.g= 255;
}

