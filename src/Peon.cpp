#include "Peon.h"
#include "ETSIDI.h"
#include "freeglut.h"

#define limite 0.5

Peon::Peon(ColorPieza _color, int _x, int _y)
{
	primerMov = true;
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

bool Peon::movValido(int destX, int destY, ColorPieza c) {


	if (color == ColorPieza::Blanca) {
		if (primerMov) {
			if ((destX == Pieza::getPosicionX()) && (destY == Pieza::getPosicionY() + 1) && (c!=Negra))//avanzando una fila	
			{
				return true;
			}

			else if ((destX == Pieza::getPosicionX()) && (destY == Pieza::getPosicionY() + 2) && (c != Negra)) //avanzando dos filas.
			{
				return true;
			}

			else if (((destX == Pieza::getPosicionX() - 1) && (destY == Pieza::getPosicionY() + 1)) || //si el destino es comer hacia su izquierda 
				((destX == Pieza::getPosicionX() + 1) && (destY == Pieza::getPosicionY() + 1)))  //si el destino es comer hacia su derecha
			{
				return true;
			}

			else
				return false;
		}
		//Si ya hizo el primer movimiento
		else if ((destX == Pieza::getPosicionX()) && (destY == Pieza::getPosicionY() + 1) && (c != Negra)) //avanzando una fila.
		{
			return true;
		}

		else if (((destX == Pieza::getPosicionX() - 1) && (destY == Pieza::getPosicionY() + 1)) || //si el destino es comer hacia su izquierda 
			((destX == Pieza::getPosicionX() + 1) && (destY == Pieza::getPosicionY() + 1))) //si el destino es comer hacia su derecha
		{
			return true;
		}

		else return false;
	}

	if (color == ColorPieza::Negra) {

		if (primerMov) {
			if ((destX == Pieza::getPosicionX()) && (destY == Pieza::getPosicionY() - 1) && (c != Blanca))//avanzando una fila	
			{
				return true;
			}

			else if ((destX == Pieza::getPosicionX()) && (destY == Pieza::getPosicionY() - 2) && (c != Blanca)) //avanzando dos filas.
			{
				return true;
			}

			else if (((destX == Pieza::getPosicionX() + 1) && (destY == Pieza::getPosicionY() - 1)) || //si el destino es comer hacia su izquierda 
				((destX == Pieza::getPosicionX() - 1) && (destY == Pieza::getPosicionY() - 1)))  //si el destino es comer hacia su derecha
			{
				return true;
			}

			else return false;
		}

		//Si ya hizo el primer movimiento
		else if	((destX == Pieza::getPosicionX()) && (destY == Pieza::getPosicionY() - 1) && (c != Blanca)) //avanzando una fila.
		{
			return true;
		}
		
			else if (((destX == Pieza::getPosicionX() + 1) && (destY == Pieza::getPosicionY() - 1)) || //si el destino es comer hacia su izquierda 
					((destX == Pieza::getPosicionX() - 1) && (destY == Pieza::getPosicionY() - 1)))		//si el destino es comer hacia su derecha
				{ 
					return true;
				}
		
		else return false;
	}
}



Vector2D* Peon::getTrayectoria(Vector2D origen, Vector2D destino) {
	Vector2D* trayectoria = new Vector2D();

	int signo_y = 1;
	int signo_x = 1;

	if (destino.x < origen.x) {
		signo_x = -1;
	}

	if (destino.y < origen.y) {
		signo_y = -1;
	}

	Vector2D aux = origen;
	unsigned int index = 0;
	while (!(aux == destino)) {
		if ((destino.x == aux.x)) {
			aux.x = aux.x;
			aux.y = aux.y + signo_y;
		}
		else {
			aux.x = aux.x + signo_x;
			aux.y = aux.y + signo_y;
		}
		trayectoria[index++] = aux;
	}

	//if ((trayectoria->x==origen.x) && (trayectoria->x == destino.x)&& (trayectoria->y == destino.y))
	//	tablero.hayPiezaDelantePeon(destino);

	trayectoria[index] = Vector2D(-1, -1); // Marcar final de trayectoria
	return trayectoria;
}
