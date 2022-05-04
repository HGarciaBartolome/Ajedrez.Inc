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

