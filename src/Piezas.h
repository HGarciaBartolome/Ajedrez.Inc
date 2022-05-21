#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
#include "Trayectoria.h"

//enum para los colores de las piezas
enum ColorPieza {
	Indefinido,
	Negra,
	Blanca
};;// True = Negras , False = Blancas

//CLASE PADRE DE TODAS LAS FIGURAS (clase abstracta con metodos virtuales puros)
class Pieza {
	//Atributos con servicio protected para que esten protegidos fuera pero accesibles para los hijos
protected:
	bool primerMov;
	ColorPieza color;

	//Metodos publicos
public:
	//Contructor y destructor
	Pieza();
	virtual ~Pieza() {};

	//Instancia del vector de posicion
	Vector2D posicion;

	//getters
	int getPosicionX();
	int getPosicionY();
	Vector2D getPosicion();
	ColorPieza getColor() const;
	bool getPrimerMov() { return primerMov; }

	//setters
	void setPosicion(Vector2D v);
	void setPrimerMov(bool pm);

	//metodos virtuales puros
	virtual Trayectoria getTrayectoria(Vector2D origen, Vector2D destino) = 0;
	virtual char tipoPieza() = 0;
	virtual bool movValido(int destX, int destY, ColorPieza c) = 0;
	virtual void Dibuja();
	virtual void Dibuja2();
	virtual void Dibuja3();
};

