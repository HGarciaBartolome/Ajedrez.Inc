#pragma once
#include "Casilla.h"
#define SIZE_TABLERO 8

class Tablero
{
private:
    Casilla casilla[SIZE_TABLERO][SIZE_TABLERO];

public:
    Tablero();
    virtual ~Tablero() {};
};