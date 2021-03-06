#include "Torre.h"
#include "ETSIDI.h"
#include "freeglut.h"
#include "Piezas.h"
#define limite 0.5

Torre::Torre(ColorPieza _color, Vector2D v)
{
	color = _color;
	posicion = v;
}

void Torre::Dibuja()
{
	if (color == ColorPieza::Blanca) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Tb.png").id);
		glDisable(GL_LIGHTING);
	}
	else
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Tn.png").id);
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

void Torre::Dibuja2()
{
	if (color == ColorPieza::Blanca) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Tb960.png").id);
		glDisable(GL_LIGHTING);
	}
	else
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Tn960.png").id);
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

bool Torre::movValido(int destX, int destY, ColorPieza c)
{
	if ((destX == Pieza::getPosicionX()) && (destY == Pieza::getPosicionY())) {
		return false;
	}
	else {
		if ((destX == Pieza::getPosicionX()) || (destY == Pieza::getPosicionY())) {
			return true;
		}
		else {
			return false;
		}
	}
}

Trayectoria Torre::getTrayectoria(Vector2D origen, Vector2D destino)
{
	Trayectoria t;

	int signo_x = 1;
	int signo_y = 1;
	if (destino.x < origen.x) {
		signo_x = -1;
	}

	if (destino.y < origen.y) {
		signo_y = -1;
	}

	Vector2D aux = origen;
	while (!(aux == destino)) {
		if ((destino.y == aux.y))
			aux.x = aux.x + signo_x;

		else if ((destino.x == aux.x))
			aux.y = aux.y + signo_y;

		t.push_back(aux);
	}

	return t;

}

char Torre::tipoPieza()
{
	return 'T';
}
