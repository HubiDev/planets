#pragma once
#include "GameElementBase.hpp"
#include <memory>

using namespace std;

class Player : public GameElementBase
{
public:
	Player();
	~Player();

	// Inherited via GameElementBase
	virtual void draw(RenderTarget & target, RenderStates states) const override;
	virtual void Update(float fpsFactor) override;

private:

	void HandleJump(float fpsFactor);

	//-----------------------------------------------------------------------------
	//RectangleShape _Shape;
	Texture _Texture;
	//Sprite _Sprite;
	Sprite _PtrSprite;
	float _CurrentRotation = 0.f;
	bool _IsJumping = false;
	float _TimeSinceJumpStart = 0.f;
	float _TmpHeight = 0.f;
};

