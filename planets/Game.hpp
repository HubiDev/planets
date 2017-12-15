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
	RenderWindow _Window;
	ContextSettings _WindowSettings;
	Clock _FpsTimer;
	list<ViewBase*> _ViewsToDisplay;

};

