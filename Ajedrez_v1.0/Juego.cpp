#define NUMFICHAS 16;
#include "Juego.h"

void Juego::Inicializa(int t)
{
	/*se inializa la variable con un valor extraido de fuera, este corresponde con el tipo de juego: JugadorVsJugador
	o JugadorVsMaquina*/
	tipo = t;

	//Se inicializa la vista de juego. Permanecerá fija a lo largo de la partida
	x_ojo = 4;
	y_ojo = 4;
	z_ojo = 15;

	//se inicializa un contador de fichas de cada jugador, con el número de de fichas iniciales
	contadorJ1 = contadorJ2 = NUMFICHAS;

	//Comienza la partida con el turno de jugador uno
	turno = TurnoUno;

	//Se inicializa el primer paso
	paso = PrimPaso;

	//Se inicializan variables correspondientes al movimiento de las fichas
	movimiento = NADA;
	//ContComidaObligatoriaJ1 = ContComidaObligatoriaJ2 = 0;
	ComidaVariasJ1 = ComidaVariasJ2 = false;

	/*
	//inicilaizo las reinas
	for (int i = 0; i < tablero.GetCasillas(); i++) {
		for (int j = 0; j < tablero.GetCasillas(); j++) {
			reinaJ1[j][i].setPosicion(j, i);
			reinaJ2[j][i].setPosicion(j, i);
		}
	}
	for (int i = 0; i < tablero.GetCasillas(); i++)
	{
		for (int j = 0; j < tablero.GetCasillas(); j++)
		{
			reinaJ1[j][i].SetDesactiva();
			reinaJ1[j][i].SetColor(89, 46, 11);
			reinaJ2[j][i].SetDesactiva();
			reinaJ2[j][i].SetColor(185, 147, 90);
		}
	}
	*/

	/*
	//primera posicion de las piezas
	for (int i = 0; i < tablero.GetCasillas(); i++) {
		for (int j = 0; j < tablero.GetCasillas(); j++) {
			fichaJ1[j][i].setPosicion(j, i);
			fichaJ1[j][i].SetColor(89, 46, 11);
			fichaJ2[j][i].setPosicion(j, i);
			fichaJ2[j][i].SetColor(185, 147, 90);
		}
	}

	for (int i = 0; i < tablero.GetCasillas(); i++)
	{
		for (int j = 0; j < tablero.GetCasillas(); j++)
		{
			if (i <= 2 && ((i + j) % 2 == 0))
			{
				fichaJ1[j][i].SetActiva();
			}
			else if (i >= 5 && ((i + j) % 2 == 0))
			{
				fichaJ2[j][i].SetActiva();
			}
		}
	}
	*/


}



//METODOS DE CONTROL

void Juego::Jugadas() { //le meto un int del tipo de juego, las enumeraciones son enteros 

}

//Cuando empieza el turno del siguiente jugador se rastrea si tiene posibilidad de CAPTURA OBLIGATORIA, para ello llama a la funcion correspondiente según el jugador
void Juego::MuestraPosibilidades() {
	
}

//Ficha se convierte en reina al llegar el final del tablero
void Juego::CrearReina() {
	
}

//METODOS DE MOVIMIENTO
void Juego::MovimientoJ1()
{

	
}

void Juego::MovimientoR1(Vector2D m) {

}

void Juego::MovimientoJ2()
{

	
}

void Juego::MovimientoR2(Vector2D m) {// movimiento reina 2
	
}



void Juego::MovimientoPC()
{

}
/*
//FUNCIONES AUXILIARES DE MOVIMIENTO
bool Juego::ComidaDobleReina()
{

	
}


bool Juego::ComidaDobleReinaPC()
{

}
*/

/*
//FUNCIONES COMPROBACION
//funciones que vuelven a poner las posibles comidas que se habían activado en la jugada anterior
void Juego::DesactivaPosibilidadesJ1() {
}

void Juego::DesactivaPosibilidadesJ2() {
}

//Devuelve true si la la casilla correspondiente al vector introducido esta ocupada por una de las fichas del jugador indicado
bool Juego::Ocupada(Ficha fichas[8][8], Vector2D v) {
};

//Devuelve true si la la casilla correspondiente al vector introducido esta ocupada por cualquier ficha
bool Juego::Ocupada(Vector2D v) {
}

//Devuelve true si la la casilla correspondiente al vector introducido esta ocupada por una de las reinas del jugador indicado
bool Juego::Ocupada(Reina reina[8][8], Vector2D v) {
};


//devuelve true si la casilla indicada existe y false si se ha salido del tablero
bool Juego::Existe(Vector2D v) {
}


bool Juego::FichaCorrecta(Ficha f[8][8], Vector2D v) {
}

bool Juego::FichaNextCorrecta(Ficha f[8][8], Vector2D v) {
}

int Juego::contador(Ficha jugador[8][8], Reina jugad_[8][8])
{
	int numFichas = 0;

	for (int i = 0; i < tablero.GetCasillas(); i++)
	{
		for (int j = 0; j < tablero.GetCasillas(); j++)
		{
			if (jugador[j][i].GetOcupada() == true)
				numFichas = numFichas + 1;
			if (jugad_[j][i].GetOcupada() == true)
				numFichas = numFichas + 1;
		}
	}
	std::cout << "-----------------EL CONTADOR ES: " << numFichas << std::endl;
	return numFichas;
}
*/

