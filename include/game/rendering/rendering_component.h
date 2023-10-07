#pragma once

#include <SFML/Graphics.hpp>
#include <Utils/Vector2D.h>

class RenderingComponent
{
public:
    RenderingComponent();
    virtual ~RenderingComponent();

    virtual void Render(sf::RenderWindow* window) =0;

protected:
    const Vector2D& GetRelativePosition();

private:
    const class RenderingSystem* renderingSystem = nullptr;
};