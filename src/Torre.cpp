
#include "Torre.h"
#include "ETSIDI.h"
#include "freeglut.h"
#include "Piezas.h"



Torre::Torre(bool _color, float _x, float _y)
{
	color = _color;
	posicion.x = _x;
	posicion.y = _y;


	
}

void Torre::Dibuja()
{
		ficha.draw();

}

void Torre::mueve(Vector2D)
{
}
