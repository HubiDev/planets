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

		auto timeSinceLastLoop = _FpsTimer.getElapsedTime().asMicroseconds();
		_FpsTimer.restart();

		_Window.clear(Color::White);

		//Update each view
		for (auto currentView : _ViewsToDisplay)
		{
			currentView->Update(timeSinceLastLoop);
			_Window.draw(*currentView);
		}	

		_Window.display();
	}
}
