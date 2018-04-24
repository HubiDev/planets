#include "Planet.hpp"


/// <summary>
/// 
/// </summary>
Planet::Planet()
{
	_Shape.setRadius(100.f);
	_Shape.setFillColor(Color::Blue);
	_Shape.setOrigin(Vector2f(100.f, 100.f));
	_Shape.setPosition(640, 360);
}


/// <summary>
/// 
/// </summary>
Planet::~Planet()
{
}

void Planet::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(_Shape);
}

void Planet::Update(long long fpsFactor)
{
}
