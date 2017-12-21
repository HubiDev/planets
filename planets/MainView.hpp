#pragma once

#include "ViewBase.hpp"
#include "Player.hpp"
#include "Planet.hpp"

class MainView : public ViewBase
{
public:
	MainView();
	~MainView();

	// Inherited via ViewBase
	virtual void Update(float fpsFactor) override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:

	Player _Player;
	Planet _Planet;

};

