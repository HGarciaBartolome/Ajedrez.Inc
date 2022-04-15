#include "Tablero.h"

Tablero::Tablero() {
    numCasillas = 8;

    //INICIALIZAMOS POSICION Y COLOR DE CASILLAS
    for (int i = 0; i < numCasillas; i++)
    {
        if ((i % 2) == 0) //casillas Y par
        {
            for (int j = 0; j < numCasillas; j++)
            {
                if (((j) % 2) == 0)//rellenan las casillas X par
                {
                    casilla[j][i].setPosicion(j, i);
                    casilla[j][i].SetColor(184, 115, 51);

                }
                else
                {
                    casilla[j][i].setPosicion(j, i);
                    casilla[j][i].SetColor(230, 181, 126);
                }
            }

        }
        else //casillas Y impar
        {
            for (int j = 0; j < numCasillas; j++)
            {
                if (((j) % 2) != 0)//rellenan las casillas X impar
                {
                    casilla[j][i].setPosicion(j, i);
                    casilla[j][i].SetColor(184, 115, 51);
                }
                else
                {
                    casilla[j][i].setPosicion(j, i);
                    casilla[j][i].SetColor(230, 181, 126);
                }
            }
        }
    }


}



void Tablero::Dibuja() {


    //Dibujamos FIJAS LAS CASILLAS NO TOCAR, ULTIMO SIEMPRE

    for (int i = 0; i < numCasillas; i++) {
        for (int j = 0; j < numCasillas; j++) {
            casilla[j][i].Dibuja();
        }
    }
    /*
    // base y lados
    glDisable(GL_LIGHTING);
    glColor3ub(139, 69, 19);
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
    */
}

void Tablero::SeleccionaCasilla(Vector2D v, unsigned char x) {
    casilla[v.j][v.i].Ilumina(x);
}

void Tablero::DesSeleccionaCasilla(Vector2D v) {
    for (int i = 0; i < numCasillas; i++)
    {
        if ((i % 2) == 0) //casillas Y par
        {
            for (int j = 0; j < numCasillas; j++)
            {
                if (((j) % 2) == 0)//rellenan las casillas X par
                {
                    casilla[j][i].SetColor(184, 115, 51);
                }
                else
                {
                    casilla[j][i].SetColor(230, 181, 126);
                }
            }

        }
        else //casillas Y impar
        {
            for (int j = 0; j < numCasillas; j++)
            {
                if (((j) % 2) != 0)//rellenan las casillas X impar
                {
                    ;
                    casilla[j][i].SetColor(184, 115, 51);
                }
                else
                    casilla[j][i].SetColor(230, 181, 126);
            }
        }
    }
}

