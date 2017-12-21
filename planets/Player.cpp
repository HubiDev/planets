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
	_Shape.setFillColor(Color::Black);
	_Shape.setOrigin(Vector2f(25, 42.5));
	_Shape.setPosition(640, 360);
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
		_CurrentRotation -= 1 / fpsFactor / 50;	

		if (_CurrentRotation <= 0)
		{
			_CurrentRotation = M_PI * 2;
		}

		_Shape.setPosition(Geometry::GetCircleCoordinatesForPhi(Vector2f(640, 360), 100.f, _CurrentRotation));
		_Shape.setRotation(Geometry::GetDegreesFromRadian(_CurrentRotation) + 90.f);
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Right))
	{

		_CurrentRotation += 1 / fpsFactor / 50;

		if (_CurrentRotation >= (M_PI * 2))
		{
			_CurrentRotation = 0;
		}

		_Shape.setPosition(Geometry::GetCircleCoordinatesForPhi(Vector2f(640, 360), 100.f, _CurrentRotation));
		_Shape.setRotation(Geometry::GetDegreesFromRadian(_CurrentRotation) + 90.f);
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Space))
	{
		_IsJumping = true;

		if (_JumpStartPos == nullptr)
		{
			_JumpStartPos = &(_Shape.getPosition());
		}
	}

	if (_IsJumping)
	{
		HandleJump(fpsFactor);
	}

}

/// <summary>
/// 
/// </summary>
/// <param name="fpsFactor"></param>
void Player::HandleJump(float fpsFactor)
{
	_TimeSinceJumpStart += fpsFactor;
	cout << _TimeSinceJumpStart << endl;
}