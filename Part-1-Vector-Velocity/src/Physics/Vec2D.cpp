#include "Vec2D.h"

Vec2D Vec2D::operator+(const Vec2D v) const {
	
	Vec2D result = Vec2D(x + v.x, y + v.y);
	return result;
};

Vec2D Vec2D::operator-(const Vec2D v) const {

	Vec2D result = Vec2D(x - v.x, y - v.y);
	return result;
}