#include "Mundo.h"
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
			m = chessClasico;
		}
		if (key == '2')
		{
			m = chess960;
		}
		if (key == '3')
		{
			m = chessETSIDI;
		}
		if (key == '4')
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
			m = chessClasico;
		}
		if (key == '2')
		{
			m = chess960;
		}
		if (key == '3')
		{
			m = chessETSIDI;
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
		//dibujo del plano donde está la foto
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-15, -3.5, -0.1);
		glTexCoord2d(1, 1); glVertex3f(15, -3.5, -0.1); //se elige donde poner la imagen de fondo. ponemos -0.1 en z para que esté de fondo
		glTexCoord2d(1, 0); glVertex3f(15, 20, -0.1);
		glTexCoord2d(0, 0); glVertex3f(-15, 20, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		/////////////////
		//meter sonido menu principal
		////////////////
	}

	//si el modo ahora es PVPclasico y no ha acabado, se dibuja el tablero
	else if (m == chessClasico && f == NO)
	{
		gluLookAt(x_ojo, y_ojo, z_ojo,
			4.0, y_ojo, 0.0,
			0.0, 1.0, 0.0);

		tablero.dibuja();
		if (!tablero.estaInicializado())
			tablero.Inicializa();
	}
	//si el juego esta en REGLAS se facilitan por pantalla las reglas del juego
	else if (m == AYUDA) {
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		//Ponemos fondo a la pantalla de incicio)
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/ayuda.png").id);
		//dibujo del plano donde está la foto
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-15, -3.5, -0.1);
		glTexCoord2d(1, 1); glVertex3f(15, -3.5, -0.1); //se elige donde poner la imagen de fondo. ponemos -0.1 en z para que esté de fondo
		glTexCoord2d(1, 0); glVertex3f(15, 20, -0.1);
		glTexCoord2d(0, 0); glVertex3f(-15, 20, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}

	//si el modo ahora es chess960 y no ha acabado, se dibuja el tablero
	else if (m == chess960 && f == NO)
	{
		gluLookAt(x_ojo, y_ojo, z_ojo,
			4.0, y_ojo, 0.0,
			0.0, 1.0, 0.0);

		tablero.dibuja2();
		if (!tablero.estaInicializado2())
			tablero.Inicializa2();
	}

	//si el modo ahora es chessETSIDI y no ha acabado, se dibuja el tablero
	else if (m == chessETSIDI && f == NO)
	{
		gluLookAt(x_ojo, y_ojo, z_ojo,
			4.0, y_ojo, 0.0,
			0.0, 1.0, 0.0);

		tablero.dibuja3();
		if (!tablero.estaInicializado3())
			tablero.Inicializa3();
	}

	//acaba el PVPclasico y gana el J1
	else if (f == J1 && m == chessClasico)
	{
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		//Ponemos fondo a la pantalla de incicio)
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/GanaJ1.png").id);
		//dibujo del plano donde está la foto
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-15, -3.5, -0.1);
		glTexCoord2d(1, 1); glVertex3f(15, -3.5, -0.1); //se elige donde poner la imagen de fondo. ponemos -0.1 en z para que esté de fondo
		glTexCoord2d(1, 0); glVertex3f(15, 20, -0.1);
		glTexCoord2d(0, 0); glVertex3f(-15, 20, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

	}
	//acaba el PVPclasico y gana el J2
	else if (f == J2 && m == chessClasico)
	{
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		//Ponemos fondo a la pantalla de incicio)
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/GanaJ2.png").id);
		//dibujo del plano donde está la foto
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-15, -3.5, -0.1);
		glTexCoord2d(1, 1); glVertex3f(15, -3.5, -0.1); //se elige donde poner la imagen de fondo. ponemos -0.1 en z para que esté de fondo
		glTexCoord2d(1, 0); glVertex3f(15, 20, -0.1);
		glTexCoord2d(0, 0); glVertex3f(-15, 20, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

	}

	//acaba el chess960 y gana el J1
	else if (f == J1 && m == chess960)
	{
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		//Ponemos fondo a la pantalla de incicio)
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/GanaJ1.png").id);
		//dibujo del plano donde está la foto
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-15, -3.5, -0.1);
		glTexCoord2d(1, 1); glVertex3f(15, -3.5, -0.1); //se elige donde poner la imagen de fondo. ponemos -0.1 en z para que esté de fondo
		glTexCoord2d(1, 0); glVertex3f(15, 20, -0.1);
		glTexCoord2d(0, 0); glVertex3f(-15, 20, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

	}
	//acaba el chess960 y gana el J2
	else if (f == J2 && m == chess960)
	{
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		//Ponemos fondo a la pantalla de incicio)
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/GanaJ2.png").id);
		//dibujo del plano donde está la foto
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-15, -3.5, -0.1);
		glTexCoord2d(1, 1); glVertex3f(15, -3.5, -0.1); //se elige donde poner la imagen de fondo. ponemos -0.1 en z para que esté de fondo
		glTexCoord2d(1, 0); glVertex3f(15, 20, -0.1);
		glTexCoord2d(0, 0); glVertex3f(-15, 20, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

	}
	//acaba el chessETSIDI y gana el J1
	else if (f == J1 && m == chessETSIDI)
	{
	gluLookAt(0, 7.5, 30, // posicion del ojo
		0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
	//Ponemos fondo a la pantalla de incicio)
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/GanaJ1.png").id);
	//dibujo del plano donde está la foto
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(-15, -3.5, -0.1);
	glTexCoord2d(1, 1); glVertex3f(15, -3.5, -0.1); //se elige donde poner la imagen de fondo. ponemos -0.1 en z para que esté de fondo
	glTexCoord2d(1, 0); glVertex3f(15, 20, -0.1);
	glTexCoord2d(0, 0); glVertex3f(-15, 20, -0.1);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	}
	//acaba el chess960 y gana el J2
	else if (f == J2 && m == chessETSIDI)
	{
	gluLookAt(0, 7.5, 30, // posicion del ojo
		0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
	//Ponemos fondo a la pantalla de incicio)
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/GanaJ2.png").id);
	//dibujo del plano donde está la foto
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(-15, -3.5, -0.1);
	glTexCoord2d(1, 1); glVertex3f(15, -3.5, -0.1); //se elige donde poner la imagen de fondo. ponemos -0.1 en z para que esté de fondo
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

		tablero.desilumina(v);
		tablero.ilumina(v);

		// Si NO hay casilla seleccionada O (el movimiento NO es válido O que haya ya una pieza del mismo color Y NO hay posible enroque)
		if (!tablero.hayCasillaSeleccionada() ||
			(!tablero.getCasillaSeleccionada().getPieza()->movValido(v.x, v.y, Indefinido) || tablero.hayPiezaDelMismoColor(v)) && !tablero.posibleEnroque(v))
			tablero.seleccionarCasilla(v);
		else
			tablero.hacerMovimiento(v);
	}



}
