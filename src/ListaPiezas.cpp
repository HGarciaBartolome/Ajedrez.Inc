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

bool ListaPiezas::agregarTorre(Torre* t)
{

	if (numTorre < MAXPIEZAS)
		listaTorre[numTorre++] = t; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
	return true;

}

bool ListaPiezas::agregarPeon(Peon* p)
{

	if (numPeon < MAXPIEZAS)
		listaPeon[numPeon++] = p; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
	return true;

}

bool ListaPiezas::agregarAlfil(Alfil* a)
{

	if (numAlfil < MAXPIEZAS)
		listaAlfil[numAlfil++] = a; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
	return true;

}

bool ListaPiezas::agregarReina(Reina* reina)
{

	if (numReina < MAXPIEZAS)
		listaReina[numReina++] = reina; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
	return true;

}

bool ListaPiezas::agregarRey(Rey* rey)
{

	if (numRey < MAXPIEZAS)
		listaRey[numRey++] = rey; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
	return true;

}
