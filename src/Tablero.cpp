#include "Tablero.h"
#include <iostream>
#include <string>
#include <time.h>

#define NCASILLAS 8

Tablero::Tablero() : inicializado(false), inicializado2(false) {
	
	Casilla c;
	c.setPos(Vector2D(-1, -1));	//ninguna casilla seleccionada

	casillaSeleccionada = c;
	
	bool Negro = true;

	for (int i = 0;i < NCASILLAS;i++)
	{
		for (int j = 0;j < NCASILLAS;j++)
		{
			casilla[i][j].setPos(Vector2D(i, j));

			if (Negro)
				casilla[i][j].setColor(84, 56, 34);
			else
				casilla[i][j].setColor(171, 139, 98);

			if (j != NCASILLAS - 1)
				Negro = !Negro;
		}
	}
}

void Tablero::dibuja(){

	for (int i = 0; i < NCASILLAS;i++) {
		for (int j = 0; j < NCASILLAS ;j++) {
			casilla[i][j].dibuja();
		}
	}
	
	//MARCO DEL TABLERO
	glDisable(GL_LIGHTING);
	glColor3ub(137, 107, 73);
	glBegin(GL_QUADS);
	glVertex3f(-1.0f, -1.0f, -0.1f);
	glVertex3f(8.0f, -1.0f, -0.1f);
	glVertex3f(8.0f, 8.0f, -0.1f);
	glVertex3f(-1.0f, 8.0f, -0.1f);
	glEnd();


	glBegin(GL_QUADS);
	glVertex3f(-1.0f, -1.0f, -0.6f);
	glVertex3f(8.0f, -1.0f, -0.6f);
	glVertex3f(8.0, -1.0f, -0.1f);
	glVertex3f(-1.0f, -1.0f, -0.1f);
	glEnd();
	glEnable(GL_LIGHTING);
	

	
	//FONDO DE PANTALLA DEL TABLERO
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondoTablero.png").id);
	
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(-30, -10, -1);
	glTexCoord2d(1, 1); glVertex3f(30, -10, -1); 
	glTexCoord2d(1, 0); glVertex3f(30, 35, -1);
	glTexCoord2d(0, 0); glVertex3f(-30, 35, -1);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	if (estaInicializado()) {
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				casilla[i][j].getPieza()->Dibuja();
	}
	
}

void Tablero::dibuja2() {

	for (int i = 0; i < NCASILLAS; i++) {
		for (int j = 0; j < NCASILLAS; j++) {
			casilla[i][j].dibuja();
		}
	}

	//MARCO DEL TABLERO
	glDisable(GL_LIGHTING);
	glColor3ub(137, 107, 73);
	glBegin(GL_QUADS);
	glVertex3f(-1.0f, -1.0f, -0.1f);
	glVertex3f(8.0f, -1.0f, -0.1f);
	glVertex3f(8.0f, 8.0f, -0.1f);
	glVertex3f(-1.0f, 8.0f, -0.1f);
	glEnd();


	glBegin(GL_QUADS);
	glVertex3f(-1.0f, -1.0f, -0.6f);
	glVertex3f(8.0f, -1.0f, -0.6f);
	glVertex3f(8.0, -1.0f, -0.1f);
	glVertex3f(-1.0f, -1.0f, -0.1f);
	glEnd();
	glEnable(GL_LIGHTING);



	//FONDO DE PANTALLA DEL TABLERO
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondoTablero.png").id);

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(-30, -10, -1);
	glTexCoord2d(1, 1); glVertex3f(30, -10, -1);
	glTexCoord2d(1, 0); glVertex3f(30, 35, -1);
	glTexCoord2d(0, 0); glVertex3f(-30, 35, -1);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	if (estaInicializado2()) {
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				casilla[i][j].getPieza()->Dibuja();
	}

}

