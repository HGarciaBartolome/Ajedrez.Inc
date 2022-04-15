#include "Mundo.h"

Mundo::Mundo()
{	
	//La variable estado se inicializa a INICIO de juego
	estado = INICIO;
	contador = 0;
	victoria = NO;
}

void Mundo::tecla(unsigned char key)
{
	//if (key == 'x' || key == 'X') ETSIDI::stopMusica();
	if (estado == INICIO)
	{
		if (key == '1')
		{
			estado = JUGVSMAQ;
			Juego.Inicializa(estado);
		}
		if (key == '2')
		{
			estado = JUGVSJUG;
			Juego.Inicializa(estado);
		}
		if (key == 'r' || key == 'R')
		{
			estado = REGLAS;
		}
		if (key == 'e' || key == 'E') {

			exit(0);

		}
	}
	if (estado == REGLAS)
	{
		if (key == '1')
		{
			estado = JUGVSMAQ;
			Juego.Inicializa(estado);
		}
		if (key == '2')
		{
			estado = JUGVSJUG;
			Juego.Inicializa(estado);
		}
		if (key == 'e' || key == 'E')
		{
			exit(0);
		}
	}
	if (victoria == FINJ1 || victoria == FINJ2)
	{
		if (key == 'e' || key == 'E') {
			exit(0);
		}
	}
	if (estado == REGLAS)
	{
		if (key == 'M' || key == 'm') {
			estado = INICIO;
		}
	}
	Juego.Tecla(key);
}

void Mundo::dibuja()
{
	//si el juego esta en modo INICIO se imprime por pantalla un menu
	if (estado == INICIO) 
	{
	}
	//si el juego esta en modo "activo", es decir, en JUGVSMAQ o JUGVSJUG se dibuja en la pantalla el espacio
	else if (estado == JUGVSMAQ && victoria == NO || estado == JUGVSJUG && victoria == NO)
	{
	}
	//si el juego esta en REGLAS se facilitan por pantalla las reglas del juego
	else if (estado == REGLAS) 
	{
	}
	//si el juego esta en FINJ1 o FINJ2 significa que uno de los jugadores ha perdido, se imprime por pantalla y finaliza el juego
	else if (victoria == FINJ1 && estado == JUGVSJUG)
	{
	}
	else if (victoria == FINJ2 && estado == JUGVSJUG)
	{
	}
	else if (victoria == FINJ2 && estado == JUGVSMAQ)
	{
	}
	else if (victoria == FINJ1 && estado == JUGVSMAQ)
	{
	}
}

void Mundo::Raton(int button, int state, int x, int y)
{
	Juego.Raton(button, state, x, y);
}

void Mundo::RotarOjo()
{
	if (contador < 100 && (estado == JUGVSMAQ || estado == JUGVSJUG)) {
		Juego.RotarOjo();
		contador++;
	}
	else Juego.Para();
}

void Mundo::Mueve()
{
	if (estado == JUGVSMAQ || estado == JUGVSJUG)
	{
		if (Juego.GetContadorJ1() == 0)
		{
			victoria = FINJ2;
		}
		if (Juego.GetContadorJ2() == 0)
		{
			victoria = FINJ1;
		}
	}
}