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

	/// <summary>
	/// Updates the animation.
	/// </summary>
	/// <param name="fpsFactor">The microseconds left since the last iteration.</param>
	void Update(long long fpsFactor);

	/// <summary>
	/// Starts the animation.
	/// </summary>
	void Start();

	/// <summary>
	/// Stops the animation.
	/// </summary>
	/// <param name="reset">Flag indicating wether the animation should be reseted.</param>
	void Stop(bool reset = true);

	/// <summary>
	/// Flag indicating wether the animation is running.
	/// </summary>
	/// <returns></returns>
	bool IsRunning();

private:

	bool _IsRunning = false;
	int _StepCount = 0;
	int _MovementX = 0;
	int _MovementY = 0;
	int _AlreadyShownFrames = 0;
	float _FrameDuration = 0.f;
	float _FrameWidth = 0.f;
	float _FrameHeigth = 0.f;
	float _durationSinceLastIteration = 0.f;
	shared_ptr<Sprite> _Sprite = nullptr;

};


