#pragma once

#include "ViewBase.hpp"

class MainView : public  ViewBase
{
public:
	MainView();
	~MainView();

	// Inherited via ViewBase
	virtual void Update(float fpsFactor) override;
};

