#include "Animation.hpp"


Animation::Animation(int stepCount, float frameDuration, shared_ptr<Sprite> sprite)
	: _StepCount(stepCount),
	_FrameDuration(frameDuration)
{
	_Sprite = sprite;
	_FrameWidth = static_cast<float>((*sprite).getTexture()->getSize().x / stepCount);
	_FrameHeigth = (*sprite).getTexture()->getSize().x;
}

/// <summary>
/// Destructor
/// </summary>
Animation::~Animation()
{
}

void Animation::Update(long long fpsFactor)
{
	if (_IsRunning)
	{

		//Calculate ms that have been elapsed
		auto ms = fpsFactor / 1000.f;
		_durationSinceLastIteration += ms;

		if (_durationSinceLastIteration > _FrameDuration)
		{
			//Move to next frame
			++_AlreadyShownFrames;
			auto oldTextureRect = (*_Sprite).getTextureRect();

			if (_AlreadyShownFrames == _StepCount)
			{
				_AlreadyShownFrames = 0;
				(*_Sprite).setTextureRect(IntRect(0, 0, static_cast<int>(_FrameWidth), static_cast<int>(_FrameHeigth)));
			}
			else
			{
				(*_Sprite).setTextureRect(IntRect(oldTextureRect.left + static_cast<int>(_FrameWidth),
					oldTextureRect.top,
					oldTextureRect.width,
					oldTextureRect.height));
			}

			_durationSinceLastIteration = 0.f; //Reset duration counter		
		}
	}
}

/// <summary>
/// Starts the animation.
/// </summary>
void Animation::Start()
{
	_IsRunning = true;
}

/// <summary>
/// Stops the animation.
/// </summary>
/// <param name="reset">Flag indicating wether the animation should be reseted.</param>
void Animation::Stop(bool reset)
{
	_IsRunning = false;

	if (reset)
	{
		(*_Sprite).setTextureRect(IntRect(0, 0, static_cast<int>(_FrameWidth), static_cast<int>(_FrameHeigth)));
	}
}

/// <summary>
/// Flag indicating wether the animation is running.
/// </summary>
/// <returns></returns>
bool Animation::IsRunning()
{
	return _IsRunning;
}
