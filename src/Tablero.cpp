#include "Tablero.h"
#define NCASILLAS 8
#include "Mundo.h"
Tablero::Tablero() {
	
	Casilla c;
	c.setPos(-1, -1);	//ninguna casilla seleccionada

	casillaSeleccionada = c;
	
	bool Negro = true;

	for (int i = 0;i < NCASILLAS;i++)
	{
		for (int j = 0;j < NCASILLAS;j++)
		{
			casilla[i][j].setPos(i, j);

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
	
}

void Tablero::Inicializa()
{

	//BLANCAS
	casilla[0][0].setPieza(Ficha::TORREB);
	casilla[2][0].setPieza(Ficha::ALFILB);
	casilla[3][0].setPieza(Ficha::REINAB);
	casilla[4][0].setPieza(Ficha::REYB);
	casilla[5][0].setPieza(Ficha::ALFILB);
	casilla[7][0].setPieza(Ficha::TORREB);
	
	for ( int i = 0; i < 7; i++) {
		int j = 1;
		casilla[i][j].setPieza(Ficha::PEONB);
	}

	//NEGRAS
	casilla[0][7].setPieza(Ficha::TORREN);
	casilla[2][7].setPieza(Ficha::ALFILN);
	casilla[3][7].setPieza(Ficha::REINAN);
	casilla[4][7].setPieza(Ficha::REYN);
	casilla[5][7].setPieza(Ficha::ALFILN);
	casilla[7][7].setPieza(Ficha::TORREN);

	for ( int i = 0; i < 7; i++) {
		int j = 6;
		casilla[i][j].setPieza(Ficha::PEONN);
	}

	//VACIAS
	for (int i = 0; i < 7; i++) {
		for (int j = 2; j < 6; j++) {
			Pieza pVacia;
			pVacia.setPosicion(i, j);
			casilla[i][j].setPieza(Ficha::VACIO);
		}
	}
	resetcasillaSelecionada();
}

Casilla Tablero::getcasillaSelecionada()
{
	return casillaSeleccionada;
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
			casilla[i][j].setPos(i, j);

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

	// Iluminar casilla
	// Desiluminar la que estuviera seleccionada antes
}

bool Tablero::hacerMovimiento(Vector2D aux)
{	
	// TODO: comprobar que se pueda hacer el movimiento
	if (&casillaSeleccionada== NULL){
		casillaSeleccionada = casilla[aux.x][aux.y];
		return false;
	}
	else {
		// Actualizar a vacio la vieja
		Ficha piezaActual = casillaSeleccionada.getPieza();
		casilla[casillaSeleccionada.getPosX()][casillaSeleccionada.getPosY()].setPieza(Ficha::VACIO);
		// Asignar la nueva posicion
		casilla[aux.x][aux.y].setPieza(piezaActual);
		return true;
		//Casilla* limpia = &casillaSeleccionada;
		//limpia = NULL;
	}
	// TODO: Dibujar
}
void Tablero::resetcasillaSelecionada()
{
	Casilla* limpia = &casillaSeleccionada;
	limpia = NULL;
}
Casilla Tablero::getCasilla(Vector2D pos)
{
	return casilla[pos.x][pos.y];
}