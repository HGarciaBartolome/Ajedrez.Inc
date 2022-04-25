#include "Casilla.h"

Casilla::Casilla()
{
    x = y = 0;
}

void Casilla::setPosicion(int ix, int iy)
{
    x = ix;
    y = iy;
}