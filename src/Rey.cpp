#include "Rey.h"
#include "ETSIDI.h"
#include "freeglut.h"
#define limite 0.5

Rey::Rey(ColorPieza _color, int _x, int _y)
{
	color = _color;
	posicion.x = _x;
	posicion.y = _y;
}

void Rey::Dibuja()
{
	if (color == ColorPieza::Blanca) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Kb.png").id);
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
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Kn.png").id);
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

bool Rey::movValido(int destX, int destY, ColorPieza c)
{
	int x = Pieza::getPosicionX();
	int y = Pieza::getPosicionY();

	if (destY == y + 1) // si el destino es hacia arriba
		if (destX == x - 1) // y en diagonal izquierda
			return true;
		else if (destX == x)//misma columna
			return true;
		else if (destX == x + 1) // en diagonal derecha
			return true;
		else
			return false;


	else if (destY == y) //si el destino es en la misma fila
		if (destX == x - 1) //hacia la izquierda
			return true;
		else if (destX == x + 1)//hacia la derecha
			return true;
		else
			return false;


	else if (destY == y - 1) //si el destino es hacia abajo 
		if (destX == x - 1)//hacia la izquierda
			return true;
		else if (destX == x) //misma columna
			return true;
		else if (destX == x + 1)//hacia la derecha
			return true;
		else
			return false;


	else
		return false;
}

Vector2D* Rey::getTrayectoria(Vector2D origen, Vector2D destino)
{
	Vector2D* trayectoria = new Vector2D();

	//TODO: assignment
	unsigned int index = 0;

	origen == destino;

	trayectoria[index] = Vector2D(-1, -1); // Marcar final de trayectoria

	return trayectoria;
}
