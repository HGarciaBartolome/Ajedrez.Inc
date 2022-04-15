#include <ETSIDI.h>
#include <stdio.h>     
#include "glut.h"
#include "Mundo.h"

Mundo mundo;

void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla
void onMouse(int button, int state, int x, int y);

int main(int argc, char* argv[])
{



}

void OnDraw(void) {

	mundo.dibuja();

}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	mundo.tecla(key);

}

void OnTimer(int value)
{

	mundo.RotarOjo();
	mundo.Mueve();

}

void onMouse(int button, int state, int x, int y)
{
	mundo.Raton(button, state, x, y);
}
