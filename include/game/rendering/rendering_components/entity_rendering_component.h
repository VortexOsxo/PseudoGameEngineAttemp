#pragma once

#include <game/rendering/rendering_component.h>

class Entity;

class EntityRenderingComponent : public RenderingComponent
{
public:
    EntityRenderingComponent(Entity* entity);
    virtual ~EntityRenderingComponent() = default;

    virtual void Render(sf::RenderWindow* window) override;

private:
    Entity* entity;
    sf::CircleShape circle = sf::CircleShape(1.f);
};