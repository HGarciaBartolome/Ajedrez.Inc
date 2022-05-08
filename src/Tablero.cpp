#include "Tablero.h"
#define NCASILLAS 8

Tablero::Tablero() {

	bool Negro = true;


	for (int i = 0;i < NCASILLAS;i++)
	{
		for (int j = 0;j < NCASILLAS;j++)
		{
			casilla[i][j].setPos(i, j);

			if (Negro)
				casilla[i][j].setColor(128, 64, 0);
			else
				casilla[i][j].setColor(213, 209, 191);

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

}

void Tablero::Inicializa()
{

	//BLANCAS
	casilla[0][0].setPieza(TORREB);
	casilla[2][0].setPieza(ALFILB);
	casilla[3][0].setPieza(REINAB);
	casilla[4][0].setPieza(REYB);
	casilla[5][0].setPieza(ALFILB);
	casilla[7][0].setPieza(TORREB);
	
	for ( int i = 0; i < 7; i++) {
		int j = 1;
		casilla[i][j].setPieza(PEONB);
	}

	//NEGRAS
	casilla[0][7].setPieza(TORREN);
	casilla[2][7].setPieza(ALFILN);
	casilla[3][7].setPieza(REINAN);
	casilla[4][7].setPieza(REYN);
	casilla[5][7].setPieza(ALFILN);
	casilla[7][7].setPieza(TORREN);

	for ( int i = 0; i < 7; i++) {
		int j = 6;
		casilla[i][j].setPieza(PEONN);
	}

	//VACIAS
	for (int i = 0; i < 7; i++) {
		for (int j = 2; j < 6; j++) {
			casilla[i][j].setPieza(VACIO);
		}
	}
}


