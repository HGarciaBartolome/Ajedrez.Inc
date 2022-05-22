#include "Cristobal.h"
#include "ETSIDI.h"
#include "freeglut.h"
#define limite 0.5

Cristobal::Cristobal(ColorPieza _color, Vector2D v)
{
	color = _color;
	posicion = v;
}

void Cristobal::Dibuja3()
{
	if (color == ColorPieza::Blanca) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/TbETSIDI.png").id);	//poner cristobal blanco
		glDisable(GL_LIGHTING);
	}
	else// if (color == ColorPieza::Negra)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/TnETSIDI.png").id);		//poner cristobal negro
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

bool Cristobal::movValido(int destX, int destY, ColorPieza c)
{
	int x = Pieza::getPosicionX();
	int y = Pieza::getPosicionY();


	if ((destX > x && destY < y) ||		//si el movimiento es abajo a la derecha o arriba izquierda
		(destX<x && destY>y))
	{
		if ((destX == x + 1) && (destY == y - 1) ||
			(destX == x + 2) && (destY == y - 2) ||
			(destX == x - 1) && (destY == y + 1) ||
			(destX == x - 2) && (destY == y + 2))
	
			return true;
		else
			return false;
	}
	else if ((destX < x && destY < y) ||
		(destX > x && destY > y))
	{												//si el movimiento es abajo izquierda o arriba derecha
		if ((destX == x + 1) && (destY == y + 1) ||
			(destX == x + 2) && (destY == y + 2) ||
			(destX == x - 1) && (destY == y - 1) ||
			(destX == x - 2) && (destY == y - 2))
			
			return true;
		else
			return false;
	}

	else
		return false;
}

char Cristobal::tipoPieza()
{
	return 'CT';
}

Trayectoria Cristobal::getTrayectoria(Vector2D origen, Vector2D destino)
{
	Trayectoria t;

	return t;
}

