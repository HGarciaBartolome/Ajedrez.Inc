#include "Tablero.h"
#define NCASILLAS 8
#include "Mundo.h"
#include <iostream>
Tablero::Tablero() {
	
	Casilla c;
	c.setPos(-1, -1);	//ninguna casilla seleccionada
	runMov= runSelec =Qmov =false;
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
	
	for ( int i = 0; i < 8; i++) {
		int j = 1;
		casilla[i][j].setPieza(Ficha::PEONB);
	}

	//NEGRAS
	casilla[0][7].setPieza(Ficha::TORREN);
	casilla[2][7].setPieza(Ficha::ALFILN);
	casilla[4][7].setPieza(Ficha::REINAN);
	casilla[3][7].setPieza(Ficha::REYN);
	casilla[5][7].setPieza(Ficha::ALFILN);
	casilla[7][7].setPieza(Ficha::TORREN);

	for ( int i = 0; i < 8; i++) {
		int j = 6;
		casilla[i][j].setPieza(Ficha::PEONN);
	}

	//VACIAS
	for (int i = 0; i < 7; i++) {
		for (int j = 2; j < 6; j++) {
			//Pieza pVacia;
			//pVacia.setPosicion(i, j);
			casilla[i][j].setPieza(Ficha::VACIO);
		}
	}
	//resetcasillaSelecionada();
}

/////////////////////////////////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Casilla Tablero::getcasillaSelecionada()
{
	return casillaOld;
}

void Tablero::seleccionarCasilla(Vector2D pos)
{
	if (runSelec == false) {
		runSelec = true;
	}
	else {
		casillaOld = casillaSeleccionada;
		casillaSeleccionada = getCasilla(pos);
		runSelec = false;
	}
}

bool Tablero::hacerMovimiento(Vector2D aux)
{	
	if(runMov==false){
		runMov = true;
	}
	else {

		if (casillaOld.getPieza() != Ficha::VACIO) {
			Ficha piezaActual = casillaOld.getPieza();
			casilla[casillaOld.getPosX()][casillaOld.getPosY()].setPieza(Ficha::VACIO);	//si en la casilla que he seleccionado hay una pieza, dejo vacia esa casilla


			casilla[casillaSeleccionada.getPosX()][casillaSeleccionada.getPosY()].setPieza(piezaActual);	//poner la pieza en la nueva casilla
			Qmov = true;
			runMov = false;
			return true;
		}
	}
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

void Tablero::Matriz(){
	for (int j = 0; j < 8; j++) {
		for (int i = 0; i < 8; i++) {
			std::cout << int(casilla[i][j].getPieza()) << "  ";
		}
		std::cout  << "\n";
	}
}