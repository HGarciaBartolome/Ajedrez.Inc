#include "Mundo.h"

void Mundo::dibuja() {

	gluLookAt(x_ojo, y_ojo, z_ojo,
		0.0, y_ojo, 0.0, 
		0.0, 1.0, 0.0);
	
	tablero.dibuja();
}

void Mundo::inicializa() {
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;
}