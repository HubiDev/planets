#include "stdafx.h"
#include "Geometry.hpp"
#include <math.h>


/// <summary>
/// 
/// </summary>
Geometry::Geometry()
{
}

/// <summary>
/// 
/// </summary>
Geometry::~Geometry()
{
}

Vector2f Geometry::GetCircleCoordinatesForPhi(const Vector2f& centerPoint, float radius, float phi)
{
	float x = centerPoint.x + radius * cosf(phi);
	float y = centerPoint.y + radius * sinf(phi);

	return Vector2f(x, y );
}
