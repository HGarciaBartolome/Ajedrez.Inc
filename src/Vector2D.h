#pragma once

class Vector2D {
public:
	//coordenadas del vector
	int x, y;

	//constructor por defecto
	Vector2D(int x, int y) { this->x = x; this->y = y; };

	//constructor con lista de inicializacion
	Vector2D() :x(0), y(0) {};

	//destructor
	virtual ~Vector2D() {};

	//sobrecarga del operador == que usaremos para ver las trayectorias de las piezas
	bool operator==(const Vector2D& v) {
		return (this->x == v.x && this->y == v.y);
	};
};
