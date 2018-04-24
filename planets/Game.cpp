#include "Game.hpp"
#include "MainView.hpp"
#include "Geometry.hpp"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <chrono>
#include <thread>

using namespace chrono;

/// <summary>
/// Constructor
/// </summary>
Game::Game()
{
	//Init settings
	_WindowSettings.antialiasingLevel = 8;
	_WindowSettings.majorVersion = 3;
	_WindowSettings.minorVersion = 0;	

	_ViewsToDisplay.push_back(unique_ptr<ViewBase>(new MainView()));
}


/// <summary>
/// Destructor
/// </summary>
Game::~Game()
{
}

/// <summary>
/// 
/// </summary>
void Game::Start()
{
	_Window.create(VideoMode(1280, 720), "Planets", Style::Close, _WindowSettings);	
	_FpsCounter.restart();
	_FpsTimer.restart();

	time_point<steady_clock> lastTimePoint = steady_clock::now();
	long long elapsed = 0;

	while (_Window.isOpen())
	{
		//this_thread::sleep_for(2ms);//Frame limiter

		//Handle events
		Event event;
		while (_Window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				_Window.close();
			}
		}		

		_Window.clear(Color::Black);

		//Update and draw each view
		for (const auto& currentView : _ViewsToDisplay)
		{
			currentView->Update(elapsed);
			_Window.draw(*currentView);
		}

		_Window.display();		

		if (_FpsCounter.getElapsedTime().asSeconds() >= 1.f)
		{
			cout << _Fps << endl;
			_Fps = 0;
			_FpsCounter.restart();
		}
		else
		{ 
			++_Fps;
		}

		auto now = steady_clock::now();		
		elapsed = duration_cast<chrono::microseconds>(now - lastTimePoint).count();
		lastTimePoint = now;
	}
}