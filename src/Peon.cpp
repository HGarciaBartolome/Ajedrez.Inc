#include "Peon.h"
#include "ETSIDI.h"
#include "freeglut.h"

/*
#define MINCORRECTO 0
#define MVALIDO 1
#define P_AVANZA1 2
#define P_AVANZA2 3
#define P_COME 4
*/

#define limite 0.5

Peon::Peon(ColorPieza _color, int _x, int _y)
{
	color = _color;
	posicion.x = _x;
	posicion.y = _y;
}

void Peon::Dibuja()
{
	if (color == ColorPieza::Blanca) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Pb.png").id);
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
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Pn.png").id);
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

bool Peon::movValido(int destX, int destY) {
	

	if (color == ColorPieza::Blanca) {
		if ((destX == Pieza::getPosicionX()) && (destY == Pieza::getPosicionY() + 1))//avanzando una fila	
		{
			return true;
		}

		else if ((destX == Pieza::getPosicionX()) && (destY == Pieza::getPosicionY() + 2)) //avanzando dos filas.
		{
			return true;
		}

		else if (((destX == Pieza::getPosicionX() - 1) && (destY == Pieza::getPosicionY() + 1)) || //si el destino es comer hacia su izquierda 
			((destX == Pieza::getPosicionX() + 1) && (destY == Pieza::getPosicionY() + 1)))  //si el destino es comer hacia su derecha)  
		{
			return true;
		}
		else
			return false;

	}

	if (color == ColorPieza::Negra) {

		if ((destX == Pieza::getPosicionX()) && (destY == Pieza::getPosicionY() - 1))//avanzando una fila	
		{
			return true;
		}

			else if ((destX == Pieza::getPosicionX()) && (destY == Pieza::getPosicionY() - 2)) //avanzando dos filas.
			{
				return true;
			}

				else if (((destX == Pieza::getPosicionX() + 1) && (destY == Pieza::getPosicionY() - 1)) || //si el destino es comer hacia su izquierda 
						((destX == Pieza::getPosicionX() - 1) && (destY == Pieza::getPosicionY() - 1)))  //si el destino es comer hacia su derecha)  
				{
					return true;
				}

			else return false;
		}

}