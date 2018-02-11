#include "Player.hpp"
#include <string>
#include "Geometry.hpp"
#include "Game.hpp"
#include "Physics.hpp"

#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

using namespace std;

/// <summary>
/// Constructor
/// </summary>
Player::Player()
{
	//_Shape.setSize(Vector2f(50, 85));
	//_Shape.setFillColor(Color::Black);
	//_Shape.setOrigin(Vector2f(25, 42.5));
	//_Shape.setPosition(640, 360);

	_Texture.loadFromFile("Textures\\astronaut_02.png");
	_Texture.setSmooth(true);
	_Sprite.setTexture(_Texture);
	_Sprite.setOrigin(_Texture.getSize().x / 2, _Texture.getSize().y / 2);
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
	//target.draw(_Shape);
	target.draw(_Sprite);
}

/// <summary>
/// 
/// </summary>
/// <param name="fpsFactor"></param>
void Player::Update(float fpsFactor)
{
	if (!_IsJumping)
	{
		if (Keyboard::isKeyPressed(Keyboard::Key::Left))
		{
			_CurrentRotation -= 1 / fpsFactor / 50;

			if (_CurrentRotation <= 0)
			{
				_CurrentRotation = M_PI * 2;
			}

			_Sprite.setPosition(Geometry::GetCircleCoordinatesForPhi(Vector2f(640, 360), 170.f, _CurrentRotation));
			_Sprite.setRotation(Geometry::GetDegreesFromRadian(_CurrentRotation) + 90.f);
		}

		if (Keyboard::isKeyPressed(Keyboard::Key::Right))
		{

			_CurrentRotation += 1 / fpsFactor / 50;

			if (_CurrentRotation >= (M_PI * 2))
			{
				_CurrentRotation = 0;
			}

			_Sprite.setPosition(Geometry::GetCircleCoordinatesForPhi(Vector2f(640, 360), 170.f, _CurrentRotation));
			_Sprite.setRotation(Geometry::GetDegreesFromRadian(_CurrentRotation) + 90.f);
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Space))
	{
		_IsJumping = true;
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
	auto t = Game::CalculateElapsedTimeFromFpsFactor(fpsFactor);
	float x = t / 10000000000.f;

	_TimeSinceJumpStart += x;

	auto height = Physics::VerticalThrow(1.1, _TimeSinceJumpStart, 9.81);

	_TmpHeight += height;

	if (_TmpHeight > 0)
	{
		auto pos = Geometry::CalculatePointFromAngle(_CurrentRotation, height);
		_Sprite.move(pos);
	}
	else
	{
		_IsJumping = false;
		_TimeSinceJumpStart = 0.f;
		_TmpHeight = 0.f;
	}
}