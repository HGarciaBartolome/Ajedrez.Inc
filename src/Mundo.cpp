#include "Mundo.h"

Mundo::Mundo()
{
	//Inicializamos el mundo con modo COMIENZO y NO final
	m = COMIENZO;
	f = NO;
}


void Mundo::tecla(unsigned char key)
{
	//Manejamos las teclas para seleccionar modos de juego o ayuda
	switch (m) {

	case 0:	//COMIENZO
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

	case 4:	//AYUDA
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
		if (key == 'M' || key == 'm')	//si se pulsa M se vuelve al Menu Principal
		{
			m = COMIENZO;
		}
		if (key == 'e' || key == 'E')
		{
			exit(0);
		}
	}

	//Si es final de partida y se pulsa e o E sale del juego
	if (f == J1 || f == J2)
	{
		if (key == 'e' || key == 'E') {
			exit(0);
		}
	}
}

void Mundo::dibuja() {

	//Si es el comienzo se imprime el menu
	if (m == COMIENZO) {
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0);

		//Ponemos fondo a la pantalla de incicio)
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Menu.png").id);


		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-14.5, -3.4, -0.1);
		glTexCoord2d(1, 1); glVertex3f(14.5, -3.4, -0.1);
		glTexCoord2d(1, 0); glVertex3f(14.5, 18.5, -0.1);
		glTexCoord2d(0, 0); glVertex3f(-14.5, 18.5, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

	}

	//si el modo ahora es PVPclasico y no ha acabado, se dibuja el tablero
	else if (m == chessClasico && f == NO)
	{
	
		/*ETSIDI::play("sonidos/juego.mp3");*/

		gluLookAt(x_ojo, y_ojo, z_ojo,
			4.0, y_ojo, 0.0,
			0.0, 1.0, 0.0);

		tablero.dibuja();
		if (!tablero.estaInicializado())
			tablero.Inicializa();

		if (tablero.f == J1) {
			f = J1;
			ETSIDI::play("sonidos/Victoria.flac");
		}
		else if (tablero.f == J2) {
			f = J2;
			ETSIDI::play("sonidos/Victoria.flac");
		}
	}

	//si el juego esta en ayuda se muestra la pantalla de ayuda
	else if (m == AYUDA) {
		gluLookAt(0, 0, 55, // posicion del ojo
			-0.0, 0, -0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/ayuda.png").id);
		
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-26.7, -20, -0.1);
		glTexCoord2d(1, 1); glVertex3f(26.7, -20, -0.1);
		glTexCoord2d(1, 0); glVertex3f(26.7, 20, -0.1);
		glTexCoord2d(0, 0); glVertex3f(-26.7,20 ,-0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		ETSIDI::setTextColor(1,1,1);
		ETSIDI::setFont("bitwise.ttf",18);
		ETSIDI::printxy("Pulse E para salir", -25, -19,5);
	}

	//si el modo ahora es chess960 y no ha acabado, se dibuja el tablero 960
	else if (m == chess960 && f == NO)
	{
		/*ETSIDI::play("sonidos/juego.mp3");*/

		gluLookAt(x_ojo, y_ojo, z_ojo,
			4.0, y_ojo, 0.0,
			0.0, 1.0, 0.0);

		tablero.dibuja2();
		if (!tablero.estaInicializado2())
			tablero.Inicializa2();

		if (tablero.f == J1)
			f = J1;
		else if (tablero.f == J2)
			f = J2;
	}

	//si el modo ahora es chessETSIDI y no ha acabado, se dibuja el tablero ETSIDI
	else if (m == chessETSIDI && f == NO)
	{
		/*ETSIDI::play("sonidos/juego.mp3");*/

		gluLookAt(x_ojo, y_ojo, z_ojo,
			4.0, y_ojo, 0.0,
			0.0, 1.0, 0.0);

		tablero.dibuja3();
		if (!tablero.estaInicializado3())
			tablero.Inicializa3();

		if (tablero.f == J1)
			f = J1;
		else if (tablero.f == J2)
			f = J2;
	}

	//acaba el PVPclasico y gana el J1
	else if (f == J1 && m == chessClasico)
	{
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/GanaJ1.png").id);

		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-15, -3.4, -0.1);
		glTexCoord2d(1, 1); glVertex3f(15, -3.4, -0.1);
		glTexCoord2d(1, 0); glVertex3f(15, 18.5, -0.1);
		glTexCoord2d(0, 0); glVertex3f(-15, 18.5, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

	}
	//acaba el PVPclasico y gana el J2
	else if (f == J2 && m == chessClasico)
	{
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/GanaJ2.png").id);

		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-15, -3.4, -0.1);
		glTexCoord2d(1, 1); glVertex3f(15, -3.4, -0.1);
		glTexCoord2d(1, 0); glVertex3f(15, 18.5, -0.1);
		glTexCoord2d(0, 0); glVertex3f(-15, 18.5, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

	}

	//acaba el chess960 y gana el J1
	else if (f == J1 && m == chess960)
	{
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/GanaJ1.png").id);

		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-15, -3.4, -0.1);
		glTexCoord2d(1, 1); glVertex3f(15,-3.4, -0.1);
		glTexCoord2d(1, 0); glVertex3f(15, 18.5, -0.1);
		glTexCoord2d(0, 0); glVertex3f(-15, 18.5, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

	}
	//acaba el chess960 y gana el J2
	else if (f == J2 && m == chess960)
	{
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/GanaJ2.png").id);

		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-15, -3.4, -0.1);
		glTexCoord2d(1, 1); glVertex3f(15, -3.4, -0.1);
		glTexCoord2d(1, 0); glVertex3f(15, 18.5, -0.1);
		glTexCoord2d(0, 0); glVertex3f(-15, 18.5, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

	}

	//acaba el chessETSIDI y gana el J1
	else if (f == J1 && m == chessETSIDI)
	{
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/GanaJ1.png").id);

		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-15, -3.4, -0.1);
		glTexCoord2d(1, 1); glVertex3f(15, -3.4, -0.1);
		glTexCoord2d(1, 0); glVertex3f(15, 18.5, -0.1);
		glTexCoord2d(0, 0); glVertex3f(-15, 18.5, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

	}

	//acaba el chess960 y gana el J2
	else if (f == J2 && m == chessETSIDI)
	{
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/GanaJ2.png").id);

		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-15, -3.4, -0.1);
		glTexCoord2d(1, 1); glVertex3f(15, -3.4, -0.1);
		glTexCoord2d(1, 0); glVertex3f(15, 18.5, -0.1);
		glTexCoord2d(0, 0); glVertex3f(-15, 18.5, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

	}
}

