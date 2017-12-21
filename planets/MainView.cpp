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
	_Planet.Update(fpsFactor);
}

void MainView::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(_Player);
	target.draw(_Planet);
}
