#include "stdafx.h"
#include "Geometry.hpp"

#define _USE_MATH_DEFINES
#include <math.h>

#include <iostream>

using namespace std;


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

/// <summary>
/// 
/// </summary>
/// <param name="centerPoint"></param>
/// <param name="radius"></param>
/// <param name="phi"></param>
/// <returns></returns>
Vector2f Geometry::GetCircleCoordinatesForPhi(const Vector2f& centerPoint, float radius, float phi)
{
	float x = centerPoint.x + radius * cosf(phi);
	float y = centerPoint.y + radius * sinf(phi);

	return Vector2f(x, y);
}

/// <summary>
/// 
/// </summary>
/// <param name="point1"></param>
/// <param name="point2"></param>
/// <returns></returns>
float Geometry::GetAngleBetweenPoints(const Vector2f & point1, const Vector2f & point2)
{
	float res = (atan2(point1.y, point1.x) - atan2(point2.y, point2.x)) * 180.f / M_PI;

	if (res <= 0)
	{
		res = 360 + res;
	}

	cout << point1.x << "," << point1.y << endl;
	cout << point2.x << "," << point2.y << endl;

	return res;
}

float Geometry::GetDegreesFromRadian(float radian)
{
	return radian * 180.f / M_PI;
}


