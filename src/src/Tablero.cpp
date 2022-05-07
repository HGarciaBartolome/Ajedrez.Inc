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

	/*enum piezas {
		REYN, REYB,
		REINAN, REINAB,
		ALFILN, ALFILB,
		TORREN, TORREB,
		PEONN, PEONB,
		VACIO = -1
	}pieza;*/

	casilla[0][0].setPieza(7);
	casilla[2][0].setPieza(5);
	casilla[3][0].setPieza(3);
	casilla[4][0].setPieza(1);
	casilla[5][0].setPieza(5);
	casilla[7][0].setPieza(7);
	
	for ( int i = 0; i < 7; i++) {
		int j = 1;
		casilla[i][j].setPieza(9);
	}

	casilla[0][7].setPieza(6);
	casilla[2][7].setPieza(4);
	casilla[3][7].setPieza(2);
	casilla[4][7].setPieza(0);
	casilla[5][7].setPieza(4);
	casilla[7][7].setPieza(6);

	for ( int i = 0; i < 7; i++) {
		int j = 6;
		casilla[i][j].setPieza(8);
	}

}


