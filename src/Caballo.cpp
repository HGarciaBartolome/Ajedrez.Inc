#include "Caballo.h"

#define limite 0.5

<<<<<<<< HEAD:src/Rey.cpp
Rey::Rey(ColorPieza _color, int _x, int _y)
========
Caballo::Caballo(ColorPieza _color, int _x, int _y)
>>>>>>>> 43f3e64f2630a60d4ec5f019c94b9e2de28f503b:Ajedrez.Inc/src/Caballo.cpp
{
	color = _color;
	posicion.x = _x;
	posicion.y = _y;
}

void Caballo::Dibuja()
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

<<<<<<<< HEAD:src/Rey.cpp
bool Rey::movValido(int destX, int destY)
{
	//bool enroque = false;
	int x = Pieza::getPosicionX();
	int y = Pieza::getPosicionY();

	/*
	if (primerMov) { // si es el primer movimiento
		if (abs(destX - Pieza::getPosicionX()) == 2 && (destY == Pieza::getPosicionY())) { //y es movimiento tipo enroque
			return ENROQUE;
			enroque = true;
		}
	}
	*/

	//if (!enroque) {

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
	//}
}
========
bool Caballo::movValido(int destX, int destY)
{
	//TODO: movimiento valido del caballo
		return false;

}
>>>>>>>> 43f3e64f2630a60d4ec5f019c94b9e2de28f503b:Ajedrez.Inc/src/Caballo.cpp
