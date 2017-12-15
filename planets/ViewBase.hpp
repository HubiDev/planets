#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class ViewBase : public Drawable
{
    public:
    ViewBase();
    ~ViewBase();

    virtual void draw(sf::RenderTarget& target,sf::RenderStates states)const;

	virtual void Update(float fpsFactor) = 0;

    private:
    
	protected:


};