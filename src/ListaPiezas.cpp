#include "ListaPiezas.h"

ListaPiezas::ListaPiezas()
{
	numPeon= 0;
	numAlfil= 0;
	numTorre= 0;
	numReina= 0;
	numRey= 0;
	for (int i = 0; i < MAXPIEZAS; i++) {
		listaAlfil[i] = 0;
		listaPeon[i] = 0;
		listaTorre[i] = 0;
		listaRey[i] = 0;
		listaReina[i] = 0;
	}
}

void ListaPiezas::agregarTorre(Torre* t)
{
}

void ListaPiezas::agregarPeon(Peon* t)
{
}

void ListaPiezas::agregarAlfil(Alfil* t)
{
}

void ListaPiezas::agregarReina(Reina* t)
{
}

void ListaPiezas::agregarRey(Rey* t)
{
}
