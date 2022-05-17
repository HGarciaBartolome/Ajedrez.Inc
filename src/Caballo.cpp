#include "Caballo.h"
#include <math.h>

#define limite 0.5

Caballo::Caballo(ColorPieza _color, int _x, int _y)
{
	color = _color;
	posicion.x = _x;
	posicion.y = _y;
}

void Caballo::Dibuja()
{
	if (color == ColorPieza::Blanca) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Cb.png").id);
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
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Cn.png").id);
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

bool Caballo::movValido(int destX, int destY, ColorPieza c)
{
	int x = Pieza::getPosicionX();
	int y = Pieza::getPosicionY();

	if (((abs(x - destX) == 1) && (abs(y - destY) == 2)) || ((abs(x - destX) == 2) && (abs(y - destY == 1)))) {

		if (x == destX || y == destY) {
			return false;
		}
		else if ((destY - y) / (destX - x) == 1 || (destY - y) / (destX - x) == -1) {
			return false;
		}
		else if (x > destX) {
			if (x - destX > 2) {
				return false;
			}
		}
		else if (destX > x) {
			if (destX - x > 2) {
				return false;
			}
		}
		else if (y > destY) {
			if (y - destY > 2) {
				return false;
			}
		}
		else if (destY > y) {
			if (destY - y > 2) {
				return false;
			}
		}
		else
			return true;
	}
	else
		return false;
}

Vector2D* Caballo::getTrayectoria(Vector2D origen, Vector2D destino)
{
	Vector2D* trayectoria = new Vector2D();

	//TODO: assignment
	unsigned int index = 0;

	origen == destino;

	trayectoria[index] = Vector2D(-1, -1); // Marcar final de trayectoria

	return trayectoria;
}