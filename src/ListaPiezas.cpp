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

void ListaPiezas::movimiento(Vector2D aux,Casilla casilla)
{
	if (casilla.getPieza() == Ficha::ALFILB) {
		for (int i = 0; i < numAlfil; i++) {
			if (listaAlfil[i]->getPosicionX() == casilla.getPosX()) {
				if (listaAlfil[i]->getPosicionY() == casilla.getPosY()) {
					listaAlfil[i]->setPosicion(aux.x,aux.y);
					return;
				}
			}
		}
	}
	if (casilla.getPieza() == Ficha::ALFILN) {
		for (int i = 0; i < numAlfil; i++) {
			if (listaAlfil[i]->getPosicionX() == casilla.getPosX()) {
				if (listaAlfil[i]->getPosicionY() == casilla.getPosY()) {
					listaAlfil[i]->setPosicion(aux.x, aux.y);
					return;
				}
			}
		}
	}
	if (casilla.getPieza() == Ficha::TORREN) {
		for (int i = 0; i < numTorre; i++) {
			if (listaTorre[i]->getPosicionX() == casilla.getPosX()) {
				if (listaTorre[i]->getPosicionY() == casilla.getPosY()) {
					listaTorre[i]->setPosicion(aux.x, aux.y);
					return;
				}
			}
		}
	}
	if (casilla.getPieza() == Ficha::TORREB) {
		for (int i = 0; i < numTorre; i++) {
			if (listaTorre[i]->getPosicionX() == casilla.getPosX()) {
				if (listaTorre[i]->getPosicionY() == casilla.getPosY()) {
					listaTorre[i]->setPosicion(aux.x, aux.y);
					return;
				}
			}
		}
	}
	if (casilla.getPieza() == Ficha::REYN) {
		for (int i = 0; i < numRey; i++) {
			if (listaRey[i]->getPosicionX() == casilla.getPosX()) {
				if (listaRey[i]->getPosicionY() == casilla.getPosY()) {
					listaRey[i]->setPosicion(aux.x, aux.y);
					return;
				}
			}
		}
	}
	if (casilla.getPieza() == Ficha::REYB) {
		for (int i = 0; i < numRey; i++) {
			if (listaRey[i]->getPosicionX() == casilla.getPosX()) {
				if (listaRey[i]->getPosicionY() == casilla.getPosY()) {
					listaRey[i]->setPosicion(aux.x, aux.y);
					return;
				}
			}
		}
	}
	if (casilla.getPieza() == Ficha::REINAB) {
		for (int i = 0; i < numReina; i++) {
			if (listaReina[i]->getPosicionX() == casilla.getPosX()) {
				if (listaReina[i]->getPosicionY() == casilla.getPosY()) {
					listaReina[i]->setPosicion(aux.x, aux.y);
					return;
				}
			}
		}
	}
	if (casilla.getPieza() == Ficha::REINAN) {
		for (int i = 0; i < numReina; i++) {
			if (listaReina[i]->getPosicionX() == casilla.getPosX()) {
				if (listaReina[i]->getPosicionY() == casilla.getPosY()) {
					listaReina[i]->setPosicion(aux.x, aux.y);
					return;
				}
			}
		}
	}
	if (casilla.getPieza() == Ficha::PEONN) {
		for (int i = 0; i < numPeon; i++) {
			if (listaPeon[i]->getPosicionX() == casilla.getPosX()) {
				if (listaPeon[i]->getPosicionY() == casilla.getPosY()) {
					listaPeon[i]->setPosicion(aux.x, aux.y);
					return;
				}
			}
		}
	}
	if (casilla.getPieza() == Ficha::PEONB) {
		for (int i = 0; i < numPeon; i++) {
			if (listaPeon[i]->getPosicionX() == casilla.getPosX()) {
				if (listaPeon[i]->getPosicionY() == casilla.getPosY()) {
					listaPeon[i]->setPosicion(aux.x, aux.y);
					return;
				}
			}
		}
	}
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