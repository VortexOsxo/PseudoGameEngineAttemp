#pragma once

#include <SFML/Graphics.hpp>

class Entity;

class Obstacle
{
public:
    Obstacle() = default;
    virtual ~Obstacle() = default;

    virtual bool Collide(Entity* entity) const =0;

    virtual sf::Shape* GetShape() =0;
};