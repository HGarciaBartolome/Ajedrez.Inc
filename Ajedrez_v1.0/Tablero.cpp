#include "Tablero.h"

Tablero::Tablero() {
    //Bucles para dibujar tablero
    for (int i = 0; i < SIZE_TABLERO; i++)
    {
        for (int j = 0; j < SIZE_TABLERO; j++)
        {
            casilla[j][i].setPosicion(j, i);
        }
    }
}
