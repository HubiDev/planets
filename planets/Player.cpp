#include "Player.hpp"
#include <string>
#include "Geometry.hpp"

#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

using namespace std;

/// <summary>
/// Constructor
/// </summary>
Player::Player()
{
	_Shape.setSize(Vector2f(50, 85));
	_Shape.setFillColor(Color::Blue);
	_Shape.setOrigin(Vector2f(0, 175));
	_Shape.setPosition(200, 200);

}

/// <summary>
/// Destructor
/// </summary>
Player::~Player()
{
}

/// <summary>
/// 
/// </summary>
/// <param name="target"></param>
/// <param name="states"></param>
void Player::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(_Shape);	
}

/// <summary>
/// 
/// </summary>
/// <param name="fpsFactor"></param>
void Player::Update(float fpsFactor)
{	

	if (Keyboard::isKeyPressed(Keyboard::Key::Left))
	{
		currentRotation -= 1 / fpsFactor / 50;	

		if (currentRotation <= 0)
		{
			currentRotation = M_PI * 2;
		}

		_Shape.setPosition(Geometry::GetCircleCoordinatesForPhi(Vector2f(640, 360), 100.f, currentRotation));
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Right))
	{

		currentRotation += 1 / fpsFactor / 50;

		if (currentRotation >= (M_PI * 2))
		{
			currentRotation = 0;
		}

		_Shape.setPosition(Geometry::GetCircleCoordinatesForPhi(Vector2f(640, 360), 100.f, currentRotation));
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Up))
	{
		_Shape.move(Vector2f(0, -1 / fpsFactor));
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Down))
	{
		_Shape.move(Vector2f(0, 1 / fpsFactor));
	}

}