void Juego::Dibuja()
{
	tablero.Dibuja();
}

void Juego::RotarOjo()
{

	float d = sqrt((pow(y_ojo, 2)) + pow(x_ojo, 2));
	double theta = atan2(y_ojo, x_ojo);
	theta += 0.1f;
	//con el angulo aumentado un diferencial cambio los valores de los puntos de vista x y z 
	x_ojo = d * cos(theta);
	y_ojo = d * sin(theta);
}

void Juego::Para()
{
	x_ojo = 4;
	y_ojo = 4;

}


void Juego::Tecla(unsigned char key)
{
	if (key == 'a') printf("hola %d espacio %d fin", vector.j, vector.i);

}


void Juego::Raton(int button, int state, int x, int y)
{
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
	{
		if (x >= 152 && x < 207) {
			;
			vector.j = 0;
			if (y >= 493 && y < 547) vector.i = 0;
			if (y >= 438 && y < 493) vector.i = 1;
			if (y >= 383 && y < 438) vector.i = 2;
			if (y >= 328 && y < 383) vector.i = 3;
			if (y >= 273 && y < 328) vector.i = 4;
			if (y >= 218 && y < 273) vector.i = 5;
			if (y >= 163 && y < 218) vector.i = 6;
			if (y >= 108 && y < 163) vector.i = 7;
		};
		if (x >= 207 && x < 263) {

			vector.j = 1;
			if (y >= 493 && y < 547) vector.i = 0;
			if (y >= 438 && y < 493) vector.i = 1;
			if (y >= 383 && y < 438) vector.i = 2;
			if (y >= 328 && y < 383) vector.i = 3;
			if (y >= 273 && y < 328) vector.i = 4;
			if (y >= 218 && y < 273) vector.i = 5;
			if (y >= 163 && y < 218) vector.i = 6;
			if (y >= 108 && y < 163) vector.i = 7;
		}
		if (x >= 263 && x < 318) {

			vector.j = 2;
			if (y >= 493 && y < 547) vector.i = 0;
			if (y >= 438 && y < 493) vector.i = 1;
			if (y >= 383 && y < 438) vector.i = 2;
			if (y >= 328 && y < 383) vector.i = 3;
			if (y >= 273 && y < 328) vector.i = 4;
			if (y >= 218 && y < 273) vector.i = 5;
			if (y >= 163 && y < 218) vector.i = 6;
			if (y >= 108 && y < 163) vector.i = 7;
		}
		if (x >= 318 && x < 373) {

			vector.j = 3;
			if (y >= 493 && y < 547) vector.i = 0;
			if (y >= 438 && y < 493) vector.i = 1;
			if (y >= 383 && y < 438) vector.i = 2;
			if (y >= 328 && y < 383)vector.i = 3;
			if (y >= 273 && y < 328) vector.i = 4;
			if (y >= 218 && y < 273) vector.i = 5;
			if (y >= 163 && y < 218) vector.i = 6;
			if (y >= 108 && y < 163)vector.i = 7;
		}
		if (x >= 373 && x < 428) {
			vector.j = 4;
			if (y >= 493 && y < 547) vector.i = 0;
			if (y >= 438 && y < 493) vector.i = 1;
			if (y >= 383 && y < 438) vector.i = 2;
			if (y >= 328 && y < 383) vector.i = 3;
			if (y >= 273 && y < 328) vector.i = 4;
			if (y >= 218 && y < 273) vector.i = 5;
			if (y >= 163 && y < 218) vector.i = 6;
			if (y >= 108 && y < 163) vector.i = 7;
		}
		if (x >= 428 && x < 483) {

			vector.j = 5;
			if (y >= 493 && y < 547) vector.i = 0;
			if (y >= 438 && y < 493) vector.i = 1;
			if (y >= 383 && y < 438) vector.i = 2;
			if (y >= 328 && y < 383) vector.i = 3;
			if (y >= 273 && y < 328) vector.i = 4;
			if (y >= 218 && y < 273) vector.i = 5;
			if (y >= 163 && y < 218) vector.i = 6;
			if (y >= 108 && y < 163) vector.i = 7;
		}
		if (x >= 483 && x < 538) {

			vector.j = 6;
			if (y >= 493 && y < 547) vector.i = 0;
			if (y >= 438 && y < 493) vector.i = 1;
			if (y >= 383 && y < 438) vector.i = 2;
			if (y >= 328 && y < 383) vector.i = 3;
			if (y >= 273 && y < 328) vector.i = 4;
			if (y >= 218 && y < 273) vector.i = 5;
			if (y >= 163 && y < 218) vector.i = 6;
			if (y >= 108 && y < 163) vector.i = 7;
		}
		if (x >= 538 && x < 593) {
			vector.j = 7;
			if (y >= 493 && y < 547) vector.i = 0;
			if (y >= 438 && y < 493) vector.i = 1;
			if (y >= 383 && y < 438) vector.i = 2;
			if (y >= 328 && y < 383) vector.i = 3;
			if (y >= 273 && y < 328) vector.i = 4;
			if (y >= 218 && y < 273) vector.i = 5;
			if (y >= 163 && y < 218) vector.i = 6;
			if (y >= 108 && y < 163) vector.i = 7;
		}
		tablero.DesSeleccionaCasilla(vector);
		tablero.SeleccionaCasilla(vector, 0);
		Jugadas();

		MuestraPosibilidades();
	}

}




