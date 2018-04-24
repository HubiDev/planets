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
double Physics::VerticalThrow(double v0, double t, double g)
{
	return v0 * t - (g / 2) * pow(t, 2);
}
