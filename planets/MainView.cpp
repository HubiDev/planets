#include "MainView.hpp"


MainView::MainView()
{
}


MainView::~MainView()
{
}

void MainView::Update(float fpsFactor)
{
	_Player.Update(fpsFactor);
}

void MainView::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(_Player);
}
