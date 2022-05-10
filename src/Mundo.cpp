#include "Mundo.h"
#include "Peon.h"
#include "Torre.h"
#include "Alfil.h"
#include "Reina.h"
#include "Rey.h"
#include <math.h>

Mundo::Mundo()
{
	//Se inicializa nuestro mundo con modo comienzo y no final
	m = COMIENZO;
	f = NO;
}

Mundo::~Mundo()
{
}

void Mundo::tecla(unsigned char key)
{
	if (m == COMIENZO)
	{
		if (key == '1')
		{
			m = PVP;
		}
		if (key == '2')
		{
			m = AYUDA;
		}
		if (key == 'e' || key == 'E') {
			exit(0);
		}
	}
	if (m == AYUDA)
	{
		if (key == '1')
		{
			m = PVP;
		}
		if (key == 'e' || key == 'E')
		{
			exit(0);
		}
	}
	if (f == J1 || f == J2)
	{
		if (key == 'e' || key == 'E') {
			exit(0);
		}
	}
	if (m == AYUDA)
	{
		if (key == 'M' || key == 'm') {
			m = COMIENZO;
		}
	}
}

void Mundo::dibuja() {

	//si el juego esta en modo INICIO se imprime por pantalla un menu
	if (m == COMIENZO) {
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		//Ponemos fondo a la pantalla de incicio)
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/menu.png").id);
		//dibujo del plano donde est� la foto
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-15, -3.5, -0.1);
		glTexCoord2d(1, 1); glVertex3f(15, -3.5, -0.1); //se elige donde poner la imagen de fondo. ponemos -0.1 en z para que est� de fondo
		glTexCoord2d(1, 0); glVertex3f(15, 20, -0.1);
		glTexCoord2d(0, 0); glVertex3f(-15, 20, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}

		//si el modo ahora es PVP y no ha acabado, se dibuja el tablero
	else if (m == PVP && f == NO)
	{
		gluLookAt(x_ojo, y_ojo, z_ojo,
			4.0, y_ojo, 0.0,
			0.0, 1.0, 0.0);

		tablero.dibuja();
		piezas.dibuja();
	}
	//si el juego esta en REGLAS se facilitan por pantalla las reglas del juego
	else if (m == AYUDA) {
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		//Ponemos fondo a la pantalla de incicio)
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/ayuda.png").id);
		//dibujo del plano donde est� la foto
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-15, -3.5, -0.1);
		glTexCoord2d(1, 1); glVertex3f(15, -3.5, -0.1); //se elige donde poner la imagen de fondo. ponemos -0.1 en z para que est� de fondo
		glTexCoord2d(1, 0); glVertex3f(15, 20, -0.1);
		glTexCoord2d(0, 0); glVertex3f(-15, 20, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
	//acaba el PVP y gana el J1
	else if (f == J1 && m == PVP)
	{
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		//Ponemos fondo a la pantalla de incicio)
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/GanaJ1.png").id);
		//dibujo del plano donde est� la foto
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-15, -3.5, -0.1);
		glTexCoord2d(1, 1); glVertex3f(15, -3.5, -0.1); //se elige donde poner la imagen de fondo. ponemos -0.1 en z para que est� de fondo
		glTexCoord2d(1, 0); glVertex3f(15, 20, -0.1);
		glTexCoord2d(0, 0); glVertex3f(-15, 20, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

	}
	//acaba el PVP y gana el J2
	else if (f == J2 && m == PVP)
	{
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		//Ponemos fondo a la pantalla de incicio)
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/GanaJ2.png").id);
		//dibujo del plano donde est� la foto
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-15, -3.5, -0.1);
		glTexCoord2d(1, 1); glVertex3f(15, -3.5, -0.1); //se elige donde poner la imagen de fondo. ponemos -0.1 en z para que est� de fondo
		glTexCoord2d(1, 0); glVertex3f(15, 20, -0.1);
		glTexCoord2d(0, 0); glVertex3f(-15, 20, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

	}
	
}

void Mundo::inicializa()
{
	x_ojo = 4;
	y_ojo = 4;
	z_ojo = 15;

	for (int i = 0; i < 8; i++) {
		Peon* auxp1 = new Peon(FALSE, i, 1);
		piezas.agregarPeon(auxp1);
		Peon* auxp = new Peon(TRUE, i, 6);
		piezas.agregarPeon(auxp);
	}
	for (int i = 0; i < 2; i++) {
		Torre* auxt1 = new Torre(FALSE, i*7, 0);
		piezas.agregarTorre(auxt1);
		Torre* auxt = new Torre(TRUE, i*7, 7);
		piezas.agregarTorre(auxt);
	}

	for (int i = 0; i < 2; i++) {
		Alfil* auxa = new Alfil(FALSE, abs((i * 7)-2), 0);
		piezas.agregarAlfil(auxa);
		Alfil* auxa1 = new Alfil(TRUE, abs((i * 7) - 2), 7);
		piezas.agregarAlfil(auxa1);
	}

	Reina* auxr1 = new Reina(FALSE,  3, 0);
	piezas.agregarReina(auxr1);
	Reina* auxr = new Reina(TRUE, 4, 7);
	piezas.agregarReina(auxr);

	Rey* auxk1 = new Rey(FALSE, 4, 0);
	piezas.agregarRey(auxk1);
	Rey* auxk = new Rey(TRUE, 3, 7);
	piezas.agregarRey(auxk);
	
}

void Mundo::Mouse(int button, int state, int x, int y)
{
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
	{

		if (x >= 153 && x < 207) {
			
			v.x = 0;
			if (y >= 493 && y < 547) v.y = 0;
			if (y >= 438 && y < 493) v.y = 1;
			if (y >= 383 && y < 438) v.y = 2;
			if (y >= 328 && y < 383) v.y = 3;
			if (y >= 273 && y < 326) v.y = 4;
			if (y >= 218 && y < 273) v.y = 5;
			if (y >= 163 && y < 218) v.y = 6;
			if (y >= 108 && y < 163) v.y = 7;
		};
		if (x >= 207 && x < 263) {

			v.x = 1;
			if (y >= 493 && y < 547) v.y = 0;
			if (y >= 438 && y < 493) v.y = 1;
			if (y >= 383 && y < 438) v.y = 2;
			if (y >= 328 && y < 383) v.y = 3;
			if (y >= 273 && y < 328) v.y = 4;
			if (y >= 218 && y < 273) v.y = 5;
			if (y >= 163 && y < 218) v.y = 6;
			if (y >= 108 && y < 163) v.y = 7;
		}
		if (x >= 263 && x < 318) {

			v.x = 2;
			if (y >= 493 && y < 547) v.y = 0;
			if (y >= 438 && y < 493) v.y = 1;
			if (y >= 383 && y < 438) v.y = 2;
			if (y >= 328 && y < 383) v.y = 3;
			if (y >= 273 && y < 328) v.y = 4;
			if (y >= 218 && y < 273) v.y = 5;
			if (y >= 163 && y < 218) v.y = 6;
			if (y >= 108 && y < 163) v.y = 7;
		}
		if (x >= 318 && x < 373) {

			v.x = 3;
			if (y >= 493 && y < 547) v.y = 0;
			if (y >= 438 && y < 493) v.y = 1;
			if (y >= 383 && y < 438) v.y = 2;
			if (y >= 328 && y < 383) v.y = 3;
			if (y >= 273 && y < 328) v.y = 4;
			if (y >= 218 && y < 273) v.y = 5;
			if (y >= 163 && y < 218) v.y = 6;
			if (y >= 108 && y < 163) v.y = 7;
		}
		if (x >= 373 && x < 428) {
			v.x = 4;
			if (y >= 493 && y < 547) v.y = 0;
			if (y >= 438 && y < 493) v.y = 1;
			if (y >= 383 && y < 438) v.y = 2;
			if (y >= 328 && y < 383) v.y = 3;
			if (y >= 273 && y < 328) v.y = 4;
			if (y >= 218 && y < 273) v.y = 5;
			if (y >= 163 && y < 218) v.y = 6;
			if (y >= 108 && y < 163) v.y = 7;
		}
		if (x >= 428 && x < 483) {

			v.x = 5;
			if (y >= 493 && y < 547) v.y = 0;
			if (y >= 438 && y < 493) v.y = 1;
			if (y >= 383 && y < 438) v.y = 2;
			if (y >= 328 && y < 383) v.y = 3;
			if (y >= 273 && y < 328) v.y = 4;
			if (y >= 218 && y < 273) v.y = 5;
			if (y >= 163 && y < 218) v.y = 6;
			if (y >= 108 && y < 163) v.y = 7;
		}
		if (x >= 483 && x < 538) {

			v.x = 6;
			if (y >= 493 && y < 547) v.y = 0;
			if (y >= 438 && y < 493) v.y = 1;
			if (y >= 383 && y < 438) v.y = 2;
			if (y >= 328 && y < 383) v.y = 3;
			if (y >= 273 && y < 328) v.y = 4;
			if (y >= 218 && y < 273) v.y = 5;
			if (y >= 163 && y < 218) v.y = 6;
			if (y >= 108 && y < 163) v.y = 7;
		}
		if (x >= 538 && x < 593) {
			v.x = 7;
			if (y >= 493 && y < 547) v.y = 0;
			if (y >= 438 && y < 493) v.y = 1;
			if (y >= 383 && y < 438) v.y = 2;
			if (y >= 328 && y < 383) v.y = 3;
			if (y >= 273 && y < 328) v.y = 4;
			if (y >= 218 && y < 273) v.y = 5;
			if (y >= 163 && y < 218) v.y = 6;
			if (y >= 108 && y < 163) v.y = 7;
		}

	}

	tablero.ilumina(v);


	//FUNCIONES DE SELECCIONAR CASILLAS

	tablero.seleccionarCasilla(v);

}
