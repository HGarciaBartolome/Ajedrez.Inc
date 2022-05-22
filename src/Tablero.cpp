#include "Tablero.h"
#include <vector>
#define NCASILLAS 8
#define CANT_PIEZAS 32

Tablero::Tablero() : inicializado(false), inicializado2(false), inicializado3(false) {



	f = NO;
	//Se comienza con el turno de blancas
	t = turnoBLANCAS;
	std::cout << "Juegan BLANCAS" << std::endl;

	casillaSeleccionada.setPieza(new PiezaVacia());

	//Se dibujan las casillas, lo que formará el tablero de juego
	bool Negro = true;

	for (int i = 0; i < NCASILLAS; i++)
	{
		for (int j = 0; j < NCASILLAS; j++)
		{
			casilla[i][j].setPieza(new PiezaVacia(ColorPieza::Indefinido, Vector2D(i, j)));
			if (Negro)
				casilla[i][j].setColor(rojo(84), verde(56), azul(34));
			else
				casilla[i][j].setColor(rojo2(171), verde2(139), azul2(98));



			if (j != NCASILLAS - 1)
				Negro = !Negro;
		}
	}
}

char Tablero::rojo(char r)
{
	color2.r = r;
	return color2.r;
}
char Tablero::verde(char v)
{
	color2.g = v;
	return color2.g;
}

char Tablero::azul(char a)
{
	color2.b = a;
	return color2.b;
}
char Tablero::rojo2(char r)
{
	color3.r = r;
	return color3.r;
}
char Tablero::verde2(char v)
{
	color3.g = v;
	return color3.g;
}

char Tablero::azul2(char a)
{
	color3.b = a;
	return color3.b;
}

//DIBUJA PARA EL MODO CLASICO
void Tablero::dibuja() {

	for (int i = 0; i < NCASILLAS; i++) {
		for (int j = 0; j < NCASILLAS; j++) {
			casilla[i][j].dibuja();
		}
	}

	//MARCO DEL TABLERO
	glDisable(GL_LIGHTING);
	glColor3ub(137, 107, 73);
	glBegin(GL_QUADS);
	glVertex3f(-1.0f, -1.0f, -0.1f);
	glVertex3f(8.0f, -1.0f, -0.1f);
	glVertex3f(8.0f, 8.0f, -0.1f);
	glVertex3f(-1.0f, 8.0f, -0.1f);
	glEnd();


	glBegin(GL_QUADS);
	glVertex3f(-1.0f, -1.0f, -0.6f);
	glVertex3f(8.0f, -1.0f, -0.6f);
	glVertex3f(8.0, -1.0f, -0.1f);
	glVertex3f(-1.0f, -1.0f, -0.1f);
	glEnd();
	glEnable(GL_LIGHTING);


	//FONDO DE PANTALLA DEL TABLERO
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondoTablero.png").id);

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(-15, -5, -1.0);
	glTexCoord2d(1, 1); glVertex3f(15, -5, -1.0);
	glTexCoord2d(1, 0); glVertex3f(15, 10, -1.0);
	glTexCoord2d(0, 0); glVertex3f(-15, 10, -1.0);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	//Se llama al Dibuja de cada Pieza
	if (estaInicializado()) {
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				casilla[i][j].getPieza()->Dibuja();
	}
}

