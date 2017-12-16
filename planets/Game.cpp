#include "stdafx.h"
#include "Game.hpp"
#include "MainView.hpp"

/// <summary>
/// Constructor
/// </summary>
Game::Game()
{
	//Init settings
	_WindowSettings.antialiasingLevel = 8;
	_WindowSettings.majorVersion = 3;
	_WindowSettings.minorVersion = 0;
	_Window.setFramerateLimit(60);

	_ViewsToDisplay.push_back(new MainView());
}


/// <summary>
/// Destructor
/// </summary>
Game::~Game()
{
	for (auto currentView : _ViewsToDisplay)
	{
		delete currentView;
	}
}

void Game::Start()
{
	_Window.create(VideoMode(1280, 720), "Planets", Style::Close, _WindowSettings);
	_FpsTimer.restart(); //TODO

	while (_Window.isOpen())
	{
		//Handle events
		Event event;
		while (_Window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				_Window.close();
			}
		}

		auto fpsFactor = CalculateFpsFactor(_FpsTimer.getElapsedTime().asMicroseconds());
		_FpsTimer.restart();

		_Window.clear(Color::White);

		//Update and draw each view
		for (auto currentView : _ViewsToDisplay)
		{
			currentView->Update(fpsFactor);
			_Window.draw(*currentView);
		}	

		_Window.display();
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="timeSinceLastLoop"></param>
/// <returns></returns>
float Game::CalculateFpsFactor(long long timeSinceLastLoop)
{
	float res = 10000.f / (float)timeSinceLastLoop;
	return res;
}