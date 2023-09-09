#pragma once

#include <SFML/Graphics.hpp>
#include <game/map/rectangle.h>

class Map
{
public:
    Map(float rayon);
    ~Map();

    float GetRayon() const;
    bool IsInside(class Entity* entity) const;
    bool IsInside(const class Vector2D& position) const;

    sf::Shape* GetDrawableShape();

private:
    RectangleObstacle obstacle = RectangleObstacle(Vector2D(150.f, 150.f), Vector2D(200.f,200.f));
    float rayon = 0;

    class MapRenderingComponent* renderingComponent = nullptr;
};