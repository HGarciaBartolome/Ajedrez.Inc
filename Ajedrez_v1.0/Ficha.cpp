#include "Ficha.h"

Ficha::Ficha() {
	x = y = 0;
	rojo = verde = azul = 1;
	ocupada = false;
	marca = false;
	next = false;
	tipo = 0;
}
Ficha::Ficha(int _x, int _y,bool color)
{
	x = _x;
	y = _y;
	tipo = 0;
	if (color == 0) {
		rojo = 255;
		azul = 255;
		verde = 255;
	}
	else if (color ==1) {
		rojo = 0;
		azul = 0;
		verde = 0;
	}
}
Ficha::Ficha(int _x, int _y, int _tipo,bool color)
{
	x = _x;
	y = _y;
	tipo = _tipo;
	if (color == 0) {
		rojo = 255;
		azul = 255;
		verde = 255;
	}
	else if (color == 1) {
		rojo = 0;
		azul = 0;
		verde = 0;
	}
}
void Ficha::Dibuja() {
	/*
	//cilindro
	glDisable(GL_LIGHTING);
	glColor3ub(rojo, verde, azul);
	GLUquadricObj* quadratic;
	quadratic = gluNewQuadric();
	glTranslatef(x, y, 0);
	gluCylinder(quadratic, 0.4f, 0.4f, 0.3f, 32, 32);
	glTranslatef(-x, -y, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	//tapa del cilindro
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(rojo, verde, azul);
	glVertex3f(x, y, 0.3f);
	for (int count = 0; count <= 360; count++)
		glVertex3f(x + sin((float)count) * 0.401, +y + cos((float)count) * 0.401, 0.3f);
	glEnd();
	glEnable(GL_LIGHTING);
	*/
};

void Ficha::setPosicion(float ix, float iy) {
	x = ix;
	y = iy;
}

void Ficha::SetColor(unsigned char r, unsigned char v, unsigned char a)
{
	rojo = r;
	verde = v;
	azul = a;
}
int Ficha::GetPosicionX() {
	return  x;
}

void Ficha::SetActiva() {
	ocupada = true;
};
void Ficha::SetDesactiva() {
	ocupada = false;
}