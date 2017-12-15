#include "Player.hpp"
#include <string>

using namespace std;

/// <summary>
/// Constructor
/// </summary>
Player::Player()
{
	_Shape.setSize(Vector2f(100, 175));
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
		_Shape.move(Vector2f(-1 / fpsFactor, 0));
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Right))
	{
		_Shape.move(Vector2f(1 / fpsFactor, 0));
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
