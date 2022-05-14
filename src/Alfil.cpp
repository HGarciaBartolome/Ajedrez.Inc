#include "Alfil.h"
#include "ETSIDI.h"
#include "freeglut.h"
#define limite 0.5

Alfil::Alfil(ColorPieza _color, int _x, int _y)
{
	color = _color;
	posicion.x = _x;
	posicion.y = _y;
}

void Alfil::Dibuja()
{
	if (color == ColorPieza::Blanca) {
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
	else if (color == ColorPieza::Negra) {
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

bool Alfil::movValido(int destX, int destY)
{

	if ((destX > Pieza::getPosicionX() && destY < Pieza::getPosicionY()) ||		//si el movimiento es abajo a la derecha o arriba izquierda
		(destX<Pieza::getPosicionX() && destY>Pieza::getPosicionY()))
	{
		if ((destX + destY) == (Pieza::getPosicionX() + Pieza::getPosicionY()))
			return true;
		else
			return false;
	}
	else if ((destX < Pieza::getPosicionX() && destY < Pieza::getPosicionY()) ||
		(destX > Pieza::getPosicionX() && destY > Pieza::getPosicionY())) {			//si el movimiento es abajo izquierda o arriba derecha
		if ((destY - destX) == (Pieza::getPosicionY() - Pieza::getPosicionX()))
			return true;
		else
			return false;
	}
	else
		return false;

}
