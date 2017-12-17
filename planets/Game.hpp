#pragma once

#include "SFML\Graphics.hpp"
#include <list>

#include "ViewBase.hpp"

using namespace sf;
using namespace std;

class Game
{
public:
	Game();
	~Game();

	void Start();

private:

	//Methods
	float CalculateFpsFactor(long long timeSinceLastLoop);

	//Fields
	RenderWindow _Window;
	ContextSettings _WindowSettings;
	Clock _FpsTimer;
	int _Fps = 0;
	Clock _FpsCounter;
	list<ViewBase*> _ViewsToDisplay;

};

