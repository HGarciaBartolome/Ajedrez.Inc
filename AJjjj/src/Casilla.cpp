#include "Casilla.h"
#include "freeglut.h"


Casilla::Casilla() {
	limite.x = 0.5;
	limite.y = 0.5;
}

void Casilla::dibuja() {
	glDisable(GL_LIGHTING);
	glColor3ub(color.r, color.g, color.b);
	glBegin(GL_POLYGON);
	glVertex2f(x + limite.x, y + limite.y);
	glVertex2f(x + limite.x, y - limite.y);
	glVertex2f(x - limite.x, y - limite.y);
	glVertex2f(x - limite.x, y + limite.y);
	glEnd();
	glEnable(GL_LIGHTING);
}

void Casilla::setPos(int ix, int iy) {
	x = ix;
	y = iy;
}

void Casilla::setColor(unsigned char r, unsigned char g, unsigned char b) {
	color.r = r;
	color.g = g;
	color.b = b;
}
