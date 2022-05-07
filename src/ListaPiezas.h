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
	bool agregarTorre(Torre* t);
	bool agregarPeon(Peon* p);
	bool agregarAlfil(Alfil* a);
	bool agregarReina(Reina* reina);
	bool agregarRey(Rey* rey);
	void incializa();
	void dibuja();
private:
	
	int numPeon, numAlfil,numReina, numTorre,numRey;//Numeros para contar cantidad de piezas
	Peon* listaPeon[MAXPIEZAS];
	Torre* listaTorre[MAXPIEZAS];
	Alfil* listaAlfil[MAXPIEZAS];
	Reina* listaReina[MAXPIEZAS];
	Rey* listaRey[MAXPIEZAS];
};