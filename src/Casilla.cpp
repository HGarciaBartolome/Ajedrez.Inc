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

void Casilla::setPieza(int pieza)
{
	switch (pieza) {

	case 0: 
		a = 0; //REYN
		break;
	case 1:
		a = 1;	//REYB
		break;
	case 2:
		a = 2;	//REINAN
		break;
	case 3:
		a = 3;	//REINAB
		break;
	case 4:
		a = 4;	//AN
		break;
	case 5:
		a = 5;	//AB
		break;
	case 6:
		a = 6;	//TN
		break;
	case 7:
		a = 7;	//TB
		break;
	case 8:
		a = 8;	//PN
		break;
	case 9:
		a = 9;	//PB
		break;
	default:
		a = -1;	//VACIO
	}
	
}

