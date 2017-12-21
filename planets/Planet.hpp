#pragma once

#include "GameElementBase.hpp"

class Planet : public GameElementBase
{
public:
	Planet();
	~Planet();

	// Inherited via GameElementBase
	virtual void draw(RenderTarget& target, RenderStates states) const override;
	virtual void Update(float fpsFactor) override;

private:
	CircleShape _Shape;
};