//DIBUJA PARA EL MODO 960
void Tablero::dibuja2() {

	for (int i = 0; i < NCASILLAS; i++) {
		for (int j = 0; j < NCASILLAS; j++) {
			casilla[i][j].dibuja();
		}
	}

	//MARCO DEL TABLERO
	glDisable(GL_LIGHTING);
	glColor3ub(137, 107, 73);
	glBegin(GL_QUADS);
	glVertex3f(-1.0f, -1.0f, -0.1f);
	glVertex3f(8.0f, -1.0f, -0.1f);
	glVertex3f(8.0f, 8.0f, -0.1f);
	glVertex3f(-1.0f, 8.0f, -0.1f);
	glEnd();


	glBegin(GL_QUADS);
	glVertex3f(-1.0f, -1.0f, -0.6f);
	glVertex3f(8.0f, -1.0f, -0.6f);
	glVertex3f(8.0, -1.0f, -0.1f);
	glVertex3f(-1.0f, -1.0f, -0.1f);
	glEnd();
	glEnable(GL_LIGHTING);



	//FONDO DE PANTALLA DEL TABLERO
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondoTablero960.png").id); //fondo distinto y fichas distintas

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(-5.5, -10, -4);
	glTexCoord2d(1, 1); glVertex3f(13.5, -10, -4);
	glTexCoord2d(1, 0); glVertex3f(13.5, 12, -4);
	glTexCoord2d(0, 0); glVertex3f(-5.5, 12, -4);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	//Se llama al Dibuja de cada pieza
	if (estaInicializado2()) {
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				casilla[i][j].getPieza()->Dibuja2();
	}
}

void Tablero::dibuja3() {

	for (int i = 0; i < NCASILLAS; i++) {
		for (int j = 0; j < NCASILLAS; j++) {
			casilla[i][j].dibuja();
		}
	}

	//MARCO DEL TABLERO
	glDisable(GL_LIGHTING);
	glColor3ub(137, 107, 73);
	glBegin(GL_QUADS);
	glVertex3f(-1.0f, -1.0f, -0.1f);
	glVertex3f(8.0f, -1.0f, -0.1f);
	glVertex3f(8.0f, 8.0f, -0.1f);
	glVertex3f(-1.0f, 8.0f, -0.1f);
	glEnd();


	glBegin(GL_QUADS);
	glVertex3f(-1.0f, -1.0f, -0.6f);
	glVertex3f(8.0f, -1.0f, -0.6f);
	glVertex3f(8.0, -1.0f, -0.1f);
	glVertex3f(-1.0f, -1.0f, -0.1f);
	glEnd();
	glEnable(GL_LIGHTING);

	//FONDO DE PANTALLA DEL TABLERO
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondoTableroETSIDI.png").id);	//fondo relacionado con la etsidi

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(-6.5, -17.5, -7);
	glTexCoord2d(1, 1); glVertex3f(15, -17.5, -7);
	glTexCoord2d(1, 0); glVertex3f(15, 15, -6);
	glTexCoord2d(0, 0); glVertex3f(-6.6, 15, -6);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	//Se llama al dibuja de cada ficha
	if (estaInicializado3()) {
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				casilla[i][j].getPieza()->Dibuja3();
	}
}


void Tablero::Inicializa()
{
	//VACIAS
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			casilla[i][j].setPieza(new PiezaVacia(ColorPieza::Indefinido, Vector2D(i, j)));
		}
	}
	//BLANCAS
	casilla[0][0].setPieza(new Torre(ColorPieza::Blanca, Vector2D(0, 0)));
	casilla[1][0].setPieza(new Caballo(ColorPieza::Blanca, Vector2D(1, 0)));
	casilla[2][0].setPieza(new Alfil(ColorPieza::Blanca, Vector2D(2, 0)));
	casilla[3][0].setPieza(new Reina(ColorPieza::Blanca, Vector2D(3, 0)));
	casilla[4][0].setPieza(new Rey(ColorPieza::Blanca, Vector2D(4, 0)));
	casilla[5][0].setPieza(new Alfil(ColorPieza::Blanca, Vector2D(5, 0)));
	casilla[6][0].setPieza(new Caballo(ColorPieza::Blanca, Vector2D(6, 0)));
	casilla[7][0].setPieza(new Torre(ColorPieza::Blanca, Vector2D(7, 0)));

	//PEONES BLANCOS
	for (int i = 0; i < 8; i++) {
		int j = 1;
		casilla[i][j].setPieza(new Peon(ColorPieza::Blanca, Vector2D(i, j)));
	}

	//NEGRAS
	casilla[0][7].setPieza(new Torre(ColorPieza::Negra, Vector2D(0, 7)));
	casilla[1][7].setPieza(new Caballo(ColorPieza::Negra, Vector2D(1, 7)));
	casilla[2][7].setPieza(new Alfil(ColorPieza::Negra, Vector2D(2, 7)));
	casilla[3][7].setPieza(new Reina(ColorPieza::Negra, Vector2D(3, 7)));
	casilla[4][7].setPieza(new Rey(ColorPieza::Negra, Vector2D(4, 7)));
	casilla[5][7].setPieza(new Alfil(ColorPieza::Negra, Vector2D(5, 7)));
	casilla[6][7].setPieza(new Caballo(ColorPieza::Negra, Vector2D(6, 7)));
	casilla[7][7].setPieza(new Torre(ColorPieza::Negra, Vector2D(7, 7)));

	//PEONES NEGROS
	for (int i = 0; i < 8; i++) {
		int j = 6;
		casilla[i][j].setPieza(new Peon(ColorPieza::Negra, Vector2D(i, j)));
	}

	inicializado = true;
}



