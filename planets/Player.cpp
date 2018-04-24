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
	_Sprite = make_shared<Sprite>();

	_Texture.loadFromFile("Textures\\astronaut_formatted.png");	
	_Texture.setSmooth(true);	
	_Sprite->setTexture(_Texture);
	_Sprite->setTextureRect(IntRect(0, 0, 800, _Texture.getSize().y));
	_Sprite->setOrigin(_Sprite->getTextureRect().width / 2.f, _Sprite->getTextureRect().height / 2.f); //Set origin to center of the sprite		
	_Sprite->setScale(0.1f, 0.1f);
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
	target.draw(*_Sprite);
}

/// <summary>
/// 
/// </summary>
/// <param name="fpsFactor"></param>
void Player::Update(long long fpsFactor)
{
	double ms = fpsFactor / 1000.0; //Convert microseconds into milliseconds

	if (!_IsJumping)
	{
		double degreesMoved = ROT_SPEED * ms; //Calculate how many degrees the player should have moved in the mean time

		if (Keyboard::isKeyPressed(Keyboard::Key::Left))
		{
			_CurrentRotation -= degreesMoved;

			if (_CurrentRotation <= 0)
			{	
				double rest = 0 - _CurrentRotation;
				_CurrentRotation = M_PI * 2.f - rest;
			}

			_Sprite->setPosition(Geometry::GetCircleCoordinatesForPhi(Vector2f(640, 360), 170.f, _CurrentRotation));
			_Sprite->setRotation(Geometry::GetDegreesFromRadian(_CurrentRotation) + 90.f);
		}

		if (Keyboard::isKeyPressed(Keyboard::Key::Right))
		{

			_CurrentRotation += degreesMoved;

			if (_CurrentRotation >= (M_PI * 2))
			{
				double rest = M_PI * 2 - _CurrentRotation;
				_CurrentRotation = rest;
			}

			_Sprite->setPosition(Geometry::GetCircleCoordinatesForPhi(Vector2f(640, 360), 170.f, _CurrentRotation));
			_Sprite->setRotation(Geometry::GetDegreesFromRadian(_CurrentRotation) + 90.f);
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Space) && !_IsJumping)
	{
		_IsJumping = true;
		_PosBeforeJump = _Sprite->getPosition();
	}

	if (_IsJumping)
	{
		HandleJump(fpsFactor);
	}

}

/// <summary>
/// Moves the player during a jump.
/// </summary>
/// <param name="fpsFactor">The time elapsed since the last iteration.</param>
void Player::HandleJump(long long fpsFactor)
{
	_TimeSinceJumpStart += fpsFactor / 1'000'000.0;
	auto height = Physics::VerticalThrow(50, _TimeSinceJumpStart, 9.81);

	if (height > 0)
	{
		auto pos = Geometry::CalculatePointFromAngle(static_cast<float>(_CurrentRotation), static_cast<float>(height));		
		_Sprite->setPosition(Vector2f(_PosBeforeJump.x + pos.x, _PosBeforeJump.y + pos.y));
	}
	else
	{		
		_IsJumping = false;
		_TimeSinceJumpStart = 0;
		_TmpHeight = 0.f;
	}
}