void Mundo::inicializa()
{
	//Inicializamos las coordenadas de nuestra perpectiva
	x_ojo = 4;
	y_ojo = 4;
	z_ojo = 15;
}

void Mundo::Mouse(int button, int state, int x, int y)
{
	//Creacion de vectores para cada casilla mediante el cursor
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
	{

		Vector2D v = getVectorDesdeCoordenadas(x, y);

		//Llamadas a funciones para Iluminar y Desiluminar las casillas
		tablero.desilumina(v);
		tablero.ilumina(v);

		// Si NO hay casilla seleccionada O (el movimiento NO es válido O que haya ya una pieza del mismo color Y NO hay posible enroque)
		if (!tablero.hayCasillaSeleccionada() ||
			(!tablero.getCasillaSeleccionada().getPieza()->movValido(v.x, v.y, Indefinido) || tablero.hayPiezaDelMismoColor(v)) && !tablero.posibleEnroque(v))
			tablero.seleccionarCasilla(v);
		else
			tablero.hacerMovimiento(v);	//Llamada para hacer movimiento oportuno
	}
}

Vector2D Mundo::getVectorDesdeCoordenadas(int x, int y)
{
	Vector2D res;
	const int MIN_X = 153; // Comienzo en el eje X de las casillas
	const int MAX_Y = 547; // Comienzo en el eje Y de las casillas
	const int OFFSET = 54;  // Desplazamiento entre casillas

	res.x = static_cast<int>((x - MIN_X) / OFFSET);
	res.y = static_cast<int>((MAX_Y - y) / OFFSET);

	return res;
}
