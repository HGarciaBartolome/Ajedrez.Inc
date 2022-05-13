#include "Tablero.h"

#define NCASILLAS 8

Tablero::Tablero() : inicializado(false) {
	
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
	casilla[1][0].setPieza(new PiezaVacia(ColorPieza::Blanca, 1, 0)); // Cambiar por caballo
	casilla[2][0].setPieza(new Alfil(ColorPieza::Blanca,2,0));
	casilla[3][0].setPieza(new Reina(ColorPieza::Blanca,3,0));
	casilla[4][0].setPieza(new Rey(ColorPieza::Blanca,4,0));
	casilla[5][0].setPieza(new Alfil(ColorPieza::Blanca, 5, 0));
	casilla[6][0].setPieza(new PiezaVacia(ColorPieza::Blanca, 6, 0));
	casilla[7][0].setPieza(new Torre(ColorPieza::Blanca, 7, 0));
	
	for ( int i = 0; i < 8; i++) {
		int j = 1;
		casilla[i][j].setPieza(new Peon(ColorPieza::Blanca,i,j));
	}

	//NEGRAS
	casilla[0][7].setPieza(new Torre(ColorPieza::Negra, 0, 7));
	casilla[1][7].setPieza(new PiezaVacia(ColorPieza::Negra, 1, 7));
	casilla[2][7].setPieza(new Alfil(ColorPieza::Negra, 2, 7));
	casilla[3][7].setPieza(new Reina(ColorPieza::Negra, 3, 7));
	casilla[4][7].setPieza(new Rey(ColorPieza::Negra, 4, 7));
	casilla[5][7].setPieza(new Alfil(ColorPieza::Negra, 5, 7));
	casilla[6][7].setPieza(new PiezaVacia(ColorPieza::Negra, 6, 7));
	casilla[7][7].setPieza(new Torre(ColorPieza::Negra, 7, 7));

	for ( int i = 0; i < 8; i++) {
		int j = 6;
		casilla[i][j].setPieza(new Peon(ColorPieza::Negra, i, j));
	}

	inicializado = true;
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

bool Tablero::hayPiezaDelMismoColor(Vector2D pos)
{
	return casillaSeleccionada.getPieza()->getColor() == casilla[pos.x][pos.y].getPieza()->getColor();
}