#include "Casilla.h"

Casilla::Casilla() 
{
    rojo = verde = azul = 1;
    lado = 1;
    x = y = 0;
}

void Casilla::setPosicion(float ix, float iy) 
{
    x = ix;
    y = iy;
}

void Casilla::SetColor(unsigned char r, unsigned char v, unsigned char a)
{
    rojo = r;
    verde = v;
    azul = a;
}

void Casilla::Dibuja()
{
    float rad = lado / 2;

    /*  glDisable(GL_LIGHTING);
    glColor3ub(rojo, verde, azul);
    glBegin(GL_QUADS);
    glVertex2f(x + rad, y + rad);
    glVertex2f(x + rad, y - rad);
    glVertex2f(x - rad, y - rad);
    glVertex2f(x - rad, y + rad);
    glEnd();
    glEnable(GL_LIGHTING);*/
}

void Casilla::Ilumina(unsigned char m) 
{
    rojo = m;
    verde = azul = 0;
}