void Tablero::Inicializa2()
{
		bool Negro = true; for (int i = 0; i < NCASILLAS; i++)
	{
		for (int j = 0; j < NCASILLAS; j++)
		{
			casilla[i][j].setPieza(new PiezaVacia(ColorPieza::Indefinido, Vector2D(i, j)));
			if (Negro)
				casilla[i][j].setColor(rojo(51), verde(102), azul(0));
			else
				casilla[i][j].setColor(rojo2(0), verde2(255), azul2(100)); if (j != NCASILLAS - 1)
				Negro = !Negro;
		}
	}



	srand(time(NULL));

	//VACIAS
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			casilla[i][j].setPieza(new PiezaVacia(ColorPieza::Indefinido, Vector2D(i, j)));
		}
	}

	//BLANCAS

	int b1, b2, b3, b4, b5, b6, b7, b8;

	while (1)
	{
		//se generan 8 numeros random
		b1 = rand() % 8;
		b2 = rand() % 8;
		b3 = rand() % 8;
		b4 = rand() % 8;
		b5 = rand() % 8;
		b6 = rand() % 8;
		b7 = rand() % 8;
		b8 = rand() % 8;

		if ((b1 != b2 && b1 != b3 && b1 != b4 && b1 != b5 && b1 != b6 && b1 != b7 && b1 != b8) &&
			(b2 != b3 && b2 != b4 && b2 != b5 && b2 != b6 && b2 != b7 && b2 != b8) &&
			(b3 != b4 && b3 != b5 && b3 != b6 && b3 != b7 && b3 != b8) &&
			(b4 != b5 && b4 != b6 && b4 != b7 && b4 != b8) &&
			(b5 != b6 && b5 != b7 && b5 != b8) &&
			(b6 != b7 && b6 != b8) &&
			(b7 != b8)) break;	//hasta que no sean distintos TODOS entre si no salen del bucle
	}
	casilla[b1][0].setPieza(new Alfil(ColorPieza::Blanca, Vector2D(b1, 0)));
	casilla[b2][0].setPieza(new Alfil(ColorPieza::Blanca, Vector2D(b2, 0)));
	casilla[b3][0].setPieza(new Reina(ColorPieza::Blanca, Vector2D(b3, 0)));
	casilla[b4][0].setPieza(new Caballo(ColorPieza::Blanca, Vector2D(b4, 0)));
	casilla[b5][0].setPieza(new Caballo(ColorPieza::Blanca, Vector2D(b5, 0)));
	casilla[b6][0].setPieza(new Rey(ColorPieza::Blanca, Vector2D(b6, 0)));
	casilla[b7][0].setPieza(new Torre(ColorPieza::Blanca, Vector2D(b7, 0)));
	casilla[b8][0].setPieza(new Torre(ColorPieza::Blanca, Vector2D(b8, 0)));


	for (int i = 0; i < 8; i++) {
		int j = 1;
		casilla[i][j].setPieza(new Peon(ColorPieza::Blanca, Vector2D(i, j)));
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//NEGRAS

	int n1, n2, n3, n4, n5, n6, n7, n8;

	while (1) {
		//se generan 8 numeros random
		n1 = rand() % 8;
		n2 = rand() % 8;
		n3 = rand() % 8;
		n4 = rand() % 8;
		n5 = rand() % 8;
		n6 = rand() % 8;
		n7 = rand() % 8;
		n8 = rand() % 8;

		if ((n1 != n2 && n1 != n3 && n1 != n4 && n1 != n5 && n1 != n6 && n1 != n7 && n1 != n8) &&
			(n2 != n3 && n2 != n4 && n2 != n5 && n2 != n6 && n2 != n7 && n2 != n8) &&
			(n3 != n4 && n3 != n5 && n3 != n6 && n3 != n7 && n3 != n8) &&
			(n4 != n5 && n4 != n6 && n4 != n7 && n4 != n8) &&
			(n5 != n6 && n5 != n7 && n5 != n8) &&
			(n6 != n7 && n6 != n8) &&
			(n7 != n8)) break;	//hasta que no sean distintos TODOS entre si no salen del bucle
	}
	casilla[n1][7].setPieza(new Alfil(ColorPieza::Negra, Vector2D(n1, 7)));
	casilla[n2][7].setPieza(new Alfil(ColorPieza::Negra, Vector2D(n2, 7)));
	casilla[n3][7].setPieza(new Reina(ColorPieza::Negra, Vector2D(n3, 7)));
	casilla[n4][7].setPieza(new Caballo(ColorPieza::Negra, Vector2D(n4, 7)));		//TODO: cambiar imagenes de las piezas
	casilla[n5][7].setPieza(new Caballo(ColorPieza::Negra, Vector2D(n5, 7)));
	casilla[n6][7].setPieza(new Rey(ColorPieza::Negra, Vector2D(n6, 7)));
	casilla[n7][7].setPieza(new Torre(ColorPieza::Negra, Vector2D(n7, 7)));
	casilla[n8][7].setPieza(new Torre(ColorPieza::Negra, Vector2D(n8, 7)));



	for (int i = 0; i < 8; i++) {
		int j = 6;
		casilla[i][j].setPieza(new Peon(ColorPieza::Negra, Vector2D(i, j)));
	}

	inicializado2 = true;
}

