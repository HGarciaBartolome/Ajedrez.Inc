#pragma once

class Vector2D {
public:
	int x, y;
	Vector2D(int x, int y) { this->x = x; this->y = y; };
	Vector2D() :x(0), y(0) {};
	bool operator==(const Vector2D& v) {
		return (this->x == v.x && this->y == v.y);
	};
	virtual ~Vector2D(){};
};