void Tablero::Inicializa()
{
	//VACIAS
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			casilla[i][j].setPieza(new PiezaVacia(ColorPieza::Indefinido, i, j));
		}
	}
	//BLANCAS
	casilla[0][0].setPieza(new Torre(ColorPieza::Blanca, 0, 0));
	casilla[1][0].setPieza(new Caballo(ColorPieza::Blanca, 1, 0)); // Cambiar por caballo
	casilla[2][0].setPieza(new Alfil(ColorPieza::Blanca,2,0));
	casilla[3][0].setPieza(new Reina(ColorPieza::Blanca,3,0));
	casilla[4][0].setPieza(new Rey(ColorPieza::Blanca,4,0));
	casilla[5][0].setPieza(new Alfil(ColorPieza::Blanca, 5, 0));
	casilla[6][0].setPieza(new Caballo(ColorPieza::Blanca, 6, 0));
	casilla[7][0].setPieza(new Torre(ColorPieza::Blanca, 7, 0));
	
	for ( int i = 0; i < 8; i++) {
		int j = 1;
		casilla[i][j].setPieza(new Peon(ColorPieza::Blanca,i,j));
	}

	//NEGRAS
	casilla[0][7].setPieza(new Torre(ColorPieza::Negra, 0, 7));
	casilla[1][7].setPieza(new Caballo(ColorPieza::Negra, 1, 7));
	casilla[2][7].setPieza(new Alfil(ColorPieza::Negra, 2, 7));
	casilla[3][7].setPieza(new Reina(ColorPieza::Negra, 3, 7));
	casilla[4][7].setPieza(new Rey(ColorPieza::Negra, 4, 7));
	casilla[5][7].setPieza(new Alfil(ColorPieza::Negra, 5, 7));
	casilla[6][7].setPieza(new Caballo(ColorPieza::Negra, 6, 7));
	casilla[7][7].setPieza(new Torre(ColorPieza::Negra, 7, 7));

	for ( int i = 0; i < 8; i++) {
		int j = 6;
		casilla[i][j].setPieza(new Peon(ColorPieza::Negra, i, j));
	}

	inicializado = true;
}


void Tablero::Inicializa2()
{
	//VACIAS
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			casilla[i][j].setPieza(new PiezaVacia(ColorPieza::Indefinido, i, j));
		}
	}
	//BLANCAS
	
	int b1, b2, b3, b4, b5, b6, b7, b8;

	while (1)
	{
		b1 = rand() % 8; 
		b2 = rand() % 8;
		b3 = rand() % 8;
		b4 = rand() % 8;
		b5 = rand() % 8;
		b6 = rand() % 8;
		b7 = rand() % 8;
		b8 = rand() % 8;
		if ((b1 !=b2 && b1!=b3 && b1!=b4 && b1!=b5 && b1!=b6 && b1!=b7 && b1!=b8) &&
			(b2 != b3 && b2 != b4 && b2 != b5 && b2 != b6 && b2 != b7 && b2 != b8)&&
			(b3 != b4 && b3 != b5 && b3 != b6 && b3 != b7 && b3 != b8)&&
			(b4 != b5 && b4 != b6 && b4 != b7 && b4 != b8)&&
			(b5 != b6 && b5 != b7 && b5 != b8 )&&
			(b6 != b7 && b6 != b8) &&
			(b7 != b8)) break;	//hasta que no sean distintos no salen del bucle
	}
	casilla[b1][0].setPieza(new Alfil(ColorPieza::Blanca, b1, 0));
	casilla[b2][0].setPieza(new Alfil(ColorPieza::Blanca, b2, 0));
	casilla[b3][0].setPieza(new Reina(ColorPieza::Blanca, b3, 0));
	casilla[b4][0].setPieza(new Caballo(ColorPieza::Blanca, b4, 0));
	casilla[b5][0].setPieza(new Caballo(ColorPieza::Blanca, b5, 0));
	casilla[b6][0].setPieza(new Rey(ColorPieza::Blanca, b6, 0));
	casilla[b7][0].setPieza(new Torre(ColorPieza::Blanca, b7, 0));
	casilla[b8][0].setPieza(new Torre(ColorPieza::Blanca, b8, 0));


	for (int i = 0; i < 8; i++) {
		int j = 1;
		casilla[i][j].setPieza(new Peon(ColorPieza::Blanca, i, j));
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//NEGRAS
	
	int n1, n2, n3, n4, n5, n6, n7, n8;

	while (1){
		n1 = rand() % 8;
		n2 = rand() % 8;
		n3 = rand() % 8;
		n4 = rand() % 8;
		n5 = rand() % 8;
		n6 = rand() % 8;
		n7 = rand() % 8;
		n8 = rand() % 8;

		if ((n1 != n2 && n1 != n3 && n1 != n4 && n1 != n5 && n1 != n6 && n1 != n7 && n1 != n8) &&
			(n2 != n3 && n2 != n4 && n2 != n5 && n2 != n6 && n2 != n7 && n2 != n8) &&
			(n3 != n4 && n3 != n5 && n3 != n6 && n3 != n7 && n3 != n8) &&
			(n4 != n5 && n4 != n6 && n4 != n7 && n4 != n8) &&
			(n5 != n6 && n5 != n7 && n5 != n8) &&
			(n6 != n7 && n6 != n8) &&
			(n7 != n8)) break;	//hasta que no sean distintos no salen del bucle
	}
	casilla[n1][7].setPieza(new Alfil(ColorPieza::Negra, n1, 7));
	casilla[n2][7].setPieza(new Alfil(ColorPieza::Negra, n2, 7));
	casilla[n3][7].setPieza(new Reina(ColorPieza::Negra, n3, 7));
	casilla[n4][7].setPieza(new Caballo(ColorPieza::Negra, n4, 7));
	casilla[n5][7].setPieza(new Caballo(ColorPieza::Negra, n5, 7));
	casilla[n6][7].setPieza(new Rey(ColorPieza::Negra, n6, 7));
	casilla[n7][7].setPieza(new Torre(ColorPieza::Negra, n7, 7));
	casilla[n8][7].setPieza(new Torre(ColorPieza::Negra, n8, 7));
	


	for (int i = 0; i < 8; i++) {
		int j = 6;
		casilla[i][j].setPieza(new Peon(ColorPieza::Negra, i, j));
	}
	
	srand(time(NULL));

	inicializado2 = true;
}


