#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"

enum ColorPieza {
	Indefinido,
	Negra,
	Blanca
};;// True = Negras , False = Blancas

class Pieza {

protected:
	bool primerMov;
	ColorPieza color;
public:
	Pieza();
	virtual ~Pieza() {};
	ColorRGB colorGraph;
	Vector2D posicion;

	int getPosicionX();
	int getPosicionY();
	void setPosicion(float _x, float _y);
	void setColor(unsigned char r, unsigned char v, unsigned char a);
	ColorPieza getColor() const;
	virtual bool movValido(int destX, int destY, ColorPieza c) = 0;
	virtual void Dibuja() = 0;
	virtual Vector2D* getTrayectoria(Vector2D origen, Vector2D destino);
	bool getPrimerMov() { return primerMov; }
	void setPrimerMov(bool pm);
};

