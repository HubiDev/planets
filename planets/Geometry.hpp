#pragma once

#include "SFML\Graphics.hpp"

using namespace sf;

class Geometry
{
public:
	Geometry();
	~Geometry();

	static Vector2f GetCircleCoordinatesForPhi(const Vector2f& centerPoint, float radius, float phi);
};

