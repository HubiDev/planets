#pragma once
#include <memory>

#include "GameElementBase.hpp"
#include "Animation.hpp"

using namespace std;

class Player : public GameElementBase
{
public:
	Player();
	~Player();

	// Inherited via GameElementBase
	virtual void draw(RenderTarget & target, RenderStates states) const override;
	virtual void Update(long long fpsFactor) override;

private:

#pragma region Methods

	void HandleJump(long long fpsFactor);

#pragma endregion	

#pragma region Fields

	Texture _Texture;
	shared_ptr<Sprite> _Sprite = nullptr;
	double _CurrentRotation = 0.f;
	bool _IsJumping = false;
	double _TimeSinceJumpStart = 0;
	double _TmpHeight = 0.f;
	Vector2f _PosBeforeJump;
	unique_ptr<Animation> _WalkingAnimation = nullptr;

#pragma endregion

#pragma region Constants

	const float ROT_SPEED = 0.0016f;

#pragma endregion

};

