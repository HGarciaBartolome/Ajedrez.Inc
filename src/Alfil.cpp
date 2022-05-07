#include "Alfil.h"
#include "ETSIDI.h"
#include "freeglut.h"
void Alfil::Dibuja()
{
	if (color == FALSE) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Ab.png").id);
		glDisable(GL_LIGHTING);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(posicion.x - limite.x, posicion.y - limite.y, 0.01);
		glTexCoord2d(1, 1); glVertex3f(posicion.x + limite.x, posicion.y - limite.y, 0.01); //se elige donde poner la imagen de fondo. ponemos -0.1 en z para que esté de fondo
		glTexCoord2d(1, 0); glVertex3f(posicion.x + limite.x, posicion.y + limite.y, 0.01);
		glTexCoord2d(0, 0); glVertex3f(posicion.x - limite.x, posicion.y + limite.y, 0.01);
		glEnd();
		glDisable(GL_BLEND);
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
	else if (color == TRUE) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/An.png").id);
		glDisable(GL_LIGHTING);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(posicion.x - limite.x, posicion.y - limite.y, 0.01);
		glTexCoord2d(1, 1); glVertex3f(posicion.x + limite.x, posicion.y - limite.y, 0.01); //se elige donde poner la imagen de fondo. ponemos -0.1 en z para que esté de fondo
		glTexCoord2d(1, 0); glVertex3f(posicion.x + limite.x, posicion.y + limite.y, 0.01);
		glTexCoord2d(0, 0); glVertex3f(posicion.x - limite.x, posicion.y + limite.y, 0.01);
		glEnd();
		glDisable(GL_BLEND);
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
 
}

void Alfil::mueve(Vector2D)
{
}
