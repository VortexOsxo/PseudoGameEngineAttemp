#pragma once

#include <SFML/Graphics.hpp>

class RenderingComponent
{
public:
    RenderingComponent();
    virtual ~RenderingComponent();

    virtual void Render(sf::RenderWindow* window) =0;

protected:
    const class RenderingSystem* renderingSystem = nullptr;
};