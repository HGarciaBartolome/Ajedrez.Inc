#pragma once
#include "Alfil.h"
#include "Reina.h"
#include "Torre.h"
#include "Rey.h"
#include "Peon.h"
#include "Piezas.h"
#include "ETSIDI.h"
#include "freeglut.h"
#define MAXPIEZAS 64
class ListaPiezas {
public:
	ListaPiezas();
	void agregarTorre(Torre* t);
	void agregarPeon(Peon* t);
	void agregarAlfil(Alfil* t);
	void agregarReina(Reina* t);
	void agregarRey(Rey* t);
private:
	
	int numPeon, numAlfil,numReina, numTorre,numRey;//Numeros para contar cantidad de piezas
	Peon* listaPeon[MAXPIEZAS];
	Torre* listaTorre[MAXPIEZAS];
	Alfil* listaAlfil[MAXPIEZAS];
	Reina* listaReina[MAXPIEZAS];
	Rey* listaRey[MAXPIEZAS];
};