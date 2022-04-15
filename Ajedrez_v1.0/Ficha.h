#pragma once
#include "math.h"
//#include "glut.h"
class Ficha
{
protected:
	float x;
	float y;
	bool marca;
	bool next;
	bool ocupada;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	int tipo;//Se define el tipo de la pieza 0=peon , 1=alfil , 2=torre, 3=reina , 4=rey

public:
	Ficha();
	Ficha(int _x, int _y,bool color);//Constructor de peones
	Ficha(int _x, int _y, int _tipo,bool color);
	~Ficha() {}
	void Dibuja();

	//set
	void setPosicion(float ix, float iy);
	void SetColor(unsigned char r, unsigned char v, unsigned char a);
	void SetActiva();
	void SetDesactiva();
	void SetOcupada(bool o) { ocupada = o; }
	void SetMarca(bool o) { marca = o; }
	void SetNext(bool o) { next = o; }

	//get
	bool GetOcupada() { return ocupada; };
	bool GetMarca() { return marca; };
	bool GetNext() { return next; };
	int GetPosicionX();

};

