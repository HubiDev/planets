#include"stdafx.h"
#include "ViewBase.hpp"

//--------------------------------------------------------
//--------------------------------------------------------
ViewBase::ViewBase()
{

}

//--------------------------------------------------------
//--------------------------------------------------------
ViewBase::~ViewBase()
{

}

/// <summary>
/// 
/// </summary>
/// <param name="target"></param>
/// <param name="states"></param>
void ViewBase::draw(RenderTarget& target, RenderStates states) const
{
	CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	target.draw(shape);
}