void Tablero::ilumina(Vector2D ilu)
{
	casilla[ilu.x][ilu.y].iluminaCasilla();
}

void Tablero::desilumina(Vector2D desilu)
{

	bool Negro = true;


	for (int i = 0; i < NCASILLAS; i++)
	{
		for (int j = 0; j < NCASILLAS; j++)
		{
			casilla[i][j].setPos(Vector2D(i, j));

			if (Negro)
				casilla[i][j].setColor(84, 56, 34);
			else
				casilla[i][j].setColor(171, 139, 98);

			if (j != NCASILLAS - 1)
				Negro = !Negro;
		}
	}

}

void Tablero::seleccionarCasilla(Vector2D pos)
{
	casillaSeleccionada = getCasilla(pos);
}

Casilla Tablero::getCasilla(Vector2D pos)
{
	return casilla[pos.x][pos.y];
}

void Tablero::hacerMovimiento(Vector2D aux)
{	
	// TODO: comprobar que se pueda hacer el movimiento -> if (pieza.movimientoValido()) 
	
	// Actualizar a vacio la vieja
	auto piezaActual = casillaSeleccionada.getPieza();
	bool mov = piezaActual->movValido(aux.x, aux.y);

	if (mov) {

		casilla[piezaActual->getPosicionX()][piezaActual->getPosicionY()].setPieza(new PiezaVacia(ColorPieza::Indefinido, -1, -1));

		// Asignar la nueva posicion
		piezaActual->setPosicion(aux.x, aux.y);
		casilla[aux.x][aux.y].setPieza(piezaActual);

		casillaSeleccionada.setPos(Vector2D(-1, -1));
	}
	//else (pensar algo)

}

bool Tablero::hayCasillaSeleccionada()
{
	return casillaSeleccionada.getPos().x != -1;	//ninguna casilla seleccionada
}

bool Tablero::esLaCasillaSeleccionada(Vector2D pos)
{
	return casillaSeleccionada.getPos().x == pos.x && casillaSeleccionada.getPos().y == pos.y;
}

Casilla Tablero::getCasillaSeleccionada()
{
	return casillaSeleccionada;
}

bool Tablero::estaInicializado()
{
	return inicializado;
}

bool Tablero::estaInicializado2()
{
	return inicializado2;
}

bool Tablero::hayPiezaDelMismoColor(Vector2D pos)
{
	return casillaSeleccionada.getPieza()->getColor() == casilla[pos.x][pos.y].getPieza()->getColor();
}