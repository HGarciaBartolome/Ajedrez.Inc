#include "Pablo.h"
#include "ETSIDI.h"
#include "freeglut.h"
#define limite 0.5

Pablo::Pablo(ColorPieza _color, Vector2D v)
{
	color = _color;
	posicion = v;
}

void Pablo::Dibuja3()
{
	if (color == ColorPieza::Blanca) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/AbETSIDI.png").id);	//poner Pablo blanco
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
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/AnETSIDI.png").id);		//poner Pablo negro
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

bool Pablo::movValido(int destX, int destY, ColorPieza c)
{
	int x = Pieza::getPosicionX();
	int y = Pieza::getPosicionY();


	if (color == ColorPieza::Blanca) {
		if ((destX == x) && (destY == y + 1) ||
			(destX == x) && (destY == y - 1) ||
			(destX == x) && (destY == y + 2) ||
			(destX == x) && (destY == y - 2) ||
			(destX == x) && (destY == y + 3) ||
			(destX == x) && (destY == y - 3))
		{
			return true;
		}

		else if ((destY == y) && (destX == x + 1) ||
			(destY == y) && (destX == x - 1) ||
			(destY == y) && (destX == x + 2) ||
			(destY == y) && (destX == x - 2) ||
			(destY == y) && (destX == x + 3) ||
			(destY == y) && (destX == x - 3))
		{
			return true;
		}

		else
			return false;
	}

	if (color == ColorPieza::Negra) {
		if ((destX == x) && (destY == y + 1) ||
			(destX == x) && (destY == y - 1) ||
			(destX == x) && (destY == y + 2) ||
			(destX == x) && (destY == y - 2) ||
			(destX == x) && (destY == y + 3) ||
			(destX == x) && (destY == y - 3))
		{
			return true;
		}

		else if ((destY == y) && (destX == x + 1) ||
			(destY == y) && (destX == x - 1) ||
			(destY == y) && (destX == x + 2) ||
			(destY == y) && (destX == x - 2) ||
			(destY == y) && (destX == x + 3) ||
			(destY == y) && (destX == x - 3))
		{
			return true;
		}

		else
			return false;
	}
}

Trayectoria Pablo::getTrayectoria(Vector2D origen, Vector2D destino)
{
	Trayectoria t;

	return t;
}

char Pablo::tipoPieza()
{
	return 'SS';
}
