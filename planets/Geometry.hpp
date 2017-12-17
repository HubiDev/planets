#pragma once

#include "SFML\Graphics.hpp"

using namespace sf;

class Geometry
{
public:
	Geometry();
	~Geometry();

	static Vector2f GetCircleCoordinatesForPhi(const Vector2f& centerPoint, float radius, float phi);
	static float GetAngleBetweenPoints(const Vector2f& point1, const Vector2f& point2);
	static float GetDegreesFromRadian(float radian);
};

