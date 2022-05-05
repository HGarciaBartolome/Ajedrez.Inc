
#include "Torre.h"
#include "ETSIDI.h"
#include "freeglut.h"
#include "Piezas.h"


void Torre::Dibuja()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Cb.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(-0.5, -0.5, 0.01);
	glTexCoord2d(1, 1); glVertex3f(0.5, -0.5, 0.01); //se elige donde poner la imagen de fondo. ponemos -0.1 en z para que esté de fondo
	glTexCoord2d(1, 0); glVertex3f(0.5, 0.5, 0.01);
	glTexCoord2d(0, 0); glVertex3f(-0.5, 0.5, 0.01);
	glEnd();	
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void Torre::mueve(Vector2D)
{
}
