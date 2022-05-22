#include "Miguel.h"
#include "ETSIDI.h"
#include "freeglut.h"
#define limite 0.5

Miguel::Miguel(ColorPieza _color, Vector2D v)
{
	color = _color;
	posicion = v;
}

void Miguel::Dibuja3()
{
	if (color == ColorPieza::Blanca) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/CbETSIDI.png").id);	//poner miguel blanco
		glDisable(GL_LIGHTING);
	}
	else //if (color == ColorPieza::Negra)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/CnETSIDI.png").id);		//poner miguel negro
		glDisable(GL_LIGHTING);
	}
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

bool Miguel::movValido(int destX, int destY, ColorPieza c)
{
	int x = Pieza::getPosicionX();
	int y = Pieza::getPosicionY();

	if (((abs(x - destX) == 1) && (abs(y - destY) == 3)) || ((abs(x - destX) == 3) && (abs(y - destY == 1))))
		return true;

	else if (x == destX || y == destY) {
		return false;
	}
	else if ((destY - y) / (destX - x) == 1 || (destY - y) / (destX - x) == -1) {
		return false;
	}
	else if (x > destX) {
		if (x - destX > 3) {
			return false;
		}
	}
	else if (destX > x) {
		if (destX - x > 3) {
			return false;
		}
	}
	else if (y > destY) {
		if (y - destY > 3) {
			return false;
		}
	}
	else if (destY > y) {
		if (destY - y > 3) {
			return false;
		}
	}

}

Trayectoria Miguel::getTrayectoria(Vector2D origen, Vector2D destino)
{
	Trayectoria t;

	return t;
}

char Miguel::tipoPieza()
{
	return 'MH';
}
