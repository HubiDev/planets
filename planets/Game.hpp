#pragma once

#include "SFML\Graphics.hpp"
#include <vector>
#include <memory>
#include "ViewBase.hpp"

using namespace sf;
using namespace std;

class Game
{
public:
	Game();
	~Game();

	void Start();
	static float CalculateFpsFactor(long long timeSinceLastLoop);
	static long long CalculateElapsedTimeFromFpsFactor(float fpsFactor);

private:

	//Methods
	

	//Fields
	RenderWindow _Window;
	ContextSettings _WindowSettings;
	Clock _FpsTimer;
	int _Fps = 0;
	Clock _FpsCounter;
	vector<unique_ptr<ViewBase>> _ViewsToDisplay;

};

