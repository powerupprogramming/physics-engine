#pragma once

struct Vec2D {
	int x;
	int y;

	Vec2D(int x, int y) : x(x), y(y) {};
	Vec2D() { x = 0; y = 0; }

	Vec2D operator+(const Vec2D v) const;
	Vec2D operator-(const Vec2D v) const;

};