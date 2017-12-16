#pragma once
#include "GameElementBase.hpp"

class Player : public GameElementBase
{
public:
	Player();
	~Player();

	// Inherited via GameElementBase
	virtual void draw(RenderTarget & target, RenderStates states) const override;
	virtual void Update(float fpsFactor) override;

private:

	//-----------------------------------------------------------------------------
	RectangleShape _Shape;
	float currentRotation = 0.f;
};