void Tablero::Inicializa3()
{

		bool Negro = true; for (int i = 0; i < NCASILLAS; i++)
	{
		for (int j = 0; j < NCASILLAS; j++)
		{
			casilla[i][j].setPieza(new PiezaVacia(ColorPieza::Indefinido, Vector2D(i, j)));
			if (Negro)
				casilla[i][j].setColor(rojo(194), verde(24), azul(7));
			else
				casilla[i][j].setColor(rojo2(51), verde2(0), azul2(153)); if (j != NCASILLAS - 1)
				Negro = !Negro;
		}
	}



	//VACIAS
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			casilla[i][j].setPieza(new PiezaVacia(ColorPieza::Indefinido, Vector2D(i, j)));
		}
	}

	//BLANCAS
	casilla[0][0].setPieza(new Pablo(ColorPieza::Blanca, Vector2D(0, 0)));
	casilla[1][0].setPieza(new Miguel(ColorPieza::Blanca, Vector2D(1, 0)));
	casilla[2][0].setPieza(new Cristobal(ColorPieza::Blanca, Vector2D(2, 0)));
	casilla[3][0].setPieza(new Reina(ColorPieza::Blanca, Vector2D(3, 0)));
	casilla[4][0].setPieza(new Rey(ColorPieza::Blanca, Vector2D(4, 0)));
	casilla[5][0].setPieza(new Cristobal(ColorPieza::Blanca, Vector2D(5, 0)));		//TODO: cambiar imagenes de las piezas
	casilla[6][0].setPieza(new Miguel(ColorPieza::Blanca, Vector2D(6, 0)));
	casilla[7][0].setPieza(new Pablo(ColorPieza::Blanca, Vector2D(7, 0)));

	//PEONES BLANCOS
	for (int i = 0; i < 8; i++) {
		int j = 1;
		casilla[i][j].setPieza(new Peon(ColorPieza::Blanca, Vector2D(i, j)));
	}

	//NEGRAS
	casilla[0][7].setPieza(new Pablo(ColorPieza::Negra, Vector2D(0, 7)));
	casilla[1][7].setPieza(new Miguel(ColorPieza::Negra, Vector2D(1, 7)));
	casilla[2][7].setPieza(new Cristobal(ColorPieza::Negra, Vector2D(2, 7)));
	casilla[3][7].setPieza(new Reina(ColorPieza::Negra, Vector2D(3, 7)));
	casilla[4][7].setPieza(new Rey(ColorPieza::Negra, Vector2D(4, 7)));
	casilla[5][7].setPieza(new Cristobal(ColorPieza::Negra, Vector2D(5, 7)));		//TODO: cambiar imagenes de las piezas
	casilla[6][7].setPieza(new Miguel(ColorPieza::Negra, Vector2D(6, 7)));
	casilla[7][7].setPieza(new Pablo(ColorPieza::Negra, Vector2D(7, 7)));

	//PEONES NEGROS
	for (int i = 0; i < 8; i++) {
		int j = 6;
		casilla[i][j].setPieza(new Peon(ColorPieza::Negra, Vector2D(i, j)));
	}

	inicializado3 = true;
}

