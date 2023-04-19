#pragma once
#include "../src/Physics/Vec2D.h"

struct Entity {
	Vec2D position;
	Vec2D velocity;
	// Vec2D acceleration;

	Entity(int x, int y);
};