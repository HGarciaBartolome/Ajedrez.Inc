#pragma once
#include <vector>
#include "Vector2D.h"

class Trayectoria {
private:
	std::vector<Vector2D> v;
public:

	Trayectoria() {};
	void push_back(const Vector2D& punto);
	Vector2D operator[](unsigned int index);
	unsigned int size() const;
};
