#pragma once
class Animation
{
public:

	/// <summary>
	/// Constructor
	/// </summary>
	Animation(int stepCount, float frameDuration);

	/// <summary>
	/// Destructor
	/// </summary>
	~Animation();


	void Update(float fpsFactor);
	void SetAnimationStepCount(int stepCount);
	void SetAnimationMovement(int movementX, int movementY);
	void SetFrameDuration(float duration);

private:

	int _StepCount;
	int _MovementX;
	int _MovementY;
	float _FrameDuration;	
};


