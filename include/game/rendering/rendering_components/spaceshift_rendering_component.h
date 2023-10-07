#pragma once

#include <game/rendering/rendering_component.h>
#include <vector>
#include <Utils/Vector2D.h>

#include <game/rendering/sprite.h>

class Entity;

class SpaceshiftRenderingComponent : public RenderingComponent
{
public:
    SpaceshiftRenderingComponent(Entity* entity, std::string shipPath, std::string enginePath);
    virtual ~SpaceshiftRenderingComponent() = default;

    virtual void Render(sf::RenderWindow* window) override;

protected:
    void RenderSpaceshift(sf::RenderWindow* window);
    void OrientSprite();

protected:
    Entity* entity = nullptr;
    Vector2D size;

private:
    Sprite spriteShip;

    Sprite spriteEngine;
};