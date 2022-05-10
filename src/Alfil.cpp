#include "Alfil.h"
#include "ETSIDI.h"
#include "freeglut.h"
#define limite 0.5

Alfil::Alfil(bool _color, int _x, int _y)
{
	color = _color;
	posicion.x = _x;
	posicion.y = _y;
}

void Alfil::Dibuja()
{
	if (color == FALSE) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Ab.png").id);
		glDisable(GL_LIGHTING);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(posicion.x - limite, posicion.y - limite, 0.01);
		glTexCoord2d(1, 1); glVertex3f(posicion.x + limite, posicion.y - limite, 0.01);
		glTexCoord2d(1, 0); glVertex3f(posicion.x + limite, posicion.y + limite, 0.01);
		glTexCoord2d(0, 0); glVertex3f(posicion.x - limite, posicion.y + limite, 0.01);
		glEnd();
		glDisable(GL_BLEND);
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
	else if (color == TRUE) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/An.png").id);
		glDisable(GL_LIGHTING);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(posicion.x - limite, posicion.y - limite, 0.01);
		glTexCoord2d(1, 1); glVertex3f(posicion.x + limite, posicion.y - limite, 0.01);
		glTexCoord2d(1, 0); glVertex3f(posicion.x + limite, posicion.y + limite, 0.01);
		glTexCoord2d(0, 0); glVertex3f(posicion.x - limite, posicion.y + limite, 0.01);
		glEnd();
		glDisable(GL_BLEND);
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
 
}

void Alfil::mueve(Vector2D)
{
}
/*
bool Alfil::puedeMover(int ix, int iy, Pieza* p) {

	if ((pos.x == ix && pos.y == iy)|| (abs(pos.x - ix) != abs(pos.y - iy))|| (p != NULL && p->getColor() == color))
		return false;							
	//MOV NO VALIDO, CASILLA DE PARTIDA || MOV NO VALIDO, NO MOV DIAGONAL || MOV NO VALIDO, PIEZA MISMO COLOR
														
}
*/