#include "Trayectoria.h"

void Trayectoria::push_back(const Vector2D& punto)
{
	v.push_back(punto);
}

Vector2D Trayectoria::operator[](unsigned int index)
{
	return v[index];
}

unsigned int Trayectoria::size() const
{
	return v.size();
}