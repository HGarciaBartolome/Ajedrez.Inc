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

	if (numTorre < (MAXPIEZAS - numAlfil -numReina-numRey -numPeon -numTorre))
		listaTorre[numTorre++] = t; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
	return true;

}

bool ListaPiezas::agregarPeon(Peon* p)
{

	if (numPeon < (MAXPIEZAS - numAlfil -numReina-numRey -numPeon -numTorre))
		listaPeon[numPeon++] = p; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
	return true;

}

bool ListaPiezas::agregarAlfil(Alfil* a)
{

	if (numAlfil < (MAXPIEZAS - numAlfil -numReina-numRey -numPeon -numTorre))
		listaAlfil[numAlfil++] = a; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
	return true;

}

bool ListaPiezas::agregarReina(Reina* reina)
{

	if (numReina < (MAXPIEZAS - numAlfil -numReina-numRey -numPeon -numTorre))
		listaReina[numReina++] = reina; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
	return true;

}

bool ListaPiezas::agregarRey(Rey* rey)
{

	if (numRey < (MAXPIEZAS - numAlfil -numReina-numRey -numPeon -numTorre))
		listaRey[numRey++] = rey; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
	return true;

}

void ListaPiezas::incializa() {
	
}

void ListaPiezas::dibuja() {
	for (int i = 0; i < numAlfil; i++) {
		listaAlfil[i]->Dibuja();
	}
	for (int i = 0; i < numTorre; i++) {
		listaTorre[i]->Dibuja();
	}
	for (int i = 0; i < numPeon; i++) {
		listaPeon[i]->Dibuja();
	}
	for (int i = 0; i < numRey; i++) {
		listaRey[i]->Dibuja();
	}
	for (int i = 0; i < numReina; i++) {
		listaReina[i]->Dibuja();
	}
}