#include "Peon.h"
#include "ETSIDI.h"
#include "freeglut.h"

#define limite 0.5

Peon::Peon(ColorPieza _color, Vector2D v)
{
	primerMov = true;
	color = _color;
	posicion = v;
}

void Peon::Dibuja()
{
	if (color == ColorPieza::Blanca) {
		glEnable(GL_TEXTURE_2D);
		try {
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Pb.png").id);
		}
		catch (...) {

		}
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
		try {
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Pn.png").id);
		}
		catch (...) {

		}
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

void Peon::Dibuja2()
{
	if (color == ColorPieza::Blanca) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Pb960.png").id);
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
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Pn960.png").id);
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

void Peon::Dibuja3()
{
	if (color == ColorPieza::Blanca) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/PbETSIDI.png").id);
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
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/PnETSIDI.png").id);
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
			if ((destX == Pieza::getPosicionX()) && (destY == Pieza::getPosicionY() + 1) && (c != Negra))//avanzando una fila	
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
		else if ((destX == Pieza::getPosicionX()) && (destY == Pieza::getPosicionY() - 1) && (c != Blanca)) //avanzando una fila.
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



Trayectoria Peon::getTrayectoria(Vector2D origen, Vector2D destino) {
	Trayectoria t;;

	int signo_y = 1;
	int signo_x = 1;

	if (destino.x < origen.x) {
		signo_x = -1;
	}

	if (destino.y < origen.y) {
		signo_y = -1;
	}

	Vector2D aux = origen;
	while (!(aux == destino)) {
		if ((destino.x == aux.x)) {
			aux.x = aux.x;
			aux.y = aux.y + signo_y;
		}
		else {
			aux.x = aux.x + signo_x;
			aux.y = aux.y + signo_y;
		}
		t.push_back(aux);
	}

	return t;
}

char Peon::tipoPieza()
{
	return 'P';
}
