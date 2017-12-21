#include "stdafx.h"
#include "Physics.hpp"

#define _USE_MATH_DEFINES
#include <math.h>

Physics::Physics()
{
}


Physics::~Physics()
{
}

/// <summary>
/// 
/// </summary>
/// <param name="v0"></param>
/// <param name="t"></param>
/// <param name="g"></param>
/// <returns></returns>
float Physics::VerticalThrow(float v0, float t, float g)
{
	return v0 * t - (g / 2) * powf(t, 2.f);
}
