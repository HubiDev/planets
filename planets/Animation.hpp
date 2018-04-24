#pragma once
#include <memory>
#include <SFML\Graphics.hpp>

using namespace std;
using namespace sf;

class Animation
{
public:

	/// <summary>
	/// Constructor
	/// </summary>
	Animation(int stepCount, float frameDuration, shared_ptr<Sprite>);

	/// <summary>
	/// Destructor
	/// </summary>
	~Animation();


	void Update(long long fpsFactor);
	void SetAnimationStepCount(int stepCount);
	void SetAnimationMovement(int movementX, int movementY);
	void SetFrameDuration(float duration);

private:

	int _StepCount = 0;
	int _MovementX = 0;
	int _MovementY = 0;
	float _FrameDuration = 0.f;
	shared_ptr<Sprite> _PtrSprite = nullptr;

};