bool Tablero::estaInicializado()
{
	return inicializado;
}

bool Tablero::estaInicializado2()
{
	return inicializado2;
}

bool Tablero::estaInicializado3()
{
	return inicializado3;
}

void Tablero::ilumina(Vector2D ilu)
{
	casilla[ilu.x][ilu.y].iluminaCasilla();
}

void Tablero::desilumina(Vector2D desilu)
{
	if (estaInicializado() == true)
	{
		bool Negro = true;

		//Se dibujan las casillas sin iluminar
		for (int i = 0; i < NCASILLAS; i++)
		{
			for (int j = 0; j < NCASILLAS; j++)
			{
				if (Negro)
					casilla[i][j].setColor(color2.r, color2.g, color2.b);
				else
					casilla[i][j].setColor(color3.r, color3.g, color3.b);

				if (j != NCASILLAS - 1)
					Negro = !Negro;
			}
		}
	}



	if (estaInicializado2() == true)
	{
		bool Negro = true;

		//Se dibujan las casillas sin iluminar
		for (int i = 0; i < NCASILLAS; i++)
		{
			for (int j = 0; j < NCASILLAS; j++)
			{
				if (Negro)
					casilla[i][j].setColor(color2.r, color2.g, color2.b);
				else
					casilla[i][j].setColor(color3.r, color3.g, color3.b);



				if (j != NCASILLAS - 1)
					Negro = !Negro;
			}
		}
	}



	if (estaInicializado3() == true)
	{
		bool Negro = true;

		//Se dibujan las casillas sin iluminar
		for (int i = 0; i < NCASILLAS; i++)
		{
			for (int j = 0; j < NCASILLAS; j++)
			{
				if (Negro)
					casilla[i][j].setColor(color2.r, color2.g, color2.b);
				else
					casilla[i][j].setColor(color3.r, color3.g, color3.b);

				if (j != NCASILLAS - 1)
					Negro = !Negro;
			}
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////MOVIMIENTOS/////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

bool Tablero::hayCasillaSeleccionada()
{
	return casillaSeleccionada.getPieza()->getPosicionX() != -1;	//ninguna casilla seleccionada
}

Casilla Tablero::getCasillaSeleccionada()
{
	return casillaSeleccionada;
}

bool Tablero::hayPiezaDelMismoColor(Vector2D pos)
{
	return casillaSeleccionada.getPieza()->getColor() == casilla[pos.x][pos.y].getPieza()->getColor();
}

void Tablero::seleccionarCasilla(Vector2D pos)
{
	casillaSeleccionada = getCasilla(pos);	//Coge la casilla seleccionada
}

Casilla Tablero::getCasilla(Vector2D pos)
{
	return casilla[pos.x][pos.y];	//devuelve la posicion de la casilla sleccionada
}

void Tablero::hacerMovimiento(Vector2D aux)
{
	//Variables de pieza para usarlas en el enroque
	auto torre = casilla[aux.x][aux.y].getPieza();
	auto rey = casillaSeleccionada.getPieza();

	// Variable de la pieza seleccionada
	auto piezaActual = casillaSeleccionada.getPieza();

	//Variable para determinar si es valido o no un movimiento
	bool mov = ((piezaActual->movValido(aux.x, aux.y, casilla[aux.x][aux.y].getPieza()->getColor()) && !hayPiezaEnMedio(piezaActual->getTrayectoria(casillaSeleccionada.getPieza()->getPosicion(), aux), aux)) && (piezaActual->getColor() == t)); //si es movimiento valido Y no hay pieza en medio Y es el turno correcto

	if (mov) {

		ETSIDI::play("sonidos/mueve.wav");

		//limpiar la casilla desde donde se mueve
		casilla[piezaActual->getPosicionX()][piezaActual->getPosicionY()].setPieza(new PiezaVacia(ColorPieza::Indefinido, Vector2D(piezaActual->getPosicion())));

		//Ver si hay pieza enemiga en la casilla destino para hacer captura
		captura(casilla[aux.x][aux.y].getPieza()->tipoPieza(), casilla[aux.x][aux.y].getPieza()->getColor());
		// Asignar la nueva posicion
		piezaActual->setPosicion(aux);
		casilla[aux.x][aux.y].setPieza(piezaActual);

		//tener en cuenta si corona un peon
		if (coronar(piezaActual))
			hacerCoronamiento(aux.x, aux.y);

		//Ya no es primer movimiento de la ficha movida (valido para tener en cuenta en enroques y avanzadilla de 2 en los peones)
		casilla[piezaActual->getPosicionX()][piezaActual->getPosicionY()].getPieza()->setPrimerMov(false);

		//Para dejar ninguna casilla seleccionada
		casillaSeleccionada.setPieza(new PiezaVacia());

		//manejo de turnos
		if (t == turnoBLANCAS) {
			t = turnoNEGRAS;
		}
		else {
			t = turnoBLANCAS;
		}

		switch (t) {
		case turnoNEGRAS:
			std::cout << "Juegan NEGRAS " << std::endl;
			break;

		case turnoBLANCAS:
			std::cout << "Juegan BLANCAS " << std::endl;
			break;
		}

	}
	//Tratamiento del enroque
	else if (posibleEnroque(aux)) {
		if (rey->getColor() == Blanca) {
			//tener en cuenta enroque largo o corto
			if (aux.x == 0 && aux.y == 0) {				//enroque largo
				hacerEnroque(aux, Vector2D(2, 0), Vector2D(3, 0));
			}

			else if (aux.x == 7 && aux.y == 0) {				//enroque corto
				hacerEnroque(aux, Vector2D(6, 0), Vector2D(5, 0));
			}
		}
		else if (rey->getColor() == Negra) {
			//tener en cuenta enroque largo o corto
			if (aux.x == 0 && aux.y == 7) {				//enroque largo
				hacerEnroque(aux, Vector2D(2, 7), Vector2D(3, 7));
			}
			else if (aux.x == 7 && aux.y == 7) {				//enroque corto
				hacerEnroque(aux, Vector2D(6, 7), Vector2D(5, 7));
			}
		}

		//manejo de los turnos
		if (t == turnoBLANCAS) {
			t = turnoNEGRAS;
		}
		else {
			t = turnoBLANCAS;
		}

		switch (t) {
		case 1:
			std::cout << "Juegan BLANCAS " << std::endl;
			break;

		case 2:
			std::cout << "Juegan NEGRAS " << std::endl;
			break;
		}
	}
	//Se imprime por pantalla Movimiento no valido en caso de no serlo
	else
		std::cout << "Movimiento no valido" << std::endl;
}

bool Tablero::posibleEnroque(Vector2D pos)
{
	auto piezaSeleccionada = casillaSeleccionada.getPieza();
	auto piezaDestino = casilla[pos.x][pos.y].getPieza();
	return ((piezaSeleccionada->getColor() == piezaDestino->getColor()) &&
		((piezaDestino->getColor() == Blanca && pos.y == 0 && (pos.x == 0 || pos.x == 7)) ||
			(piezaDestino->getColor() == Negra && pos.y == 7 && (pos.x == 0 || pos.x == 7))) &&
		piezaSeleccionada->getPrimerMov() && piezaDestino->getPrimerMov());
}

void Tablero::hacerEnroque(Vector2D pos, Vector2D v_rey, Vector2D v_torre)
{
	auto torre = casilla[pos.x][pos.y].getPieza();
	auto piezaActual = casillaSeleccionada.getPieza();
	//limpiar las posiciones del rey y la torre
	casilla[piezaActual->getPosicionX()][piezaActual->getPosicionY()].setPieza(new PiezaVacia(ColorPieza::Indefinido, Vector2D(piezaActual->getPosicion())));
	casilla[pos.x][pos.y].setPieza(new PiezaVacia(ColorPieza::Indefinido, pos));
	//actualizar la posicion del rey 
	piezaActual->setPosicion(v_rey);
	casilla[v_rey.x][v_rey.y].setPieza(piezaActual);
	//actualizar la posicion de la torre
	torre->setPosicion(v_torre);
	casilla[v_torre.x][v_torre.y].setPieza(torre);
	//primer movimiento a false y actualizo la posicion del vector
	casilla[piezaActual->getPosicionX()][piezaActual->getPosicionY()].getPieza()->setPrimerMov(false);
	casillaSeleccionada.setPieza(new PiezaVacia());
}

bool Tablero::hayPiezaEnMedio(Trayectoria trayectoria, Vector2D destino)
{
	bool hayPieza = false;
	for (int i = 0; i < trayectoria.size(); i++)
	{
		if (casilla[trayectoria[i].x][trayectoria[i].y].getPieza()->getColor() != ColorPieza::Indefinido && !(trayectoria[i] == destino)) {
			hayPieza = true;
			break;
		}
	}
	return hayPieza;
}

bool Tablero::coronar(Pieza* pieza) {


	if ((pieza->tipoPieza() == 'P' && pieza->getColor() == Blanca && pieza->getPosicionY() == 7) || (pieza->tipoPieza() == 'P' && pieza->getColor() == Negra && pieza->getPosicionY() == 0))
		return true;
	else
		return false;
}

void Tablero::hacerCoronamiento(int x, int y)
{
	if (casilla[x][y].getPieza()->getColor() == Blanca) {
		//cambiar peon por reina
		casilla[x][y].setPieza(new Reina(ColorPieza::Blanca, Vector2D(x, y)));
	}

	else if (casilla[x][y].getPieza()->getColor() == Negra) {
		//cambiar peon por reina
		casilla[x][y].setPieza(new Reina(ColorPieza::Negra, Vector2D(x, y)));
	}
}

void Tablero::captura(char tipo, ColorPieza color)
{

	if (tipo == 'V') {
		std::cout << "Casilla vacia " << std::endl;
	}

	else if (tipo == 'K' && color==1) {
		f = GanaJ1;
		
	}

	else if (tipo == 'K' && color == 2) {
		f = GanaJ2;
	
	}

	else {
		if (color == 1)
			std::cout << "Captura	" << tipo << " Negro/a " << std::endl;
		else if (color == 0)
			std::cout << "Captura	" << tipo << " Blanco/a " << std::endl;

	}
}
