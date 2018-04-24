#pragma once

#include <SFML\Graphics.hpp>

using namespace sf;

class GameElementBase : public Drawable
{
public:
	GameElementBase();
	~GameElementBase();

	// Inherited via Drawable
	virtual void draw(RenderTarget& target, RenderStates states) const = 0;
	virtual void Update(long long fpsFactor) = 0;	

protected:
};

