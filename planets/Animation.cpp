#include "Animation.hpp"


Animation::Animation(int stepCount, float frameDuration, shared_ptr<Sprite> sprite)
	: _StepCount(stepCount),
	_FrameDuration(frameDuration)
{
	_PtrSprite = sprite;

}

/// <summary>
/// Destructor
/// </summary>
Animation::~Animation()
{
}

void Animation::Update(long long fpsFactor)
{
}

/// <summary>
/// 
/// </summary>
/// <param name="stepCount"></param>
void Animation::SetAnimationStepCount(int stepCount)
{
}

/// <summary>
/// 
/// </summary>
/// <param name="movementX"></param>
/// <param name="movementY"></param>
void Animation::SetAnimationMovement(int movementX, int movementY)
{
}

/// <summary>
/// 
/// </summary>
/// <param name="duration"></param>
void Animation::SetFrameDuration(float duration)
{
}
